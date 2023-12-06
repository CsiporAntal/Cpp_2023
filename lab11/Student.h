//
// Created by Toni on 2023. 12. 06..
//

#ifndef CPP_2022_STUDENT_H
#define CPP_2022_STUDENT_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName),
                                                                       lastName(lastName) {}

    int getId() const {
        return id;
    }

    void setId1(int id) {
        Student::id = id;
    }

    const string &getFirstName() const {
        return firstName;
    }

    const string &getLastName() const {
        return lastName;
    }

    void addGrade(const string& subject, double grade);

    double getGrade(const string& subject);

    const map<string, double> &getGrades() const;

    void computeAverage();

    double getAverage() const;

    friend ostream &operator<<(ostream &os, const Student &student);

};


#endif //CPP_2022_STUDENT_H
