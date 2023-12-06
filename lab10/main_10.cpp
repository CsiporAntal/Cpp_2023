#include <iostream>
#include "Alkamazott.h"
#include "Manager.h"
#include "Ceg.h"


int main() {
    Ceg ceg;

    // 10 szemely 3 manager
    for (int i = 1; i <= 10; ++i) {
        if (i <= 3) {
            ceg.ujAlkalmazott(new Manager("Manager", std::to_string(i), 1980 + i * 5));
        } else {
            ceg.ujAlkalmazott(new Alkamazott("Alkamazott", std::to_string(i), 1990 + i * 3, "Munka"));
        }
    }

    // hozzaradeneles a managerekhez
    for (int i = 3; i < 10; i++) {
        ceg.hozzaadAlkalmazottatManagerhez(static_cast<Manager*>(ceg.getAlkalmazott(i % 3)), static_cast<Alkamazott*>(ceg.getAlkalmazott(i)));
    }

    ceg.listazCsakManagerek();

    // athelzeyes egyik managerto la maskhoz
       ceg.levallasztAlkalmazottatManagertol(static_cast<Manager*>(ceg.getAlkalmazott(0)), static_cast<Alkamazott*>(ceg.getAlkalmazott(3)));
    ceg.hozzaadAlkalmazottatManagerhez(static_cast<Manager*>(ceg.getAlkalmazott(1)), static_cast<Alkamazott*>(ceg.getAlkalmazott(3)));

    ceg.listazCsakManagerek();

    return 0;
}
