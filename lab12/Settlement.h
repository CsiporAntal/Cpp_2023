//
// Created by Toni on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENT_H
#define CPP_2022_SETTLEMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Settlement {
public:
    Settlement(const string& name, const string& county, int population);

    // Getters
    string getName() const;
    string getCounty() const;
    int getPopulation() const;

private:
    string name;
    string county;
    int population;
};


#endif //CPP_2022_SETTLEMENT_H
