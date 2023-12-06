//
// Created by Toni on 2023. 12. 06..
//

#include "Szemely.h"

Szemely::Szemely(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv)
        : vezetekNev(vezetekNev), keresztNev(keresztNev), SzuletesiEv(szuletesiEv) {}

void Szemely::print(std::ostream& os) const {
    os << "Vezeteknev: " << vezetekNev << ", Keresztnev: " << keresztNev
       << ", Szuletesi ev: " << SzuletesiEv;
}

std::ostream& operator<<(std::ostream& os, const Szemely& szemely) {
    szemely.print(os);
    return os;
}


