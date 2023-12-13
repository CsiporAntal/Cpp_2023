//
// Created by Toni on 2023. 12. 13..
//

#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filePath) {
    // Read data from the CSV file and populate the multimap
    ifstream file(filePath);
    string line;

    while (getline(file, line)) {
        // Assuming CSV format: name,code,population
        size_t pos = line.find(',');
        string name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        string code = line.substr(0, pos);
        line.erase(0, pos + 1);

        int population = stoi(line);

        settlements.insert({ code, Settlement(name, code, population) });
    }

    file.close();
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    auto range = settlements.equal_range(county);
    vector<Settlement> result;
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto range = settlements.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getName() == name) {
            return it->second;
        }
    }
    // Return an empty Settlement if not found
    return Settlement("", "", 0);
}

Settlement SettlementStatisticsImpl::minPopulation() const {
    auto minIt = min_element(settlements.begin(), settlements.end(),
                             [](const auto& a, const auto& b) {
                                 return a.second.getPopulation() < b.second.getPopulation();
                             });

    return minIt->second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for (const auto& entry : settlements) {
        if (entry.second.getName() == name) {
            result.push_back(entry.second);
        }
    }
    return result;
}

Settlement SettlementStatisticsImpl::maxPopulation() const {
    auto maxIt = max_element(settlements.begin(), settlements.end(),
                             [](const auto& a, const auto& b) {
                                 return a.second.getPopulation() < b.second.getPopulation();
                             });

    return maxIt->second;
}
