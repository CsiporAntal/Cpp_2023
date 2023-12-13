#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {
    SettlementStatisticsImpl statistics("telepulesek.csv");

    // Test the implemented functions
    cout << "Number of settlements: " << statistics.numSettlements() << endl;
    cout << "Number of counties: " << statistics.numCounties() << endl;

    string countyToSearch = "SomeCounty";
    cout << "Number of settlements in " << countyToSearch << ": " << statistics.numSettlementsByCounty(countyToSearch) << endl;

    string countyToFindSettlements = "SomeCounty";
    vector<Settlement> settlementsInCounty = statistics.findSettlementsByCounty(countyToFindSettlements);
    cout << "Settlements in " << countyToFindSettlements << ":" << endl;
    for (const auto& settlement : settlementsInCounty) {
        cout << "Name: " << settlement.getName() << ", Population: " << settlement.getPopulation() << endl;
    }

    string settlementToFind = "SomeSettlement";
    Settlement foundSettlement = statistics.findSettlementsByNameAndCounty(settlementToFind, countyToFindSettlements);
    cout << "Settlement found - Name: " << foundSettlement.getName() << ", Population: " << foundSettlement.getPopulation() << endl;

    Settlement maxPopulationSettlement = statistics.maxPopulation();
    cout << "Settlement with the maximum population - Name: " << maxPopulationSettlement.getName() << ", Population: " << maxPopulationSettlement.getPopulation() << endl;

    Settlement minPopulationSettlement = statistics.minPopulation();
    cout << "Settlement with the minimum population - Name: " << minPopulationSettlement.getName() << ", Population: " << minPopulationSettlement.getPopulation() << endl;

    string nameToFindSettlements = "SomeName";
    vector<Settlement> settlementsByName = statistics.findSettlementsByName(nameToFindSettlements);
    cout << "Settlements with the name " << nameToFindSettlements << ":" << endl;
    for (const auto& settlement : settlementsByName) {
        cout << "County: " << settlement.getCounty() << ", Population: " << settlement.getPopulation() << endl;
    }


    return 0;
}