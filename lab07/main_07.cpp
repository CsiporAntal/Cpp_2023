#include <iostream>
#include "User.h"
#include "Quiz.h"
#include "QuizGame.h"

int main() {
    User users[] = {User("Peter"), User("Kati")};
    Quiz quizzes[] = {Quiz("cpp1"), Quiz("cpp2")};
    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);

    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.play();
            std::cout << "Name: " << game.getUser().getName() << ", score: "
                      << game.getScore() << std::endl
                      << std::endl;
        }
    }

    std::cout << std::endl
              << "****************" << std::endl;
    std::cout << "Users' results:" << std::endl;
    for (int i = 0; i < num_users; ++i) {
        std::cout << users[i] << std::endl;
    }
    std::cout << "****************" << std::endl;

    return 0;
}
