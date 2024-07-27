#include "FitnessApp.h"
#include <iostream>

bool FitnessApp::loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::string sql = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    rc = sqlite3_step(stmt);
    bool loginSuccess = (rc == SQLITE_ROW);
    sqlite3_finalize(stmt);

    if (loginSuccess) {
        std::cout << "Login successful!" << std::endl;
	std::cout << "\nWelcome back, " << username << "!\n";
       	std::cout << "Let's get started on your journey to a healthier, stronger you.\n";
	std::cout << "Remember, every great achievement begins with the decision to try.\n";
	std::cout << "Let's make today count!\n\n";
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return loginSuccess;
}

