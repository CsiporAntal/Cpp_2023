//
// Created by Toni on 2023. 12. 13..
//

#include "Settlement.h"
Settlement::Settlement(const string &name, const string &county, int population)
        : name(name), county(county), population(population) {}

string Settlement::getName() const { return name; }

string Settlement::getCounty() const { return county; }

int Settlement::getPopulation() const { return population; }

