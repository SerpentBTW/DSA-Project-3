#include <iostream>
#include <vector>
#include "Car.h"
#include "Quicksort.h"
using namespace std;


int main(){
    // List for testing purposes;
    // 3 2 5 0 1 8 7 6 9 4
    vector<Car*> list;
    list.emplace_back(new Car("make", "model", 2024, 3, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 2, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 5, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 0, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 1, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 8, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 7, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 6, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 9, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));
    list.emplace_back(new Car("make", "model", 2024, 4, 10, 10, "engine", "transmission", "drivetrain", "fuelType", "sellerName", "sellerRating", 0, 0, 0));

    Quicksort(list, "price");

    for (auto c : list) {
        cout << c->getPrice() << endl;
    }


    return 0;
}
