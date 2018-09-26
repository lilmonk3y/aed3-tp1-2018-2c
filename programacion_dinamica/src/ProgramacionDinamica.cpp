//
// Created by Christian nahuel Rivera on 25/09/2018.
//

#include <climits>
#include <vector>
#include "ProgramacionDinamica.h"

unsigned int ProgramacionDinamica::execute(int *elements, int objectiveValue, int sizeOfElements) {
    std::vector<int> originalSet (elements, elements + sizeOfElements / sizeof(int) );
    std::vector<std::vector<unsigned int>> solutions;
    initialize(solutions,originalSet.size(),objectiveValue+1);
    unsigned long responseIndex = originalSet.size() - 1;
    return minimoConjuntoQueSuma(responseIndex, objectiveValue, originalSet, solutions);
}

unsigned int ProgramacionDinamica::minimoConjuntoQueSuma(unsigned long index, int partialValue,
                                                         std::vector<int> originalSet,
                                                         std::vector<std::vector<unsigned int>> solutions) {
    if(solutions.at(index).at(partialValue) == INT_MIN){
        if(index > 0 and partialValue > 0){
            solutions.at(index).at(partialValue) = recursivePath(index, partialValue, originalSet, solutions);
        } else if( partialValue == 0 && index > 0){
            solutions.at(index).at(partialValue) = 0;
        } else if(index==0 && (partialValue - originalSet.at(index)) == 0){
            solutions.at(index).at(partialValue) = 1;
        }else{
            solutions.at(index).at(partialValue) = INT_MAX;
        }
    }
    return solutions.at(index).at(partialValue);
}

const unsigned int & ProgramacionDinamica::recursivePath(unsigned long index, int partialValue,
                                                         std::vector<int> &originalSet,
                                                         const std::vector<std::vector<unsigned int>> &solutions) {
    return std::__1::min(minimoConjuntoQueSuma(index - 1, partialValue, originalSet, solutions),
                         (partialValue - originalSet.at(index) < 0) ?
                             INT_MAX :
                             minimoConjuntoQueSuma(index - 1, partialValue - originalSet.at(index) , originalSet, solutions) + 1);
}

void ProgramacionDinamica::initialize(std::vector<std::vector<unsigned int>> &vector, unsigned long indexX, int indexY) {
    vector.resize(indexX);
    for(int x = 0; x < indexX; x++){
        vector.at(x).resize(indexY);
    }
    for(int x = 0; x < indexX; x++){
        for(int y = 0; y < indexY; y++){
            vector.at(x).at(y) = INT_MIN;
        }
    }
}
