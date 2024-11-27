//
// Created by moore on 11/27/2024.
//

#include "GetVal.h"

int getVal(Car* car, string& spec) {
    if (spec == "year")
        return car->getYear();
    else if (spec == "price")
        return car->getPrice();
    else if (spec == "mileage")
        return car->getMileage();
    else if (spec == "mpg")
        return car->getMpg();
    else
        return -1;
}