#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Car.h"
#include "Quicksort.h"
#include "ShellSort.h"
using namespace std;


int main(){
    // List for testing purposes;
    // 3 2 5 0 1 8 7 6 9 4
    vector<Car*> Testlist;
    Testlist.emplace_back(new Car("make", "model", 2024, 3, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 2, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 5, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 0, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 1, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 8, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 7, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 6, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 9, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    Testlist.emplace_back(new Car("make", "model", 2024, 4, 10, "10", "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));

    ShellSort(Testlist, "price");

    for (auto c : Testlist) {
        cout << c->getPrice() << endl;
    }


    string make,model,year,price,mileage,mpg,engine,transmission,drivetrain,fuelType,sellerName,sellerRating,accidents,oneOwner,personalUseOnly;
    bool accidentBool, oneOwnerBool, personalUseBool;
    string exterior_color, interior_color, driver_rating, driver_reviews, price_drop;

    vector<Car*> dataSet;
    ifstream in("data.csv", ios::in);
    string row;
    getline(in, row);



    while(!in.eof()) {
        getline(in, row);
        stringstream s(row);
        getline(s, make, ',');
        getline(s, model, ',');
        getline(s, year, ',');
        getline(s, mileage, ',');
        getline(s, engine, ',');
        getline(s, transmission, ',');
        getline(s, drivetrain, ',');
        getline(s, fuelType, ',');
        getline(s, mpg, ',');
        getline(s, exterior_color, ',');
        getline(s, interior_color,',');
        getline(s, accidents, ',');
        getline(s, oneOwner, ',');
        getline(s, personalUseOnly, ',');
        getline(s, sellerName, ',');
        getline(s, sellerRating, ',');
        getline(s, driver_rating, ',');
        getline(s, driver_reviews,',');
        getline(s, price_drop,',');
        getline(s,price,',');
        if(accidents == "1"){
            accidentBool = true;
        }
        if(oneOwner == "1"){
            oneOwnerBool = true;
        }
        if(personalUseOnly == "1"){
            personalUseBool = true;
        }
        try {
            Car *carConstruct = new Car(make, model, stoi(year), stoi(price), stoi(mileage), mpg, engine, transmission, drivetrain,
                                        fuelType, sellerName, sellerRating, accidentBool, oneOwnerBool, personalUseBool);
            dataSet.push_back(carConstruct);
        }
        catch(std::invalid_argument){}
    }
    cout << dataSet.size() << endl;


    bool run = true;
    int numLines = 0;
    int algoInput = 0;
    int specInt = 0;
    string spec;
    while (run) {
        cout << "How many lines would you like to output? (Input number)" << endl;
        cin >> numLines;

        cout << "Which algorithm would you like to perform? (Input number)" << endl;
        cout << "1. Quick sort" << endl;
        cout << "2. Shell sort" << endl;
        cout << "3. Heap sort" << endl;
        cin >> algoInput;

        cout << "What spec would you like to filter by? (Input number)" << endl;
        cout << "1. Year" << endl;
        cout << "2. Price" << endl;
        cout << "3. Mileage" << endl;
        cout << "4. MPG" << endl;
        cin >> specInt;
        //Converting ui selection to string for sorting parameters
        if (specInt == 1) {
            spec = "year";
        }
        else if (specInt == 2) {
            spec = "price";
        }
        else if (specInt == 3) {
            spec = "mileage";
        }
        else if (specInt == 4) {
            spec = "mpg";
        }

        if (algoInput == 1) {
            Quicksort(dataSet, spec);
        }
        else if (algoInput == 2) {
            ShellSort(dataSet, spec);
        }
        else if (algoInput == 3) {
            //Radix sort
        }
        else {
            cout << "Invalid input";
            run = false;
        }
        for (int i = 0; i < numLines; i++) {
            cout << dataSet[i]->getPrice() << endl;
        }
    }

    return 0;
}
