//
// Created by Toni on 2023. 11. 22..
//

#include "QuizGame.h"
#include "User.h"

int User::counter = 0;

User::User(const std::string& name) : name(name) {
    id = ++counter;
}

int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

void User::addScore(const std::string& quizName, double score) {
    scores[quizName] = score;
}

double User::getScore(const std::string& quizName) const {
    auto it = scores.find(quizName);
    return (it != scores.end()) ? it->second : 0.0;
}

void User::print(std::ostream& os) const {
    os << "User ID: " << id << ", Name: " << name << std::endl;
    for (const auto& score : scores) {
        os << "Quiz: " << score.first << ", Score: " << score.second << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    user.print(os);
    return os;
}
