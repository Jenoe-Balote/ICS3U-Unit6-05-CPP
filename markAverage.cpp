// Copyright (c) 2021 Jenoe Balote All rights reserved
//
// Created by Jenoe Balote
// Created on June 2021
// this program averages out marks inputted by the user

#include <iostream>
#include <iomanip>
#include <list>
#include <cmath>

float CalculateAverage(std::list<int> marksList) {
    // this function calculates the average

    float listSum = 0;
    float average;

    for (int mark : marksList) {
        listSum = listSum + mark;
    }
    average = listSum / marksList.size();

    return average;
}

main() {
    // this function collects the marks

    std::string markString;
    int markInteger;
    float average;
    std::list<int> markList;

    // input and process
    std::cout << "Let's calculate an average mark!"<< std::endl;
    std::cout << "Enter marks one by one (0 is the lowest, "
                                          "100 is the highest)" << std::endl;
    std::cout << "Enter -1 once you are done." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter a mark (%): ";
    std::cin >> markString;
    while (true) {
        try {
            markInteger = std::stoi(markString);

            if (markInteger == -1) {
                break;
            } else if (markInteger < 0 || markInteger > 100) {
                std::cout << "Invalid. Enter a mark (%): ";
                std::cin >> markString;
            } else {
                std::cout << "Enter a mark (%): ";
                std::cin >> markString;
                markList.push_back(markInteger);
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid. Enter a mark (%): ";
                std::cin >> markString;
        }
    }

    // call function(s)
    average = CalculateAverage(markList);

    // output
    // source used for rounding numbers in cpp:
    // https://www.tutorialspoint.com/round-in-cplusplus#:~:text=The%20round()
    //     %20function%20in,cmath%3E%20or%20.
    std::cout << "\nThe average is: " << round(average) << "%" << std::endl;
    std::cout << "\nThanks for participating!" << std::endl;
}
