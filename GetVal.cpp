//
// Created by moore on 11/27/2024.
//

#include "GetVal.h"
//Gets the field based on a spec given into the function adn the specific node given
int getVal(Car* car, string& spec) {
    if (spec == "year")
        return car->getYear();
    else if (spec == "price")
        return car->getPrice();
    else if (spec == "mileage")
        return car->getMileage();
    else if (spec == "mpg")
        return car->getMpgHigh();
    else
        return -1;
}