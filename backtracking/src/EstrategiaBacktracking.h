//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#ifndef TP1_GTEST_ESTRATEGIABACKTRACKING_H
#define TP1_GTEST_ESTRATEGIABACKTRACKING_H

#include <vector>
#include "Estrategia.h"
#include "Backtracking.h"
class EstrategiaBacktracking : public Estrategia{
public:
    bool estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                              int partialSum, std::vector<int> &partialSummation);

    bool factibilidad(std::vector<int> &originalSet, int objectiveValue, int index, int partialResult,
                          int partialSum, std::vector<int> &partialSummation);

    bool optimalidad(std::vector<int> &originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                         int partialSum);

};


#endif //TP1_GTEST_ESTRATEGIABACKTRACKING_H
