//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#include "Backtracking.h"
#include <numeric>

int Backtracking::execute(int elements[], int objectValue, int sizeOfElements) {
    std::vector<int> originalSet (elements, elements + sizeOfElements / sizeof(int) );
    std::vector<int> result;
    int noResponce = INT_MAX;
    return minimoSubconjuntoQueSuma(originalSet,objectValue,0,result,noResponce);
}

bool Backtracking::summationEqualsTo(std::vector<int> vector, int value) {
    int summation = 0;
    for (int index : vector)
        summation += index;

    return summation == value;
}

int Backtracking::minimoSubconjuntoQueSuma(std::vector<int> originalSet, int objectiveValue, int index,
                                           std::vector<int> partialResult, int &bestResult) {
    if(index == originalSet.size()){
        if(summationEqualsTo(partialResult, objectiveValue) && partialResult.size() < bestResult){
            bestResult = partialResult.size();
        }
    }else{
        if( this->estrategia->estrategiaDePoda() ) return INT_MAX;

        minimoSubconjuntoQueSuma(originalSet,objectiveValue,index+1,partialResult,bestResult);

        partialResult.push_back(originalSet.at(index));
        minimoSubconjuntoQueSuma(originalSet,objectiveValue,index+1,partialResult,bestResult);
    }
    return bestResult;
}
