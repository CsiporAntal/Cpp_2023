//
// Created by Toni on 2023. 11. 08..
//

#include "Answer.h"

Answer::Answer(const string &text) : text(text,correct = false) {}

const string &Answer::getText() const {
    return text;
}

bool Answer::isCorrect() const {
    return correct;
}

void Answer::setCorrect(bool correct) {
    Answer::correct = correct;
}
