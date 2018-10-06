//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#ifndef TP1_GTEST_BACKTRACKING_H
#define TP1_GTEST_BACKTRACKING_H

#include <vector>
#include <string>
#include "Estrategia.h"

class Backtracking {
public:
    Backtracking(Estrategia *estrategia){
        this->estrategia = estrategia;
    }
    ~Backtracking(){
    }


    int execute(std::vector<int> &elements, int objectValue);

    void minimoSubconjuntoQueSuma(std::vector<int> &originalSet, int &objectiveValue, int &bestResult, int index,
                                      int partialResult, int partialSum);

    static int summation(std::vector<int> &vector);
private:
    Estrategia *estrategia;
};


#endif //TP1_GTEST_BACKTRACKING_H
