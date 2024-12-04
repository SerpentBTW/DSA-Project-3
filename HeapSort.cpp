//
// Created by phama on 12/3/2024.
//
#include "HeapSort.h"
#include "GetVal.h"

//Heapify function
void Heapify(vector<Car*>& list, int n, int i, string& spec) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && getVal(list[left], spec) > getVal(list[largest], spec)) {
        largest = left;
    }

    if (right < n && getVal(list[right], spec) > getVal(list[largest], spec)) {
        largest = right;
    }

    if (largest != i) {
        swap(list[i], list[largest]);
        Heapify(list, n, largest, spec);
    }
}

//Heap sort function
void HeapSort(vector<Car*>& list, string spec) {
    int n = list.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(list, n, i, spec);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(list[0], list[i]);
        Heapify(list, i, 0, spec);
    }
}