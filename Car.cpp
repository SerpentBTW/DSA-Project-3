//
// Created by moore on 11/25/2024.
//

#include "Car.h"
#include <iostream>
Car::Car(string make, string model, int year, int price, int mileage, string mpg, string engine, string transmission,
         string drivetrain, string fuelType, string sellerName, string sellerRating, bool accidents, bool oneOwner,
         bool personalUseOnly) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->mileage = mileage;
    this->mpg = mpg;
    this->engine = engine;
    this->transmission = transmission;
    this->drivetrain = drivetrain;
    this->fuelType = fuelType;
    this->sellerName = sellerName;
    this->sellerRating = sellerRating;
    this->accidents = accidents;
    this->oneOwner = oneOwner;
    this->personalUseOnly = personalUseOnly;

    // Ideally stores second number in mpg string (##-##) as mpgHigh.
    // Handles edge cases where mpg in incorrect form.
    string mpgHighString;
    string firstNum;
    bool afterDash = false;
    bool useFirstNum = true;
    for (auto c : mpg) {
        if (afterDash) {
            if (c < 48 || c > 57) {
                useFirstNum = true;
                break;
            }
            mpgHighString.push_back(c);
        }
        if (!afterDash) {
            firstNum.push_back(c);
        }
        if (c == '-') {
            afterDash = true;
            useFirstNum = false;
        }
    }
    try {
        if (useFirstNum) {
            this->mpgHigh = stoi(firstNum);
        }
        else {
            this->mpgHigh = stoi(mpgHighString);
        }
    } catch (const exception& e){
        this->mpgHigh = -1;
        cerr << e.what() << endl;
    }
}

string Car::getMake() {
    return make;
}

string Car::getModel() {
    return model;
}

int Car::getYear() {
    return year;
}

int Car::getPrice() {
    return price;
}

int Car::getMileage() {
    return mileage;
}

string Car::getMpg() {
    return mpg;
}

int Car::getMpgHigh() {
    return mpgHigh;
}

string Car::getEngine() {
    return engine;
}

string Car::getTransmission() {
    return transmission;
}

string Car::getDrivetrain() {
    return drivetrain;
}

string Car::getFuelType() {
    return fuelType;
}

string Car::getSellerName() {
    return sellerName;
}

string Car::getSellerRating() {
    return sellerRating;
}

bool Car::getAccidents() {
    return accidents;
}

bool Car::getOneOwner() {
    return oneOwner;
}

bool Car::getPersonalUseOnly() {
    return personalUseOnly;
}
