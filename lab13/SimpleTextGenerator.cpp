//
// Created by Toni on 2023. 12. 20..
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText) {
    stringstream ss(trainingText);
    string word, prevWord;

    while (ss >> word) {
        data[prevWord].push_back(word);
        prevWord = word;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            trainFromText(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    stringstream result;
    string prefix = startWords;
    result << prefix;

    for (int i = 0; i < numWords - 1; ++i) {
        if (data.find(prefix) != data.end() && !data[prefix].empty()) {
            // Randomly select a postfix
            int randomIndex = rand() % data[prefix].size();
            string postfix = data[prefix][randomIndex];

            // Append the postfix to the result
            result << " " << postfix;

            // Update the prefix for the next iteration
            prefix = postfix;
        } else {
            // If no postfix is available, stop the generation
            break;
        }
    }

    return result.str();
}

void SimpleTextGenerator::printData() const {
    for (const auto& entry : data) {
        cout << entry.first << " {";
        for (const auto& postfix : entry.second) {
            cout << postfix << ", ";
        }
        cout << "}" << endl;
    }
}
