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
    //Creates DataSet vector and opens the csv file
    vector<Car*> dataSet;
    ifstream in("data.csv", ios::in);
    string row;
    getline(in, row);


    //Goes through csv file and puts all data into the Car objects.
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
    //Copies dataset to be adjusted with each sorting algorithm.
    vector<Car*> quickData(dataSet);
    vector<Car*> shellData(dataSet);
    vector<Car*> heapData(dataSet);


    int numLines = 0;
    int specInt = 0;
    int printOrder = 0;
    string spec;
    //UI Starts
        cout << "Welcome to MotorMatch" << endl;
        cout << "---------------------------------------------------------" << endl;

        cout << "What parameter would you like to sort by? (Input number)" << endl;
        cout << "1. Year" << endl;
        cout << "2. Price" << endl;
        cout << "3. Mileage" << endl;
        cout << "4. MPG" << endl;
        cin >> specInt;
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
        cout << "How many lines would you like to output? (Input number)" << endl;
        cin >> numLines;
        if(numLines <= 0 || numLines > 229402){
            cout << "Invalid input, rerun program with compatible inputs.";
            return 0;
        }
        //Converting ui selection to string for sorting parameters
        cout << "Ascending or Descending order? (Input number)" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        cin >> printOrder;
        cout << endl;
        //Starts each sorting algorithsm and records the time it takes for each algorithm to complete.
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
            //Prints first n number of lines
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
                cout << "-----------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "Quick Sort Execution Time: " << QuickDuration.count() << " milliseconds" << endl;
                cout << "Shell Sort Execution Time: " << ShellDuration.count() << "  milliseconds" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
            }
            //Prints last n number of lines
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
                cout << "-----------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "Quick Sort Execution Time: " << QuickDuration.count() << " milliseconds" << endl;
                cout << "Shell Sort Execution Time: " << ShellDuration.count() << "  milliseconds" << endl;
                cout << "Heap Sort Execution Time: " << HeapDuration.count() << " milliseconds" << endl;
            }
            else {
                cout << "Invalid input, rerun program with compatible inputs.";
                return 0;
            }
    return 0;
}
