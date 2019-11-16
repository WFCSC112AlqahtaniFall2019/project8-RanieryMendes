#include "Data.h"
//
// Created by Raniery Costa Mendes on 11/16/19.
//

#include <iostream>
bool Data::operator<( Data obj) {
   return  this->CPI < obj.CPI;

   };

ostream& ::operator<<(ostream &os, const Data &obj) {

    os << obj.countryName << " " << obj.countryCode << " ";
    os << obj.countryRegion << " " << obj.CPI << endl;

    return os;
}
