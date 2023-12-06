//
// Created by Toni on 2023. 12. 06..
//

#include "Student.h"

void Student::addGrade(const string &subject, double grade) {
    grades[subject]=grade;
}

double Student::getGrade(const string &subject) {
//    auto it = grades.find(subject);
//    if (it == grades.end())
//        throw out_of_range("nincs ilyen targy");
//    return it->second;
//
    return grades.at(subject);
 }

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    this->average = 0;
    double average = 0;
    for (auto [key, value] : grades ) {
        if(value < 5) return;
        average += value;
    }
    this->average = average / grades.size();
}

double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "id: " << student.id << " firstName: " << student.firstName << " lastName: " << student.lastName << endl;
    for(auto [key, value] : student.grades){
        os << key << ": " << value << '\t';
    }
       os << " average: " << student.average;
    return os;
}




