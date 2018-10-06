//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#ifndef TP1_GTEST_ESTRATEGIAFUERZABRUTA_H
#define TP1_GTEST_ESTRATEGIAFUERZABRUTA_H

#include <vector>
#include "Estrategia.h"

class EstrategiaFuerzaBruta : public Estrategia {
public:
    bool estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                              int partialSum);
};


#endif //TP1_GTEST_ESTRATEGIAFUERZABRUTA_H
