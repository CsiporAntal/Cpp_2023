//
// Created by Toni on 2023. 12. 06..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H

#include <iostream>
#include <string>

class Szemely {
private:
    std::string vezetekNev;
    std::string keresztNev;
    int SzuletesiEv;

public:
    Szemely(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv);

    virtual void print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Szemely& szemely);
};


#endif //CPP_2022_SZEMELY_H
