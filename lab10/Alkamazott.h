//
// Created by Toni on 2023. 12. 06..
//

#ifndef CPP_2022_ALKAMAZOTT_H
#define CPP_2022_ALKAMAZOTT_H


#include <ostream>
#include "Szemely.h"

class Alkamazott : public Szemely {
private:
    static int nextId;
    int id;
    std::string munkakor;

public:
    Alkamazott(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv, const std::string &munkakor);

    int getId() const;

    virtual void print(std::ostream& os) const override;
};



#endif //CPP_2022_ALKAMAZOTT_H
