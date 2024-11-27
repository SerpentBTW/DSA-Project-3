//
// Created by moore on 11/26/2024.
//

#pragma once

#include "Car.h"

using namespace std;

template<typename T>
T getVal(Car& car, string& spec) {
    if (spec == "make")
        return car.getMake();
    else if (spec == "model")
        return car.getModel();
    else if (spec == "year")
        return car.getYear();
    else if (spec == "price")
        return car.getPrice();
    else if (spec == "mileage")
        return car.getMileage();
    else if (spec == "mpg")
        return car.getMpg();
    else if (spec == "engine")
        return car.getEngine();
    else if (spec == "transmission")
        return car.getTransmission();
    else if (spec == "drivetrain")
        return car.getDrivetrain();
    else if (spec == "fuelType")
        return car.getFuelType();
    else if (spec == "sellerName")
        return car.getSellerName();
    else if (spec == "sellerRating")
        return car.getSellerRating();
    else if (spec == "accidents")
        return car.getAccidents();
    else if (spec == "oneOwner")
        return car.getOneOwner();
    else if (spec == "personalUseOnly")
        return car.getPersonalUseOnly();
    else
        return "ERROR";
}