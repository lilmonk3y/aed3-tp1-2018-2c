//
// Created by Christian nahuel Rivera on 25/09/2018.
//

#ifndef TP1_GTEST_PROGRAMACIONDINAMICA_H
#define TP1_GTEST_PROGRAMACIONDINAMICA_H


class ProgramacionDinamica {
public:
    unsigned int execute(int elements[], int objectiveValue, int sizeOfElements);

    unsigned int minimoConjuntoQueSuma(unsigned long index, int partialValue, std::vector<int> originalSet,
                                       std::vector<std::vector<unsigned int>> solutions);

    void initialize(std::vector<std::vector<unsigned int>> &vector, unsigned long indexX, int indexY);

    const unsigned int & recursivePath(unsigned long index, int partialValue, std::vector<int> &originalSet,
                                       const std::vector<std::vector<unsigned int>> &solutions);
};


#endif //TP1_GTEST_PROGRAMACIONDINAMICA_H
