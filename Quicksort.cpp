//
// Created by moore on 11/26/2024.
//

#include "Quicksort.h"
#include "GetVal.h"

using namespace std;

void Quicksort(vector<Car*>& list, string spec) {
    QuicksortRecursive(list, 0, list.size()-1, spec);
}


// Recursive Quicksort function
void QuicksortRecursive(vector<Car*>& list, int start, int end, string spec) {
    if (start < end) {
        int pivot = Partition(list, start, end, spec);
        QuicksortRecursive(list, start, pivot - 1, spec);
        QuicksortRecursive(list, pivot + 1, end, spec);
    }
}

// Swaps values during the sort and reassigns pivot.
int Partition(vector<Car*>& list, int start, int end, string spec) {
    // Pivot is determined using Median of Three method to hopefully increase the chances of an appropriate center value.
    int pivot = start;
    if (end - start >= 2) {
        FindMedianVal(list, start, end, spec, pivot);
    }

    // Move pivot to the end for simplicity
    swap(list[pivot], list[end]);

    // Loops through entire list
    int swapIndex = start;
    for (int i = start; i < end; ++i) {
        if (getVal(list[i], spec) <= getVal(list[pivot], spec)) {
            swap(list[i], list[swapIndex]);
            swapIndex++;
        }
    }

    // Swaps the pivot into the correct position after rest of list placed accordingly
    swap(list[swapIndex], list[end]);

    return swapIndex;
}

// Finds the median value of the first, middle, and last elements of the list.
// This helps keep the Quicksort algorithm closer to O(NlogN) as it will try to use a more centralized pivot.
void FindMedianVal(vector<Car*>& list, int start, int end, string spec, int& pivot) {
    int firstIndex = start;
    int middleIndex = start + (end - start) / 2;
    int lastIndex = end;

    int firstVal = getVal(list[start],spec);
    int middleVal = getVal(list[end/2],spec);
    int lastVal = getVal(list[end],spec);

    // O(1) logic checks to determine middle value
    if (((firstVal > middleVal) && (firstVal < lastVal)) || ((firstVal > lastVal) && (firstVal < middleVal))) {
        pivot = firstIndex;
    }
    else if (((middleVal > firstVal) && (middleVal < lastVal)) || ((middleVal > lastVal) && (middleVal < firstVal))) {
        pivot = middleIndex;
    }
    else {
        pivot = lastIndex;
    }
}