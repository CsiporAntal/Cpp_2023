//
// Created by Toni on 2023. 11. 08..
//

#ifndef CPP_2022_QUIZGAME_H
#define CPP_2022_QUIZGAME_H


#include "Quiz.h"

class QuizGame {
private:
    int rightAnswersnr;
    Quiz quiz;

public:
    explicit QuizGame(string quizName,string filename);
    void startGame();
};


#endif //CPP_2022_QUIZGAME_H
