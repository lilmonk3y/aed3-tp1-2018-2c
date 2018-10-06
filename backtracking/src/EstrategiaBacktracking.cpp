//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#include "EstrategiaBacktracking.h"

bool EstrategiaBacktracking::estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                                              int partialSum) {
    bool fact = factibilidad(originalSet, objectiveValue, index, partialResult, partialSum);
    bool opt = optimalidad(originalSet, objectiveValue, bestResult, index, partialResult, partialSum);
    return fact || opt;
    //return factibilidad(originalSet, partialResult, objectiveValue, index) || optimalidad(partialResult, objectiveValue, bestResult);
}

bool
EstrategiaBacktracking::factibilidad(std::vector<int> &originalSet, int objectiveValue, int index, int partialResult, int partialSum) {
    bool condicion1 = partialSum > objectiveValue;
    bool condicion2 = partialSum + summationFrom(originalSet,index) < objectiveValue;
    return condicion1 || condicion2;
}

bool
EstrategiaBacktracking::optimalidad(std::vector<int> &originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                                    int partialSum) {
    return  partialResult   >= bestResult;
}

int EstrategiaBacktracking::summationFrom(std::vector<int> &vector, int index) {
    int result = 0;
    for(int indice = index;indice < vector.size();indice++){
        result = result + vector.at(indice);
    }
    return result;
}
