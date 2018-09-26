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

    int response = programacionDinamica->execute(elements,value, sizeof(elements));

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(PDtest,whenVisitingLastElementInElementsAndValueMinusThatElementIsCero_mustReturn1){
    int elements[] = {4};
    int value = 4;

    int response = programacionDinamica->execute(elements,value, sizeof(elements));

    ASSERT_EQ(1, response);
}

TEST_F(PDtest,casoBorde_1){
    int elements[] = {0};
    int value = 0;

    int response = programacionDinamica->execute(elements,value, sizeof(elements));

    ASSERT_EQ(1, response);
}

TEST_F(PDtest,casoBorde_2){
    int elements[] = {4};
    int value = 0;

    int response = programacionDinamica->execute(elements,value, sizeof(elements));

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(PDtest,whenArrayLengthIsBiggerThanOne_mustCallRecursivePath){
    int elements[] = {10,15,5,10,5};
    int value = 25;

    int response = programacionDinamica->execute(elements,value, sizeof(elements));

    ASSERT_EQ(2, response);
}