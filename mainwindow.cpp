#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Initialize the database
    initializeDatabase();



    // Ensure the initial page is set to login
    ui->stackedWidget->setCurrentWidget(ui->loginpage);

    // Connect the buttons to their respective slots
    connect(ui->login, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->signup, &QPushButton::clicked, this, &MainWindow::on_signupButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::on_registerButton_clicked);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
    connect(ui->next, &QPushButton::clicked, this, &MainWindow::on_nextButton_clicked); // Connect next button
    connect(ui->backtobmi, &QPushButton::clicked, this, &MainWindow::on_backtobmiButton_clicked); // Connect next button
    connect(ui->ectomorph, &QPushButton::clicked, this, &MainWindow::on_ectomorphButton_clicked);
    connect(ui->mesomorph, &QPushButton::clicked, this, &MainWindow::on_mesomorphButton_clicked);
    connect(ui->endomorph, &QPushButton::clicked, this, &MainWindow::on_endomorphButton_clicked);


    // Connect Ectomorphfeatures buttons
    connect(ui->Ectocharacteristics, &QPushButton::clicked, this, &MainWindow::on_EctomorphcharacteristicsButton_clicked);
    connect(ui->Ectonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_EctomorphnutritionAndDietButton_clicked);
    connect(ui->Ectoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_EctomorphexerciseAndWorkoutButton_clicked);

    // Connect Endomorphfeatures buttons
    connect(ui->Endocharacteristics, &QPushButton::clicked, this, &MainWindow::on_EndomorphcharacteristicsButton_clicked);
    connect(ui->Ectonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_EndomorphnutritionAndDietButton_clicked);
    connect(ui->Endoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_EndomorphexerciseAndWorkoutButton_clicked);

    // Connect Mesomorphfeatures buttons
    connect(ui->Mesocharacteristics, &QPushButton::clicked, this, &MainWindow::on_MesomorphcharacteristicsButton_clicked);
    connect(ui->Mesonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_MesomorphnutritionAndDietButton_clicked);
    connect(ui->Mesoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_MesomorphexerciseAndWorkoutButton_clicked);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_data.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "firstname TEXT, "
                    "lastname TEXT, "
                    "email TEXT UNIQUE, "
                    "password TEXT)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS bmi_data ("
                    "user_id INTEGER, "
                    "weight REAL, "
                    "height REAL, "
                    "bmi REAL, "
                    "FOREIGN KEY(user_id) REFERENCES users(id))")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    qDebug() << "Attempting login with username:" << username << "and password:" << password;
    qDebug() << "Stored username:" << generatedUsername;

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Username and password cannot be empty.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE firstname || lastname = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Login Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        ui->stackedWidget->setCurrentWidget(ui->bmipage);
        currentUserId = query.value("id").toInt(); // Store current user's ID for BMI calculations
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::on_signupButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->RegisterPage);
}
void MainWindow::on_registerButton_clicked()
{
    QString firstname = ui->firstname->text().trimmed();
    QString lastname = ui->lastname->text().trimmed();
    QString email = ui->email->text().trimmed();
    QString password = ui->password_2->text().trimmed();
    QString confirmPassword = ui->confirm->text().trimmed();

    qDebug() << "Registering with firstname:" << firstname << "lastname:" << lastname;

    // Use a static regular expression for name validation
    static const QRegularExpression nameRegex("^[a-zA-Z]+$");
    bool firstNameValid = nameRegex.match(firstname).hasMatch();
    bool lastNameValid = nameRegex.match(lastname).hasMatch();

    qDebug() << "Name validation results:" << "Firstname valid:" << firstNameValid << "Lastname valid:" << lastNameValid;

    if (!firstNameValid || !lastNameValid) {
        QMessageBox::warning(this, "Registration Failed", "First and last names should contain only letters.");
        return; // Exit the function if validation fails
    }

    // Validate the email format
    if (!email.endsWith("@gmail.com")) {
        qDebug() << "Email validation failed";
        QMessageBox::warning(this, "Registration Failed", "Email must be a valid @gmail.com address.");
        return; // Exit the function if validation fails
    }

    // Validate password match
    if (password != confirmPassword) {
        qDebug() << "Password match failed";
        QMessageBox::warning(this, "Registration Failed", "Passwords do not match.");
        return; // Exit the function if validation fails
    }

    // Generate the username
    generatedUsername = firstname + lastname;
    qDebug() << "Generated username:" << generatedUsername;

    // Insert user data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO users (firstname, lastname, email, password) VALUES (?, ?, ?, ?)");
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(email);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Database insertion failed:" << query.lastError().text();
        QMessageBox::critical(this, "Registration Failed", query.lastError().text());
        return; // Exit the function if the query execution fails
    }

    // Show success message
    QMessageBox::information(this, "Registration Successful", "You are now registered!\nYour username is: " + generatedUsername);

    // Clear the registration fields
    ui->firstname->clear();
    ui->lastname->clear();
    ui->email->clear();
    ui->password_2->clear();
    ui->confirm->clear();

    // Switch back to the login page
    ui->stackedWidget->setCurrentWidget(ui->loginpage);
}



void MainWindow::on_calculateButton_clicked()
{
    bool weightOk, heightOk;
    double weight = ui->weight->text().toDouble(&weightOk);
    double heightCm = ui->height->text().toDouble(&heightOk);

    if (!weightOk || !heightOk || weight <= 0 || heightCm <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter valid positive numbers for weight and height.");
        ui->bmiresult->setText("Invalid input");
        return;
    }

    double heightM = heightCm / 100.0; // Convert height from centimeters to meters

    double bmi = weight / (heightM * heightM); // Calculate BMI

    qDebug() << "Weight:" << weight << "Height (m):" << heightM << "BMI:" << bmi;

    QString category;
    if (bmi < 18.5) {
        category = "Underweight";
    } else if (bmi < 24.9) {
        category = "Normal weight";
    } else if (bmi < 29.9) {
        category = "Overweight";
    } else {
        category = "Obesity";
    }

    ui->bmiresult->setText("Your BMI is: " + QString::number(bmi, 'f', 2) + "\nCategory: " + category);

    // Store BMI data in the database
    QSqlQuery query;
    query.prepare("INSERT INTO bmi_data (user_id, weight, height, bmi) VALUES (?, ?, ?, ?)");
    query.addBindValue(currentUserId);
    query.addBindValue(weight);
    query.addBindValue(heightM); // Store height in meters
    query.addBindValue(bmi);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to store BMI data: " + query.lastError().text());
        return;
    }
}

void MainWindow::on_nextButton_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->bodytypes);
}

void MainWindow::on_ectomorphButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphfeatures);
}

void MainWindow::on_mesomorphButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphfeatures);
}

void MainWindow::on_endomorphButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Endomorphfeatures);
}

void MainWindow::on_backtobmiButton_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->bmipage);
}

// Slot for Characteristics button
void MainWindow::on_EctomorphcharacteristicsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Ectomorph);
}

// Slot for Nutrition and Diet button
void MainWindow::on_EctomorphnutritionAndDietButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphnutrients);
}

// Slot for Exercise and Workout button
void MainWindow::on_EctomorphexerciseAndWorkoutButton_clicked()
{
    // Logic to open the Exercise and Workout page
    // Implement navigation to the corresponding QWidget here
}


// Slot for Characteristics button
void MainWindow::on_EndomorphcharacteristicsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Endomorph);
}

// Slot for Nutrition and Diet button
void MainWindow::on_EndomorphnutritionAndDietButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Endomorphnutrients);
}

// Slot for Exercise and Workout button
void MainWindow::on_EndomorphexerciseAndWorkoutButton_clicked()
{
    // Logic to open the Exercise and Workout page
    // Implement navigation to the corresponding QWidget here
}


// Slot for Characteristics button
void MainWindow::on_MesomorphcharacteristicsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Mesomorph);
}

// Slot for Nutrition and Diet button
void MainWindow::on_MesomorphnutritionAndDietButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphnutrients);
}

// Slot for Exercise and Workout button
void MainWindow::on_MesomorphexerciseAndWorkoutButton_clicked()
{
    // Logic to open the Exercise and Workout page
    // Implement navigation to the corresponding QWidget here
}


