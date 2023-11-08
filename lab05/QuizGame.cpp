//
// Created by Toni on 2023. 11. 08..
//

#include <random>
#include <iostream>
#include "QuizGame.h"

QuizGame::QuizGame(string quizName, string filename): quiz(quizName) {
    quiz.readFromFile(filename);
}

void QuizGame::startGame() {
    random_device rd;
    mt19937 gen(rd());
    int M = quiz.getQuestions().size();
    uniform_int_distribution<int> dist(0,M);
    vector<int> order;
    for (int i = 0; i < M; ++i) {
        order.push_back((1));
    }
    auto first = order.begin();
    auto last = order.end();
    for (auto i=(last-first)-1; i>0; --i) {
        swap(first[i],first[dist(gen)]);

    }
    /* for (int i = 0; i < order.size(); ++i) {
         cout << i << " --> " <<order[i] <<endl;
     }*/
    rightAnswersnr=0;
    for (int i = 0; i < order.size(); ++i) {
        Question q = quiz.getQuestions()[order[i]];
        cout << q.getText() << endl;
        for(const Answer &a : q.getAnswers()){
            cout << "\t"<<a.getText() << endl;
        }
        cout <<"Adja meg a helyes valaszt!:";
        int n;
        cin >> n;
        if(q.getAnswers()[n].isCorrect()){
            rightAnswersnr += q.getAnswers()[n].isCorrect();
            rightAnswersnr++;
        }

    }
    cout<<"Helyes valaszok szama: "<<rightAnswersnr<<endl;
}
