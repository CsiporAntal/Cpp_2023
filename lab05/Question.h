//
// Created by Toni on 2023. 11. 08..
//

#ifndef CPP_2022_QUESTION_H
#define CPP_2022_QUESTION_H


#include <string>
#include <vector>
#include "Answer.h"

using namespace std;
class Question {
private:
    const string text;
    vector<Answer> answers;

public:
    Question(const string &text, const vector<Answer> &answers);

    explicit Question(const string &text);

    const string &getText() const;

    vector<Answer> &getAnswers();
};

#endif //CPP_2022_QUESTION_H
