#include <iostream>
#include <vector>
#include "GraduationDao.h"

int main() {
    std::cout << "Hello, Lab_11" << std::endl;

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    vector<string> subjects{"matek", "roman", "magyar"};
    int numSubjects = subjects.size();
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    return 0;
}