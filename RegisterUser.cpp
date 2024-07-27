#include "FitnessApp.h"
#include <iostream>

void FitnessApp::registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::string sql = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "');";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "User registered successfully!" << std::endl;
    }
}

