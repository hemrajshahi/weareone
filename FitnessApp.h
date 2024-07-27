#ifndef FITNESS_APP_H
#define FITNESS_APP_H

#include <sqlite3.h>
#include <string>

class FitnessApp {
public:
    void run();

private:
    void registerUser();
    bool loginUser();
    void bmiCalculator();
    void bodyTypeOptions();
    void displayOptions();
    bool connectDatabase();
    void createTables();

    sqlite3* db;
};

#endif // FITNESS_APP_H

