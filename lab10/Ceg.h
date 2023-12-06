//
// Created by Toni on 2023. 12. 06..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H

#include "Manager.h"
#include <vector>

using namespace std;

class Ceg {
private:
    vector <Szemely *> alkalmazottak;
public:

    void ujAlkalmazott(Szemely* alkamazott);
    void elbocsatAlkalmazott(int id);
    void hozzaadAlkalmazottatManagerhez(Manager* manager, Alkamazott* alkamazott);
    void levallasztAlkalmazottatManagertol(Manager* manager, Alkamazott* alkamazott);
    void listazAlkalmazottak() const;
    void listazCsakManagerek() const;

    Szemely* getAlkalmazott(int index);

};


#endif //CPP_2022_CEG_H
