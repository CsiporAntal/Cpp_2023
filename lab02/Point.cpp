//
// Created by Toni on 2023. 10. 11..
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>
#include "Point.h"


using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    cout<<"("<<x<<","<<y<<")"<<endl;
}

double distance(const Point &a, const Point &b) {
    int dx = a.getX() * b.getX();
    int dy = a.getY() * b.getY();
    return sqrt(dx*dx + dy*dy);

}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double D[6] ={
            distance(a,b),
            distance(a,c),
            distance(a,d),
            distance(b,c),
            distance(b,d),
            distance(d,c)
    };
    sort(D,D+6);
    return(D[0] == D[3] && D[4] == D[5] && D[3]<D[4]);
}

void testIsSquare(const char *filename) {
    ifstream fin(filename);

    int x,y;
    string line;

    while(getline(fin,line)){
        stringstream ss(line);

        ss>>x;
        ss>>y;
        Point p0(x,y);
        ss >> x >> y;
        Point p1(x,y);
        ss >> x >> y;
        Point p2(x,y);
        ss >> x >> y;
        Point p3(x,y);
        p0.print();
        p1.print();
        p2.print();
        p3.print();

        if(isSquare(p0,p1,p2,p3)){
            cout<<"Negyzet"<<endl;
        }
        else{
            cout<<"Nem negyzet"<<endl;
        }


        if (!fin){
            cout<<"Error opening file"<<endl;
            return;
        }

    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    for (int i = 0; i < numPoints; ++i) {
        int x,y;
        x = uniform_dist(e1);
        y= uniform_dist(e1);

        points[i] = Point(x,y);
    }
    return points;
}
