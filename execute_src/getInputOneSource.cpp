//
// Created by Christian nahuel Rivera on 04/10/2018.
//

#include <iostream>

int main(){
    int sizeOfArray;
    int objectiveValue;

    std::cout << "Pass values and objetive amount:" << std::endl;
    std::cin >> sizeOfArray;
    std::cin >> objectiveValue;

    std::cout << "Pass the " + std::to_string(sizeOfArray) + " values:" << std::endl;
    int elements[sizeOfArray];
    int value;
    for(int index = 0; index < sizeOfArray; index ++){
        std::cin >> value;
        elements[index] = value;
    }
    std::cout << "No more elements expected" << std::endl;
}
