//
// Created by Christian nahuel Rivera on 05/10/2018.
//


#include <iostream>
#include <array>
#include "../backtracking/src/Backtracking.h"
#include "../backtracking/src/EstrategiaBacktracking.h"

int callSolution(std::vector<int> &elements, int objectiveValue) {
    Backtracking *backtracking = new Backtracking(new EstrategiaBacktracking());
    int response = backtracking->execute(elements, objectiveValue);
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
        std::vector<int> elements;
        elements.resize(sizeOfArray);
        int value;
        for(int index = 0; index < sizeOfArray; index ++){
            std::cin >> value;
            elements.at(index) = value;
        }

        std::cout << callSolution(elements, objectiveValue) << std::endl;

        std::cin >> sizeOfArray;
        std::cin >> objectiveValue;
    }

    std::cout << "No more elements expected" << std::endl;
}
