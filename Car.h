//
// Created by moore on 11/25/2024.
//

#pragma once
#include <string>

using namespace std;

class Car {
private:
    // REQUIRED
    string make;
    string model;
    int year;
    int price;
    int mileage;
    int mpg;

    // RECOMMENDED
    string engine;
    string transmission;
    string drivetrain;
    string fuelType;
    string sellerName;
    string sellerRating;
    bool accidents;
    bool oneOwner;
    bool personalUseOnly;

public:
    Car(string make,string model,int year,int price,int mileage,int mpg,string engine,string transmission,string drivetrain,string fuelType,string sellerName,string sellerRating,bool accidents,bool oneOwner,bool personalUseOnly);
    string getMake();
    string getModel();
    int getYear();
    int getPrice();
    int getMileage();
    int getMpg();
    string getEngine();
    string getTransmission();
    string getDrivetrain();
    string getFuelType();
    string getSellerName();
    string getSellerRating();
    bool getAccidents();
    bool getOneOwner();
    bool getPersonalUseOnly();
};
