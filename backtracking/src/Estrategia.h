//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#ifndef TP1_GTEST_ESTRATEGIA_H
#define TP1_GTEST_ESTRATEGIA_H


class Estrategia {
public:
    virtual bool estrategiaDePoda(std::vector<int> originalSet, int objectiveValue, int index,
                                  std::vector<int> partialResult, int bestResult) = 0;
};


#endif //TP1_GTEST_ESTRATEGIA_H
