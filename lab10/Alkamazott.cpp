//
// Created by Toni on 2023. 12. 06..
//

#include "Alkamazott.h"

int Alkamazott::nextId = 1;

Alkamazott::Alkamazott(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv, const std::string &munkakor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), id(nextId++), munkakor(munkakor) {}

int Alkamazott::getId() const {
    return id;
}

void Alkamazott::print(std::ostream& os) const {
    Szemely::print(os);
    os << ", ID: " << id << ", Munkakor: " << munkakor;
}

