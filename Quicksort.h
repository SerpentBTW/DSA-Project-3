//
// Created by moore on 11/26/2024.
//

#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "Car.h"
#include "GetVal.h"

using namespace std;

void Quicksort(vector<Car*>& list, string spec);
void QuicksortRecursive(vector<Car*>& list, int start, int end, string spec);
int Partition(vector<Car*>& list, int start, int end, string spec);
void FindMedianVal(vector<Car*>& list, int start, int end, string spec, int& pivot);

void ThreeWayPartition(vector<Car*>& list, int start, int end, string spec, int& leftEnd, int& rightStart);

