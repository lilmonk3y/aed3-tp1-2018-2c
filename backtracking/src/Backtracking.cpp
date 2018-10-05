//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#include "Backtracking.h"
#include <numeric>

int Backtracking::execute(std::vector<int> &elements, int objectValue) {
    std::vector<int> result;
    int responce = INT_MAX;
    minimoSubconjuntoQueSuma(elements,objectValue,0,result,responce);
    return responce;
}

int Backtracking::summation(std::vector<int> &vector) {
    int summation = 0;
    for (int index : vector)
        summation += index;

    return summation;
}

void Backtracking::minimoSubconjuntoQueSuma(std::vector<int> &originalSet, int &objectiveValue, int index,
                                            std::vector<int> partialResult, int &bestResult) {
    if(index == originalSet.size()){
        if(summation(partialResult) == objectiveValue && partialResult.size() < bestResult){
            bestResult = partialResult.size();
        }
    }else{
        if(this->estrategia->estrategiaDePoda(originalSet,objectiveValue,index,partialResult,bestResult)) return;

        minimoSubconjuntoQueSuma(originalSet,objectiveValue,index+1,partialResult,bestResult);

        partialResult.push_back(originalSet.at(index));
        minimoSubconjuntoQueSuma(originalSet,objectiveValue,index+1,partialResult,bestResult);
    }
    return;
}
