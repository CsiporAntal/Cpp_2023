#include <iostream>
#include "SimpleTextGenerator.h"
#include "TextGenerator.h"

int main() {
    SimpleTextGenerator generator;

    string text = "Now is not the time for sleep, now is the time for party!";
    generator.trainFromText(text);
    generator.printData();
    for (int i = 0; i < 3; ++i) {
        cout << "Generated text: " << generator.generate("now is", 6) << endl;
    }
    return 0;
}