//
// Created by Christian nahuel Rivera on 04/10/2018.
//

#include <iostream>
#include <array>
#include "../backtracking/src/Backtracking.h"
#include "../backtracking/src/EstrategiaFuerzaBruta.h"

int callSolution(int elements[], int objectiveValue, int size){
    Backtracking *backtracking = new Backtracking(new EstrategiaFuerzaBruta());
    int response = backtracking->execute(elements,objectiveValue,size);
    if( response == INT_MAX){
        response = -1;
    }
    return response;
}

int main(){

    int sizeOfArray;
    int objectiveValue;
    std::cout << "Pass sets of values and finally 0 0 for expresing end of values." << std::endl;
    std::cin >> sizeOfArray;
    std::cin >> objectiveValue;
    while(sizeOfArray != 0 && objectiveValue != 0){
        std::array<int,sizeOfArray> elements;
        int value;
        for(int index = 0; index < sizeOfArray; index ++){
            std::cin >> value;
            elements[index] = value;
        }

        std::cout << callSolution(elements,objectiveValue,sizeOfArray) << std::endl;

        std::cin >> sizeOfArray;
        std::cin >> objectiveValue;
    }

    std::cout << "No more elements expected" << std::endl;
}