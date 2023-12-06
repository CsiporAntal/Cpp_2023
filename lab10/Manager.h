//
// Created by Toni on 2023. 12. 06..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include "Alkamazott.h"
#include <vector>

class Manager : public Alkamazott {
public:
    static const std::string MANAGER_MUNKAKOR;

private:
    std::vector<Alkamazott *> beosztottak;

public:
    Manager(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv);

    void addAlkamazott(Alkamazott *alkamazott);
    void deleteAlkamazottById(int id);
    void print() const;
};

#endif //CPP_2022_MANAGER_H
