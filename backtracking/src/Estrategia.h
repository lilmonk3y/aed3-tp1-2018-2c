//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#ifndef TP1_GTEST_ESTRATEGIA_H
#define TP1_GTEST_ESTRATEGIA_H


class Estrategia {
public:
    virtual bool estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int bestResult, int index, int partialResult,
                                      int partialSum, std::vector<int> &partialSummation) = 0;
};


#endif //TP1_GTEST_ESTRATEGIA_H
