//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#include "Backtracking.h"
#include <numeric>

int Backtracking::execute(std::vector<int> &elements, int objectValue) {
    int responce = INT_MAX;
    std::vector<int> summationForNext;
    summationForNext.resize(elements.size());
    for(int index = 0;index < elements.size();index++){
        summationForNext.at(index) = summationFrom(elements,index);
    }
    minimoSubconjuntoQueSuma(elements, objectValue, responce, 0, 0, 0, summationForNext);
    return responce;
}

int Backtracking::summation(std::vector<int> &vector) {
    int summation = 0;
    for (int index : vector)
        summation += index;

    return summation;
}

int Backtracking::summationFrom(std::vector<int> &vector, int index) {
    int result = 0;
    for(int indice = index;indice < vector.size();indice++){
        result = result + vector.at(indice);
    }
    return result;
}

void Backtracking::minimoSubconjuntoQueSuma(std::vector<int> &originalSet, int &objectiveValue, int &bestResult, int index,
                                            int partialResult, int partialSum, std::vector<int> &partialSummation) {
    if(index == originalSet.size()){
        if(partialSum == objectiveValue && partialResult < bestResult){
            bestResult = partialResult;
        }
    }else{
        if(this->estrategia->estrategiaDePoda(originalSet, objectiveValue, bestResult, index, partialResult, partialSum,
                                              partialSummation)) return;

        minimoSubconjuntoQueSuma(originalSet, objectiveValue, bestResult, index + 1, partialResult, partialSum,
                                 partialSummation);

        partialSum += originalSet.at(index);
        minimoSubconjuntoQueSuma(originalSet, objectiveValue, bestResult, index + 1, partialResult + 1, partialSum,
                                 partialSummation);
    }
    return;
}
