//
// Created by Toni on 2023. 12. 06..
//

#include <algorithm>
#include "Ceg.h"


void Ceg::ujAlkalmazott(Szemely* alkamazott) {
    alkalmazottak.push_back(alkamazott);
}

void Ceg::elbocsatAlkalmazott(int id) {
    auto it = std::remove_if(alkalmazottak.begin(), alkalmazottak.end(),
                             [id](Szemely* szemely) {
                                 if (Alkamazott* alkamazott = dynamic_cast<Alkamazott*>(szemely)) {
                                     return alkamazott->getId() == id;
                                 }
                                 return false;
                             });

    alkalmazottak.erase(it, alkalmazottak.end());
}

void Ceg::hozzaadAlkalmazottatManagerhez(Manager* manager, Alkamazott* alkamazott) {
    if (manager) {
        manager->addAlkamazott(alkamazott);
    }
}

void Ceg::levallasztAlkalmazottatManagertol(Manager* manager, Alkamazott* alkamazott) {
    if (manager) {
        manager->deleteAlkamazottById(alkamazott->getId());
    }
}

void Ceg::listazAlkalmazottak() const {
    std::cout << "Lista az osszes alkalmazottról:" << std::endl;
    for (const auto& alkamazott : alkalmazottak) {
        alkamazott->print(std::cout);
        std::cout << std::endl;
    }
}

void Ceg::listazCsakManagerek() const {
    std::cout << "Lista csak a managerekrol:" << std::endl;
    for (const auto& alkamazott : alkalmazottak) {
        if (Manager* manager = dynamic_cast<Manager*>(alkamazott)) {
            manager->print();
            std::cout << std::endl;
        }
    }
}

Szemely *Ceg::getAlkalmazott(int index) {
    if (index >= 0 && index < alkalmazottak.size()) {
        return alkalmazottak[index];
    }
    return nullptr;
}

