//
// Created by Toni on 2023. 12. 06..
//

#include <iostream>
#include <algorithm>
#include "Manager.h"


const std::string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv)
        : Alkamazott(vezetekNev, keresztNev, szuletesiEv, MANAGER_MUNKAKOR) {}

void Manager::addAlkamazott(Alkamazott *alkamazott) {
    beosztottak.push_back(alkamazott);
}

void Manager::deleteAlkamazottById(int id) {
    auto it = std::remove_if(beosztottak.begin(), beosztottak.end(),
                             [id](Alkamazott *alkamazott) { return alkamazott->getId() == id; });

    beosztottak.erase(it, beosztottak.end());
}

void Manager::print() const {
    Alkamazott::print(std::cout);
    std::cout << ", Beosztottak szama: " << beosztottak.size() << std::endl;

    for (const auto& alkamazott : beosztottak) {
        std::cout << "Alkalmazott " << alkamazott->getId() << " ";
        alkamazott->print(std::cout);
        std::cout << std::endl;
    }
}








