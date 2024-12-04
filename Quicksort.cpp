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
        int LTEnd;
        int GTStart;
        ThreeWayPartition(list, start, end, spec, LTEnd, GTStart);

        QuicksortRecursive(list, start, LTEnd, spec);
        QuicksortRecursive(list, GTStart, end, spec);
    }
}

// Uses 3-way partitioning to handle sorts with large amounts of repeated values (ex. Year, MPG)
void ThreeWayPartition(vector<Car*>& list, int start, int end, string spec, int& LTEnd, int& GTStart) {
    // Select the first element to be the pivot.
    // Determine values less than, current, greater than pivot
    Car* pivotValue = list[start];
    int LTPivot = start;
    int currIndex = start;
    int GTPivot = end;

    // Swaps elements based on their relationship with pivot
    while (currIndex <= GTPivot) {
        // Less than pivot
        if (getVal(list[currIndex], spec) - getVal(pivotValue, spec) < 0) {
            swap(list[LTPivot], list[currIndex]);
            LTPivot++;
            currIndex++;
        }
        // Greater than pivot
        else if (getVal(list[currIndex], spec) - getVal(pivotValue, spec) > 0) {
            swap(list[currIndex], list[GTPivot]);
            GTPivot--;
        }
        // Equal to pivot
        else {
            currIndex++;
        }
    }

    // Adjusts bounds of partition for next call
    LTEnd = LTPivot - 1;
    GTStart = GTPivot + 1;
}