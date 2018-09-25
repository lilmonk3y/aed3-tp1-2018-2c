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
    bool estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int index,
                          std::vector<int> partialResult, int bestResult);

    bool factibilidad(std::vector<int> &originalSet, std::vector<int> &partialResult,
                      int objectiveValue, int index);

    bool optimalidad(std::vector<int> partialResult, int objectiveValue, int bestResult);

    int summationFrom(std::vector<int> &vector, int index);
};


#endif //TP1_GTEST_ESTRATEGIABACKTRACKING_H
