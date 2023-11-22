//
// Created by Toni on 2023. 11. 22..
//

#ifndef CPP_2022_USER_H
#define CPP_2022_USER_H

#include <iostream>
#include <map>
#include <string>

class User {
private:
    int id;
    std::string name;
    std::map<std::string, double> scores;
    static int counter;

public:
    User(const std::string& name);
    int getId() const;
    const std::string& getName() const;
    void addScore(const std::string& quizName, double score);
    double getScore(const std::string& quizName) const;
    void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};


#endif //CPP_2022_USER_H
