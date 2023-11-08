//
// Created by Toni on 2023. 11. 08..
//

#ifndef CPP_2022_ANSWER_H
#define CPP_2022_ANSWER_H

#include <string>

using namespace std;

class Answer {
private:
    const string text;
    bool correct;


public:
    explicit Answer(const string &text);

    const string &getText() const;

    bool isCorrect() const;

    void setCorrect(bool correct);
};

#endif //CPP_2022_ANSWER_H
