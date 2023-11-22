//
// Created by Toni on 2023. 11. 22..
//

#include "Quiz.h"

Quiz::Quiz(const std::string& name) : name(name) {
    // You can add your questions here or load them from a file.
    // For simplicity, I'll add a sample question.
    Question q1;
    q1.text = "What is the capital of C++?";
    q1.correctAnswer = "Object-oriented";

    // Add the question to the vector of questions.
    questions.push_back(q1);
}

const std::string& Quiz::getName() const {
    return name;
}

const std::vector<Question>& Quiz::getQuestions() const {
    return questions;
}
