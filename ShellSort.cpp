//
// Created by tyler on 12/2/2024.
//

#include "ShellSort.h"
#include "GetVal.h"


void ShellSort(vector<Car*>& list, string spec){
    for(int gap = list.size()/2; gap > 0; gap /=2){
        for(int i = gap; i < list.size(); i++){
            int temp = getVal(list[i], spec);
            Car* tempIndex = list[i];
            int j;
            for(j = i; j >= gap && getVal(list[j-gap],spec) > temp; j -= gap){
                list[j] = list[j - gap];
            }
            list[j] = tempIndex;
        }
    }
};