#include "FitnessApp.h"
#include <iostream>

void FitnessApp::run() {
    if (!connectDatabase()) {
        std::cerr << "Failed to connect to database." << std::endl;
        return;
    }

    createTables();

    int choice;
    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    int option;
                    while (true) {
                        std::cout << "1. BMI Calculator\n2. Body Type Options\n3. Logout\nEnter your choice: ";
                        std::cin >> option;
                        if (option == 1) {
                            bmiCalculator();
                        } else if (option == 2) {
                            bodyTypeOptions();
                        } else if (option == 3) {
                            break;
                        } else {
                            std::cout << "Invalid option. Try again." << std::endl;
                        }
                    }
                }
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

bool FitnessApp::connectDatabase() {
    int rc = sqlite3_open("fitness_app.db", &db);
    return rc == SQLITE_OK;
}

void FitnessApp::createTables() {
    const char* sql = "CREATE TABLE IF NOT EXISTS users ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "username TEXT UNIQUE, "
                      "password TEXT);";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

