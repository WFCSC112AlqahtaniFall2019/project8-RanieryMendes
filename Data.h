//
// Created by Raniery Costa Mendes on 11/16/19.
//
#include <string>

using namespace std;

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

class Data{
public:
    bool operator < ( Data obj);
    friend ostream& operator<<(ostream& os, const Data& obj);

    string countryName;
    string countryCode;
    string countryRegion;
    int CPI;


};

#endif //PROJECT8_DATA_H
