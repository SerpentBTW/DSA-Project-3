#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <vector>
#include "Car.h"
#include "Quicksort.h"
#include "ShellSort.h"
#include "HeapSort.h"
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
        Car *carConstruct = new Car(make, model, stoi(year), stoi(price), stoi(mileage), mpg, engine, transmission, drivetrain,
                                    fuelType, sellerName, sellerRating, accidentBool, oneOwnerBool, personalUseBool);
        dataSet.push_back(carConstruct);

        }

    vector<Car*> quickData(dataSet);
    vector<Car*> shellData(dataSet);
    vector<Car*> heapData(dataSet);


    int numLines = 0;
    int specInt = 0;
    int printOrder = 0;
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
        cout << "Ascending or Descending order? (Input number)" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        cin >> printOrder;
        cout << endl;

        if (specInt == 1 || specInt == 4) {
            auto ShellStart = std::chrono::high_resolution_clock::now();
            ShellSort(shellData, spec);
            auto ShellStop = std::chrono::high_resolution_clock::now();
            auto HeapStart = std::chrono::high_resolution_clock::now();
            HeapSort(heapData, spec);
            auto HeapStop = std::chrono::high_resolution_clock::now();

            auto ShellDuration = std::chrono::duration_cast<std::chrono::milliseconds>(ShellStop - ShellStart);
            auto HeapDuration = std::chrono::duration_cast<std::chrono::milliseconds>(HeapStop - HeapStart);
            if (printOrder == 1) {
                for (int i = 0; i < numLines; i++) {
                    cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | "
                         << shellData[i]->getModel() << " | " << "$" << shellData[i]->getPrice() << " | "
                         << shellData[i]->getMileage() << " miles" << " | " << shellData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = 0; i < numLines; i++) {
                    cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | "
                         << heapData[i]->getModel() << " | " << "$" << heapData[i]->getPrice() << " | "
                         << heapData[i]->getMileage() << " miles" << " | " << heapData[i]->getMpg() << "mpg" << endl;
                }
            }
            else if (printOrder == 2) {
                cout << "Shell Sort Execution Time: " << ShellDuration.count() << "  milliseconds" << endl;
                cout << endl;
                for (int i = shellData.size() - 1;i > shellData.size() - numLines; i--) {
                    cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | "
                         << shellData[i]->getModel() << " | " << "$" << shellData[i]->getPrice() << " | "
                         << shellData[i]->getMileage() << " miles" << " | " << shellData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = heapData.size() - 1;i > heapData.size() - numLines; i--) {
                    cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | "
                         << heapData[i]->getModel() << " | " << "$" << heapData[i]->getPrice() << " | "
                         << heapData[i]->getMileage() << " miles" << " | " << heapData[i]->getMpg() << "mpg" << endl;
                }
            }
        }
        else {
            auto QuickStart = std::chrono::high_resolution_clock::now();
            Quicksort(quickData, spec);
            auto QuickStop = std::chrono::high_resolution_clock::now();
            auto ShellStart = std::chrono::high_resolution_clock::now();
            ShellSort(shellData, spec);
            auto ShellStop = std::chrono::high_resolution_clock::now();
            auto HeapStart = std::chrono::high_resolution_clock::now();
            HeapSort(heapData, spec);
            auto HeapStop = std::chrono::high_resolution_clock::now();

            auto QuickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(QuickStop - QuickStart);
            auto ShellDuration = std::chrono::duration_cast<std::chrono::milliseconds>(ShellStop - ShellStart);
            auto HeapDuration = std::chrono::duration_cast<std::chrono::milliseconds>(HeapStop - HeapStart);
            if (printOrder == 1) {
                cout << "Quick Sort Execution Time: " << QuickDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = 0; i < numLines; i++) {
                    cout << quickData[i]->getYear() << " | " << quickData[i]->getMake() << " | "
                         << quickData[i]->getModel() << " | " << "$" << quickData[i]->getPrice() << " | "
                         << quickData[i]->getMileage() << " miles" << " | " << quickData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Shell Sort Execution Time: " << ShellDuration.count() << "  milliseconds" << endl;
                cout << endl;
                for (int i = 0; i < numLines; i++) {
                    cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | "
                         << shellData[i]->getModel() << " | " << "$" << shellData[i]->getPrice() << " | "
                         << shellData[i]->getMileage() << " miles" << " | " << shellData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = 0; i < numLines; i++) {
                    cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | "
                         << heapData[i]->getModel() << " | " << "$" << heapData[i]->getPrice() << " | "
                         << heapData[i]->getMileage() << " miles" << " | " << heapData[i]->getMpg() << "mpg" << endl;
                }
            }
            else if (printOrder == 2) {
                cout << "Quick Sort Execution Time: " << QuickDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = quickData.size() - 1;i > quickData.size() - numLines; i--) {
                    cout << quickData[i]->getYear() << " | " << quickData[i]->getMake() << " | "
                         << quickData[i]->getModel() << " | " << "$" << quickData[i]->getPrice() << " | "
                         << quickData[i]->getMileage() << " miles" << " | " << quickData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Shell Sort Execution Time: " << ShellDuration.count() << "  milliseconds" << endl;
                cout << endl;
                for (int i = shellData.size() - 1;i > shellData.size() - numLines; i--) {
                    cout << shellData[i]->getYear() << " | " << shellData[i]->getMake() << " | "
                         << shellData[i]->getModel() << " | " << "$" << shellData[i]->getPrice() << " | "
                         << shellData[i]->getMileage() << " miles" << " | " << shellData[i]->getMpg() << "mpg" << endl;
                }
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
                cout << endl;
                for (int i = heapData.size() - 1;i > heapData.size() - numLines; i--) {
                    cout << heapData[i]->getYear() << " | " << heapData[i]->getMake() << " | "
                         << heapData[i]->getModel() << " | " << "$" << heapData[i]->getPrice() << " | "
                         << heapData[i]->getMileage() << " miles" << " | " << heapData[i]->getMpg() << "mpg" << endl;
                }
            }
        }
    return 0;
}
