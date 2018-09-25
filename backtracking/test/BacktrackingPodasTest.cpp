//
// Created by Christian nahuel Rivera on 23/09/2018.
//

#include "gtest/gtest.h"
#include "../src/EstrategiaBacktracking.h"

struct PodasTest : testing::Test {
    PodasTest(){
        podas = new EstrategiaBacktracking();
    }

    ~PodasTest(){
        delete podas;
    }
    EstrategiaBacktracking *podas;
};

TEST_F(PodasTest,whenPartialResultSummationIsBiggerThanObjectiveValue_mustReturnTrue){
    std::vector<int> originalSet;
    int objectiveValue = 10;
    int elements2[] = {6,5,4};
    std::vector<int> partialResult(elements2, elements2 + sizeof(elements2) / sizeof(int) );
    int bestResult;
    int index;

    bool resultado = podas->estrategiaDePoda(originalSet,objectiveValue,index,partialResult,bestResult);

    ASSERT_EQ(true,resultado);
}

TEST_F(PodasTest,whenPartialResultSummationIsSmallerThanObjectiveValue_mustReturnFalse){
    int elements[] = {10,9,8,7};
    std::vector<int> originalSet(elements, elements + sizeof(elements) / sizeof(int) );
    int objectiveValue = 10;
    int elements2[] = {7};
    std::vector<int> partialResult(elements2, elements2 + sizeof(elements2) / sizeof(int) );
    int bestResult = 10;
    int index = 3;

    bool resultado = podas->estrategiaDePoda(originalSet,objectiveValue,index,partialResult,bestResult);

    ASSERT_EQ(false,resultado);
}


TEST_F(PodasTest,whenSummationOfPartialResultPlusNextElementsInOriginalSetAreSmallerThanObjectiveValue_mustReturnTrue){
    int elements[] = {1,2,3,4,5,6};
    std::vector<int> originalSet(elements, elements + sizeof(elements) / sizeof(int) );
    int objectiveValue = 20;
    int elements2[] = {3,4};
    std::vector<int> partialResult(elements2, elements2 + sizeof(elements2) / sizeof(int) );
    int bestResult = 3;
    int index = 4;

    bool resultado = podas->estrategiaDePoda(originalSet,objectiveValue,index,partialResult,bestResult);

    ASSERT_EQ(true,resultado);
}

TEST_F(PodasTest,test_summationFrom1){
    int elements[] = {3,2,1,3,8};
    std::vector<int> originalSet(elements, elements + sizeof(elements) / sizeof(int) );
    int index = 3;

    int resultado = podas->summationFrom(originalSet,index);

    ASSERT_EQ(11,resultado);
}

TEST_F(PodasTest,test_summationFrom2){
    int elements[] = {3,2,1,3,8};
    std::vector<int> originalSet(elements, elements + sizeof(elements) / sizeof(int) );
    int index = 1;

    int resultado = podas->summationFrom(originalSet,index);

    ASSERT_EQ(14,resultado);
}