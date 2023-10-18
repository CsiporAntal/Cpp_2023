//
// Created by Toni on 2023. 10. 18..
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"


PointSet::PointSet(int n) : n(n){

    for (int i = 0; i < n; i++ ) {
        int x = rand() % (M + 1);
        int y = rand() % (M+1);
        points.emplace_back(x,y);
    }
    computeDistances();
}
void PointSet::computeDistances() {
    distances.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}
double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}
void PointSet::printPoints() const {
    for (const Point& p: points){
        cout<< "X: "<<p.getX()<<"Y: "<<p.getY()<<endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}
void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances() {
    sort(distances.begin(),distances.end());
    auto last = unique(distances.begin(),distances.end());
    return  distance(distances.begin(),last);
}

void PointSet::printDistances() const {
    for (double d: distances){
        cout<<d<<endl;
    }
}

int PointSet::numDistances() const {
    return distances.size();
}





