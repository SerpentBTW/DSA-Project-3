//
// Created by tyler on 12/2/2024.
//

#include "ShellSort.h"
#include "GetVal.h"


void ShellSort(vector<Car*>& list, string spec){
    //Create gap size and loop through gap size is 0
    for(int gap = list.size()/2; gap > 0; gap /=2){
        //Do gapped insertion sort
        for(int i = gap; i < list.size(); i++){
            //Store the ith Value and node's pointer.
            int temp = getVal(list[i], spec);
            Car* tempIndex = list[i];
            int j;
            //Compare and insert when needed.
            for(j = i; j >= gap && getVal(list[j-gap],spec) > temp; j -= gap){
                list[j] = list[j - gap];
            }
            list[j] = tempIndex;
        }
    }
};