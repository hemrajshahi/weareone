#include "FitnessApp.h"
#include <iostream>

void FitnessApp::bmiCalculator() {
    double weight, height;
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter height (m): ";
    std::cin >> height;

    double bmi = weight / (height * height);
    std::cout << "Your BMI is: " << bmi << std::endl;

    if (bmi < 18.5) {
        std::cout << "Category: Underweight" << std::endl;
    } else if (bmi < 24.9) {
        std::cout << "Category: Normal weight" << std::endl;
    } else if (bmi < 29.9) {
        std::cout << "Category: Overweight" << std::endl;
    } else {
        std::cout << "Category: Obesity" << std::endl;
    }
}

