//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#include "Backtracking.h"
#include <numeric>

int Backtracking::execute(std::vector<int> &elements, int objectValue) {
    int responce = INT_MAX;
    minimoSubconjuntoQueSuma(elements, objectValue, responce, 0, 0, 0);
    return responce;
}

int Backtracking::summation(std::vector<int> &vector) {
    int summation = 0;
    for (int index : vector)
        summation += index;

    return summation;
}

void Backtracking::minimoSubconjuntoQueSuma(std::vector<int> &originalSet, int &objectiveValue, int &bestResult, int index,
                                            int partialResult, int partialSum) {
    if(index == originalSet.size()){
        if(partialSum == objectiveValue && partialResult < bestResult){
            bestResult = partialResult;
        }
    }else{
        if(this->estrategia->estrategiaDePoda(originalSet, objectiveValue, bestResult, index, partialResult, partialSum)) return;

        minimoSubconjuntoQueSuma(originalSet, objectiveValue, bestResult, index + 1, partialResult, partialSum);

        partialSum += originalSet.at(index);
        minimoSubconjuntoQueSuma(originalSet, objectiveValue, bestResult, index + 1, partialResult+1, partialSum);
    }
    return;
}
