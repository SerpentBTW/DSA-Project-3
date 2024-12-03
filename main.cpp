#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Car.h"
#include "Quicksort.h"
#include "ShellSort.h"
#include "Heapsort.h"
using namespace std;


int main(){
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

    vector<Car*> quickData(dataSet);
    vector<Car*> shellData(dataSet);
    vector<Car*> heapData(dataSet);


    int numLines = 0;
    int specInt = 0;
    string spec;

        cout << "Welcome to MotorMatch" << endl;
        cout << "---------------------------------------------------------" << endl;

        cout << "What parameter would you like to sort by? (Input number)" << endl;
        cout << "1. Year" << endl;
        cout << "2. Price" << endl;
        cout << "3. Mileage" << endl;
        cout << "4. MPG" << endl;
        cin >> specInt;

        cout << "How many lines would you like to output? (Input number)" << endl;
        cin >> numLines;
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
        else {
            cout << "Invalid input, rerun program with compatible inputs.";
            return 0;
        }
        //Skip quick sort for year and mpg
        if (specInt == 1 || specInt == 4) {
            ShellSort(shellData, spec);
            HeapSort(heapData, spec);
        }
        else {
            Quicksort(quickData, spec);
            ShellSort(shellData, spec);
            HeapSort(heapData, spec);
        }
        //Print Shell and Heap if year or mpg selected
        if (specInt == 1 || specInt == 4) {
            //Print Shell sort
            for (int i = 0; i < numLines; i++) {
                cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | " << shellData[i]->getModel()
                     << " | " << "$" << shellData[i]->getPrice() << " | " << shellData[i]->getMileage() << " miles" << " | "
                     << shellData[i]->getMpg() << "mpg" << endl;
            }
            cout << "-----------------------------------------------" << endl;
            //Print Heap sort
            for (int i = 0; i < numLines; i++) {
                cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | " << heapData[i]->getModel()
                     << " | " << "$" << heapData[i]->getPrice() << " | " << heapData[i]->getMileage() << " miles" << " | "
                     << heapData[i]->getMpg() << "mpg" << endl;
            }
        }
        //Print all 3 sorts
        else {
            //Print Quick sort
            for (int i = 0; i < numLines; i++) {
                cout << quickData[i]->getYear() << " | " << quickData[i]->getMake() << " | " << quickData[i]->getModel()
                     << " | " << "$" << quickData[i]->getPrice() << " | " << quickData[i]->getMileage() << " miles" << " | "
                     << quickData[i]->getMpg() << "mpg" << endl;
            }
            cout << "-----------------------------------------------" << endl;
            //Print Shell sort
            for (int i = 0; i < numLines; i++) {
                cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | " << shellData[i]->getModel()
                     << " | " << "$" << shellData[i]->getPrice() << " | " << shellData[i]->getMileage() << " miles" << " | "
                     << shellData[i]->getMpg() << "mpg" << endl;
            }
            cout << "-----------------------------------------------" << endl;
            //Print Heap sort
            for (int i = 0; i < numLines; i++) {
                cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | " << heapData[i]->getModel()
                     << " | " << "$" << heapData[i]->getPrice() << " | " << heapData[i]->getMileage() << " miles" << " | "
                     << heapData[i]->getMpg() << "mpg" << endl;
            }
        }



    for(auto d : dataSet){
        delete d;
    }
    return 0;
}
