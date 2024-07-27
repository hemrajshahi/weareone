#include "FitnessApp.h"
#include "Ectomorph.h"
#include "Mesomorph.h"
#include "Endomorph.h"
#include <iostream>

void FitnessApp::bodyTypeOptions() {
    std::string bodyType;
    int option;
    bool validBodyType = false;

    while (true) {
        if (!validBodyType) {
            std::cout << "Choose your body type (ectomorph, mesomorph, endomorph): ";
            std::cin >> bodyType;

            if (bodyType == "ectomorph" || bodyType == "mesomorph" || bodyType == "endomorph") {
                validBodyType = true;  // Set flag to true if body type is valid
            } else {
                std::cout << "Invalid body type." << std::endl;
                continue;  // Restart the loop to ask for body type again
            }
        }

        std::cout << "1. Characteristics\n2. Nutrients and Diets\n3. Exercises\nEnter your choice: ";
        std::cin >> option;

        if (bodyType == "ectomorph") {
            Ectomorph ecto;
            switch (option) {
                case 1:
                    ecto.characteristics();
                    break;
                case 2:
                    ecto.nutrientsAndDiet();
                    break;
                case 3:
                    ecto.exercises();
                    std::cout << "Enter exercise name for details or 'exit' to go back: ";
                    {
                        std::string exerciseName;
                        std::cin.ignore();
                        std::getline(std::cin, exerciseName);
                        if (exerciseName != "exit") {
                            ecto.showExerciseDetails(exerciseName);
                        }
                    }
                    break;
                default:
                    std::cout << "Invalid option." << std::endl;
            }
        } else if (bodyType == "mesomorph") {
            Mesomorph meso;
            switch (option) {
                case 1:
                    meso.characteristics();
                    break;
                case 2:
                    meso.nutrientsAndDiet();
                    break;
                case 3:
                    meso.exercises();
                    std::cout << "Enter exercise name for details or 'exit' to go back: ";
                    {
                        std::string exerciseName;
                        std::cin.ignore();
                        std::getline(std::cin, exerciseName);
                        if (exerciseName != "exit") {
                            meso.showExerciseDetails(exerciseName);
                        }
                    }
                    break;
                default:
                    std::cout << "Invalid option." << std::endl;
            }
        } else if (bodyType == "endomorph") {
            Endomorph endo;
            switch (option) {
                case 1:
                    endo.characteristics();
                    break;
                case 2:
                    endo.nutrientsAndDiet();
                    break;
                case 3:
                    endo.exercises();
                    std::cout << "Enter exercise name for details or 'exit' to go back: ";
                    {
                        std::string exerciseName;
                        std::cin.ignore();
                        std::getline(std::cin, exerciseName);
                        if (exerciseName != "exit") {
                            endo.showExerciseDetails(exerciseName);
                        }
                    }
                    break;
                default:
                    std::cout << "Invalid option." << std::endl;
            }
        }

        char choice;
        std::cout << "Do you want to continue with this body type (y/n)? ";
        std::cin >> choice;
        if (choice == 'n' || choice == 'N') {
            std::cout << "Exiting the program..." << std::endl;
            exit(0);  // Exit the program completely
        }
        // If choice is 'y', continue in the same loop with the same body type
    }
}

