//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#include "EstrategiaBacktracking.h"

bool EstrategiaBacktracking::estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int index,
                                              std::vector<int> partialResult, int bestResult) {
    bool fact = factibilidad(originalSet, partialResult, objectiveValue, index);
    bool opt = optimalidad(partialResult, objectiveValue, bestResult);
    return fact || opt;
    //return factibilidad(originalSet, partialResult, objectiveValue, index) || optimalidad(partialResult, objectiveValue, bestResult);
}

bool
EstrategiaBacktracking::factibilidad(std::vector<int> &originalSet, std::vector<int> &partialResult,
                                     int objectiveValue, int index) {
    bool condicion1 = Backtracking::summation(partialResult) > objectiveValue;
    bool condicion2 = Backtracking::summation(partialResult) + summationFrom(originalSet,index) < objectiveValue;
    return condicion1 || condicion2;
}

bool EstrategiaBacktracking::optimalidad(std::vector<int> partialResult, int objectiveValue, int bestResult) {
    return false;
}

int EstrategiaBacktracking::summationFrom(std::vector<int> &vector, int index) {
    int result = 0;
    for(int indice = index;indice < vector.size();indice++){
        result = result + vector.at(indice);
    }
    return result;
}
