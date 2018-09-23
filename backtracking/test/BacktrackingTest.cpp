//
// Created by Christian nahuel Rivera on 22/09/2018.
//

#include "gtest/gtest.h"
#include "../src/Backtracking.h"
#include "../src/EstrategiaFuerzaBruta.h"
#include "../src/EstrategiaBacktracking.h"

struct BacktrackingTest : testing::Test{
    Backtracking *backtracking;
    BacktrackingTest(){
        backtracking = new Backtracking(new EstrategiaFuerzaBruta());
    }
    ~BacktrackingTest(){
        delete backtracking;
    }
};

TEST_F(BacktrackingTest,whenCantGetSubSet_mustReturnINT_MAX){
    int elements[] = {4,6,2,8,0};
    int value = 7;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(BacktrackingTest,whenOneElementIsEqualsToTheValue_mustReturn1){
    int elements[] = {7};
    int value = 7;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(1, response);
}

TEST_F(BacktrackingTest,whenASubsetSubIsEqualsToTheValue_mustReturnItsSize){
    int elements[] = {4,3,4};
    int value = 8;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(2, response);
}

TEST_F(BacktrackingTest,whenTwoSubsetsAreEqualsToTheValue_mustReturnTheSizeOfTheSmallerOne){
    int elements[] = {4,3,4,8};
    int value = 8;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(1, response);
}

TEST_F(BacktrackingTest,testingSubsets_1){
    int elements[] = {3,2,1,3,8};
    int value = 9;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(2, response);
}

TEST_F(BacktrackingTest,testingSubsets_2){
    int elements[] = {10,15,5,10,5};
    int value = 25;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(2, response);
}

TEST_F(BacktrackingTest,testingSubsets_3){
    int elements[] = {2,4,7,3,2,1};
    int value = 8;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(2, response);
}

TEST_F(BacktrackingTest,testingSubsets_4){
    int elements[] = {2,4,6,4,8,10,2};
    int value = 11;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(INT_MAX, response);
}

TEST_F(BacktrackingTest,testingSubsets_5){
    int elements[] = {40,20,22,10,9,8,6,15,30};
    int value = 57;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(3, response);
}

TEST_F(BacktrackingTest,testingSubsets_6){
    int elements[] = {10,2,6,8,4,14,2,2,13,1};
    int value = 14;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(1, response);
}

TEST_F(BacktrackingTest,testingSubsets_7){
    int elements[] = {2,6,4,8,10,12,2,8,6};
    int value = 13;

    int response = backtracking->execute(elements,value, sizeof(elements));

    ASSERT_EQ(INT_MAX, response);
}