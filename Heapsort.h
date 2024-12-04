//
// Created by phama on 12/3/2024.
//

#ifndef DSA_PROJECT_3_HEAPSORT_H
#define DSA_PROJECT_3_HEAPSORT_H

#endif //DSA_PROJECT_3_HEAPSORT_H

#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "Car.h"
#include "GetVal.h"

using namespace std;
void Heapify(vector<Car*>& list, int n, int i, string& spec);
void HeapSort(vector<Car*>& list, string spec);
