//
// Created by Toni on 2023. 11. 22..
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H


#include <iostream>
#include <string>
#include <vector>

struct Question {
    std::string text;
    std::string correctAnswer;
};

class Quiz {
private:
    std::string name;
    std::vector<Question> questions;

public:
    Quiz(const std::string& name);
    const std::string& getName() const;
    const std::vector<Question>& getQuestions() const;
};



#endif //CPP_2022_QUIZ_H
