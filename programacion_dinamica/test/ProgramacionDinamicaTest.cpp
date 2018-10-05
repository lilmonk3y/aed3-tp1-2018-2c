//
// Created by Christian nahuel Rivera on 25/09/2018.
//

#include "gtest/gtest.h"
#include "../src/ProgramacionDinamica.h"

struct PDtest : testing::Test {
    ProgramacionDinamica *programacionDinamica;

    PDtest(){
        this->programacionDinamica = new ProgramacionDinamica();
    }

    ~PDtest(){
        delete programacionDinamica;
    }
};

TEST_F(PDtest,whenIndexIsCeroAndValueIsNot_mustReturnINT_MAX){
    int elements[] = {4};
    int value = 7;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(PDtest,whenVisitingLastElementInElementsAndValueMinusThatElementIsCero_mustReturn1){
    int elements[] = {4};
    int value = 4;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(1, response);
}

TEST_F(PDtest,casoBorde_1){
    int elements[] = {0};
    int value = 0;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(1, response);
}

TEST_F(PDtest,casoBorde_2){
    int elements[] = {4};
    int value = 0;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(PDtest,whenArrayLengthIsBiggerThanOne_mustCallRecursivePath){
    int elements[] = {10,15,5,10,5};
    int value = 25;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(2, response);
}


TEST_F(PDtest,testingSubsets_1){
    int elements[] = {3,2,1,3,8};
    int value = 9;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(2, response);
}

TEST_F(PDtest,testingSubsets_2){
    int elements[] = {10,15,5,10,5};
    int value = 25;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(2, response);
}

TEST_F(PDtest,testingSubsets_3){
    int elements[] = {2,4,7,3,2,1};
    int value = 8;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(2, response);
}

TEST_F(PDtest,testingSubsets_4){
    int elements[] = {2,4,6,4,8,10,2};
    int value = 11;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(PDtest,testingSubsets_5){
    int elements[] = {40,20,22,10,9,8,6,15,30};
    int value = 57;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(3, response);
}

TEST_F(PDtest,testingSubsets_6){
    int elements[] = {10,2,6,8,4,14,2,2,13,1};
    int value = 14;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(1, response);
}

TEST_F(PDtest,testingSubsets_7){
    int elements[] = {2,6,4,8,10,12,2,8,6};
    int value = 13;
    std::vector<int> originalSet (elements, elements + sizeof(elements) / sizeof(int) );

    int response = programacionDinamica->execute(originalSet, value);

    ASSERT_EQ(INT_MAX, response);
}