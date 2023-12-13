//
// Created by Toni on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H

#include <algorithm>
#include <set>
#include "Settlement.h"
struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
            const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
            const string& name, const string& county) const = 0;
    virtual Settlement maxPopulation() const = 0;
    virtual Settlement minPopulation() const = 0;
    virtual vector<Settlement> findSettlementsByName(
            const string& name) = 0;
};


class SettlementStatisticsImpl : public SettlementStatistics {
public:
    SettlementStatisticsImpl(const string& filePath);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string& county) const override;

    vector<Settlement> findSettlementsByCounty(const string& county) const override;

    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;

    Settlement maxPopulation() const override;

    Settlement minPopulation() const override;

    vector<Settlement> findSettlementsByName(const string& name) override;

private:
    multimap<string, Settlement> settlements;
    set<string> counties;  // Optional: Store unique counties for additional functionality
};



#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H
