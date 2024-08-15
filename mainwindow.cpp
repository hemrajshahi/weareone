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

    //ectomorph button
    connect(ui->home1, &QPushButton::clicked, this, &MainWindow::on_home1button_clicked); // Connect home button
    connect(ui->backecto, &QPushButton::clicked, this, &MainWindow::on_backtoectobutton_clicked); // Connect backtoecto button
    connect(ui->back1, &QPushButton::clicked, this, &MainWindow::on_back1button_clicked); // Connect back1 button
    connect(ui->back4, &QPushButton::clicked, this, &MainWindow::on_back4button_clicked); // Connect back1 button
    connect(ui->back5, &QPushButton::clicked, this, &MainWindow::on_back5button_clicked); // Connect back1 button


    //endomorph button
    connect(ui->home2, &QPushButton::clicked, this, &MainWindow::on_home2button_clicked); // Connect home button
    connect(ui->backendo, &QPushButton::clicked, this, &MainWindow::on_backtoendobutton_clicked); // Connect backtoecto button
    connect(ui->back2, &QPushButton::clicked, this, &MainWindow::on_back2button_clicked); // Connect back button
    connect(ui->back6, &QPushButton::clicked, this, &MainWindow::on_back6button_clicked); // Connect back1 button
    connect(ui->back8, &QPushButton::clicked, this, &MainWindow::on_back8button_clicked); // Connect back1 button



    //Mesomorph button
    connect(ui->home3, &QPushButton::clicked, this, &MainWindow::on_home3button_clicked); // Connect home button
    connect(ui->backmeso, &QPushButton::clicked, this, &MainWindow::on_backtomesobutton_clicked); // Connect backtoecto button
    connect(ui->back3, &QPushButton::clicked, this, &MainWindow::on_back3button_clicked); // Connect back button
    connect(ui->back7, &QPushButton::clicked, this, &MainWindow::on_back7button_clicked); // Connect back1 button
    connect(ui->back9, &QPushButton::clicked, this, &MainWindow::on_back9button_clicked); // Connect back1 button



    // Connect Ectomorphfeatures buttons
    connect(ui->Ectocharacteristics, &QPushButton::clicked, this, &MainWindow::on_EctomorphcharacteristicsButton_clicked);
    connect(ui->Ectonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_EctomorphnutritionAndDietButton_clicked);
    connect(ui->Ectoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_EctomorphexerciseAndWorkoutButton_clicked);

    // Connect Endomorphfeatures buttons
    connect(ui->Endocharacteristics, &QPushButton::clicked, this, &MainWindow::on_EndomorphcharacteristicsButton_clicked);
    connect(ui->Endonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_EndomorphnutritionAndDietButton_clicked);
    connect(ui->Endoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_EndomorphexerciseAndWorkoutButton_clicked);

    // Connect Mesomorphfeatures buttons
    connect(ui->Mesocharacteristics, &QPushButton::clicked, this, &MainWindow::on_MesomorphcharacteristicsButton_clicked);
    connect(ui->Mesonutritionanddiet, &QPushButton::clicked, this, &MainWindow::on_MesomorphnutritionAndDietButton_clicked);
    connect(ui->Mesoexerciseandworkout, &QPushButton::clicked, this, &MainWindow::on_MesomorphexerciseAndWorkoutButton_clicked);
    //show exercise button

    connect(ui->showexercise, &QPushButton::clicked, this, &MainWindow::on_Ectoshowexercise_clicked);
    connect(ui->exerciseName, &QLineEdit::returnPressed, this, &MainWindow::on_Ectoshowexercise_clicked);
    connect(ui->showexercise2, &QPushButton::clicked, this, &MainWindow::on_Endoshowexercise_clicked);
    connect(ui->showexercise3, &QPushButton::clicked, this, &MainWindow::on_Mesoshowexercise_clicked);
    connect(ui->exerciseName2, &QLineEdit::returnPressed, this, &MainWindow::on_Endoshowexercise_clicked);
    connect(ui->exerciseName3, &QLineEdit::returnPressed, this, &MainWindow::on_Mesoshowexercise_clicked);




}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("fitness.db");

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
    ui->registerButton->setEnabled(false); // Disable the register button to prevent re-entry

    QString firstname = ui->firstname->text().trimmed();
    QString lastname = ui->lastname->text().trimmed();
    QString email = ui->email->text().trimmed();
    QString password = ui->password_2->text().trimmed();
    QString confirmPassword = ui->confirm->text().trimmed();

    // Debugging: Print the lengths of the trimmed fields
    qDebug() << "Firstname length:" << firstname.length();
    qDebug() << "Lastname length:" << lastname.length();
    qDebug() << "Email length:" << email.length();
    qDebug() << "Password length:" << password.length();
    qDebug() << "Confirm Password length:" << confirmPassword.length();

    QString generatedUsername = firstname + lastname;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM users WHERE email = ?");
    checkQuery.addBindValue(email);

    QSqlQuery query;
    query.prepare("INSERT INTO users (firstname, lastname, email, password) VALUES (?, ?, ?, ?)");
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(email);
    query.addBindValue(password);

    QMessageBox::information(this, "Registration Successful", "You are now registered!\nYour username is: " + generatedUsername);

    // Clear the registration fields
    ui->firstname->clear();
    ui->lastname->clear();
    ui->email->clear();
    ui->password_2->clear();
    ui->confirm->clear();

    ui->registerButton->setEnabled(true); // Re-enable the button after registration

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

//                                                        ectomorph buttons
void MainWindow::on_home1button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphfeatures);
}

void MainWindow::on_backtoectobutton_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphfeatures);
}
void MainWindow::on_back1button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->bodytypes);
}

void MainWindow::on_back4button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphexercise);
}

void MainWindow::on_back5button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphfeatures);
}

//                                                          endomorph buttons

void MainWindow::on_home2button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Endomorphfeatures);
}

void MainWindow::on_back6button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Endomorphfeatures);
}


void MainWindow::on_backtoendobutton_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Endomorphfeatures);
}

void MainWindow::on_back2button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->bodytypes);
}

void MainWindow::on_back8button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Endomorphexercise);
}


//                                                          mesmorphbuttons
void MainWindow::on_home3button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphfeatures);
}

void MainWindow::on_backtomesobutton_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphfeatures);
}

void MainWindow::on_back3button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->bodytypes);
}

void MainWindow::on_back7button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphfeatures);
}

void MainWindow::on_back9button_clicked()
{
    // Transition to the bodytypes page
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphexercise);
}

// Slot for Ectomorph Characteristics button

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
    ui->stackedWidget->setCurrentWidget(ui->Ectomorphexercise);
}

//ectomorph exercise showing

void MainWindow::on_Ectoshowexercise_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Ectoshowexercise);

    QString exerciseName = ui->exerciseName->text().trimmed();

    // Variables to hold exercise details and image path
    QString exerciseDetails;
    QString imagePath;

    // Retrieve exercise details and image path based on input
    if (exerciseName.compare("Squats", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Squats\n"
                          "Description: Excellent for lower body strength and muscle gain.\n"
                          "Muscles Worked: Quadriceps, Hamstrings, Glutes\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, barbell resting on your upper back.\n"
                          "Lower your body by bending your knees and hips, keeping your back straight.\n"
                          "Descend until your thighs are parallel to the ground.\n"
                          "Push through your heels to return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/squats.jpg"; // Resource path for Squats image
    } else if (exerciseName.compare("Deadlifts", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Deadlifts\n"
                          "Description: Great for overall strength and muscle development.\n"
                          "Muscles Worked: Back, Legs, Core\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with your feet hip-width apart, barbell in front.\n"
                          "Bend at your hips and knees to lower your body and grasp the barbell with an overhand grip.\n"
                          "Lift the barbell by extending your hips and knees to full extension.\n"
                          "Lower the barbell back to the ground in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/deadlift.jpg";
    }
    else if (exerciseName.compare("Biceps Curl", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Biceps Curl\n"
                          "Description: Strengthens the biceps, improves arm definition.\n"
                          "Muscles Worked: Biceps\n"
                          "Equipment: Dumbbells, Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding dumbbells or a barbell with palms facing forward.\n"
                          "Curl the weights up towards your shoulders while keeping your elbows close to your torso.\n"
                          "Slowly lower the weights back to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/barbellcurl.jpg";  // Ensure this path is correct
    } else if (exerciseName.compare("Pulley Push-down", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Pulley Push-down\n"
                          "Description: Targets the triceps, improving upper arm strength.\n"
                          "Muscles Worked: Triceps\n"
                          "Equipment: Cable Machine\n\n"
                          "Procedure:\n"
                          "Stand facing a pulley machine with a straight bar attached to the top pulley.\n"
                          "Grasp the bar with an overhand grip, elbows close to your sides.\n"
                          "Push the bar down until your arms are fully extended, then slowly return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/pulleypushdown.jpg";  // Ensure this path is correct

    } else if (exerciseName.compare("Bench Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Bench Press\n"
                          "Description: Targets the chest, shoulders, and triceps.\n"
                          "Muscles Worked: Chest, Shoulders, Triceps\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Lie on a bench with your feet flat on the floor.\n"
                          "Grasp the barbell with hands slightly wider than shoulder-width apart.\n"
                          "Lower the barbell to your chest, then press it back up to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/benchpress.jpg";
    } else if (exerciseName.compare("Pull-Ups/Chin-Ups", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Pull-Ups/Chin-Ups\n"
                          "Description: Effective for back and biceps development.\n"
                          "Muscles Worked: Back, Biceps\n"
                          "Equipment: Pull-Up Bar\n\n"
                          "Procedure:\n"
                          "Grasp the pull-up bar with an overhand grip for pull-ups or underhand grip for chin-ups.\n"
                          "Pull your body up until your chin is above the bar.\n"
                          "Lower your body back to the starting position in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 4-6 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 8-10 reps\n";
        imagePath = ":/images/chinup.jpg";
    } else if (exerciseName.compare("Shoulder Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Shoulder Press\n"
                          "Description: Builds shoulder and upper body strength.\n"
                          "Muscles Worked: Shoulders, Triceps\n"
                          "Equipment: Barbell or Dumbbells\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding the barbell or dumbbells at shoulder height.\n"
                          "Press the weight overhead until your arms are fully extended.\n"
                          "Lower the weight back to shoulder height.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/shoulderpress.jpg";
    } else if (exerciseName.compare("Rowing Machine", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Rowing Machine\n"
                          "Description: Full-body workout that also builds endurance.\n\n"
                          "Procedure:\n"
                          "Sit on the rowing machine with feet secured on the footrests.\n"
                          "Grasp the handle with an overhand grip.\n"
                          "Push through your legs, then pull the handle towards your chest.\n"
                          "Return to the starting position in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/Rowingmachine.jpg";
    } else if (exerciseName.compare("Cycling", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Cycling\n"
                          "Description: Low impact and good for cardiovascular health.\n\n"
                          "Procedure:\n"
                          "Adjust the bike seat to your height.\n"
                          "Pedal at a steady pace.\n"
                          "Maintain a consistent speed and resistance level.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/cycling.jpg";
    } else if (exerciseName.compare("Swimming", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Swimming\n"
                          "Description: Full-body exercise that is easy on the joints.\n\n"
                          "Procedure:\n"
                          "Choose a swimming stroke you are comfortable with.\n"
                          "Swim at a steady pace.\n"
                          "Focus on maintaining good form.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 2-3 times a week\n"
                          "Intermediate: 30-40 minutes, 3-4 times a week\n"
                          "Advanced: 40-60 minutes, 4-5 times a week\n";
        imagePath = ":/images/swimming.jpg";
    } else {
        exerciseDetails = "Please write the name of the exercise from the showing list.";
        imagePath = ":/images/default.jpg"; // Default image path
    }

    // Display the exercise details
    ui->exerciseDetailsLabel->setWordWrap(true);
    ui->exerciseDetailsLabel->setText(exerciseDetails);

    // Load and display the image
    QPixmap exerciseImage(imagePath);
    ui->exerciseImageLabel->setPixmap(exerciseImage.scaled(ui->exerciseImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


//mesomorph exercise showing

void MainWindow::on_Mesoshowexercise_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Mesoshowexercise);

    QString exerciseName = ui->exerciseName2->text().trimmed();

    // Variables to hold exercise details and image path
    QString exerciseDetails;
    QString imagePath;

    if (exerciseName.compare("Deadlifts", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Deadlifts\n"
                          "Description: Builds overall body strength and muscle mass.\n"
                          "Muscles Worked: Back, Legs, Core\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with your feet hip-width apart, barbell in front.\n"
                          "Bend at your hips and knees to lower your body and grasp the barbell with an overhand grip.\n"
                          "Lift the barbell by extending your hips and knees to full extension.\n"
                          "Lower the barbell back to the ground in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/deadlift.jpg";

    }  else if (exerciseName.compare("Biceps Curl", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Biceps Curl\n"
                          "Description: Strengthens the biceps, improves arm definition.\n"
                          "Muscles Worked: Biceps\n"
                          "Equipment: Dumbbells, Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding dumbbells or a barbell with palms facing forward.\n"
                          "Curl the weights up towards your shoulders while keeping your elbows close to your torso.\n"
                          "Slowly lower the weights back to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/bicepscurl.jpg";  // Ensure this path is correct
    } else if (exerciseName.compare("Pulley Push-down", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Pulley Push-down\n"
                          "Description: Targets the triceps, improving upper arm strength.\n"
                          "Muscles Worked: Triceps\n"
                          "Equipment: Cable Machine\n\n"
                          "Procedure:\n"
                          "Stand facing a pulley machine with a straight bar attached to the top pulley.\n"
                          "Grasp the bar with an overhand grip, elbows close to your sides.\n"
                          "Push the bar down until your arms are fully extended, then slowly return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/pulleypushdown.jpg";  // Ensure this path is correct
    }

    else if (exerciseName.compare("Squats", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Squats\n"
                          "Description: Essential for lower body strength.\n"
                          "Muscles Worked: Quadriceps, Hamstrings, Glutes\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, barbell resting on your upper back.\n"
                          "Lower your body by bending your knees and hips, keeping your back straight.\n"
                          "Descend until your thighs are parallel to the ground.\n"
                          "Push through your heels to return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/squats.jpg";

    } else if (exerciseName.compare("Pull-Ups/Chin-Ups", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Pull-Ups/Chin-Ups\n"
                          "Description: Effective for back and biceps development.\n"
                          "Muscles Worked: Back, Biceps\n"
                          "Equipment: Pull-Up Bar\n\n"
                          "Procedure:\n"
                          "Grasp the pull-up bar with an overhand grip for pull-ups or underhand grip for chin-ups.\n"
                          "Pull your body up until your chin is above the bar.\n"
                          "Lower your body back to the starting position in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 4-6 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 8-10 reps\n";
        imagePath = ":/images/chinup.jpg";

    } else if (exerciseName.compare("Bench Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Bench Press\n"
                          "Description: Upper body strength and muscle gain.\n"
                          "Muscles Worked: Chest, Shoulders, Triceps\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Lie on a bench with your feet flat on the floor.\n"
                          "Grasp the barbell with hands slightly wider than shoulder-width apart.\n"
                          "Lower the barbell to your chest, then press it back up to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/benchpress.jpg";
    } else if (exerciseName.compare("Leg Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Leg Press\n"
                          "Description: Strengthens the lower body.\n"
                          "Muscles Worked: Quadriceps, Hamstrings, Glutes\n"
                          "Equipment: Leg Press Machine\n\n"
                          "Procedure:\n"
                          "Sit in the leg press machine with feet shoulder-width apart on the platform.\n"
                          "Push the platform away from you by extending your legs, without locking your knees.\n"
                          "Slowly return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/legpress.jpg";

    }else if (exerciseName.compare("Military Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Military Press\n"
                          "Description: Develops shoulder strength and stability.\n"
                          "Muscles Worked: Shoulders, Triceps\n"
                          "Equipment: Barbell, Dumbbells\n\n"
                          "Procedure:\n"
                          "Stand with your feet shoulder-width apart, holding a barbell or dumbbells at shoulder height.\n"
                          "Press the weight overhead until your arms are fully extended.\n"
                          "Slowly lower the weight back to shoulder height.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/militarypress.jpg";  // Ensure this path is correct

    } else if (exerciseName.compare("Walking/Jogging", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Walking/Jogging\n"
                          "Description: Easy to start and effective for weight loss.\n\n"
                          "Procedure:\n"
                          "Walk or jog at a steady pace, focusing on maintaining good form.\n"
                          "Increase duration and intensity gradually.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/jogging.jpg";
    } else if (exerciseName.compare("Cycling", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Cycling\n"
                          "Description: Low-impact and great for burning calories.\n\n"
                          "Procedure:\n"
                          "Adjust the bike seat to your height.\n"
                          "Pedal at a steady pace.\n"
                          "Maintain a consistent speed and resistance level.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/cycling.jpg";
    } else if (exerciseName.compare("Swimming", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Swimming\n"
                          "Description: Full-body workout that is gentle on joints.\n\n"
                          "Procedure:\n"
                          "Choose a swimming stroke you are comfortable with.\n"
                          "Swim at a steady pace.\n"
                          "Focus on maintaining good form.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 2-3 times a week\n"
                          "Intermediate: 30-40 minutes, 3-4 times a week\n"
                          "Advanced: 40-60 minutes, 4-5 times a week\n";
        imagePath = ":/images/swimming.jpg";
    } else if (exerciseName.compare("Elliptical Trainer", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Elliptical Trainer\n"
                          "Description: Effective for cardiovascular health and weight loss.\n\n"
                          "Procedure:\n"
                          "Stand on the machine and hold the handles.\n"
                          "Begin pedaling at a steady pace.\n"
                          "Increase resistance and intensity gradually.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/elliptricaltrainer.jpg";
    } else if (exerciseName.compare("Running", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Running\n"
                          "Description: Effective cardio exercise for overall fitness and weight loss.\n\n"
                          "Procedure:\n"
                          "Run at a moderate pace, gradually increasing speed and distance.\n"
                          "Maintain good posture, keeping your back straight and arms relaxed.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/running.jpg";  // Make sure this path is correct
    }

    // Adding Jumping Rope
    else if (exerciseName.compare("Jumping Rope", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Jumping Rope\n"
                          "Description: High-intensity cardio exercise that improves coordination and burns calories.\n\n"
                          "Procedure:\n"
                          "Jump over the rope as it passes under your feet.\n"
                          "Maintain a steady rhythm, keeping your jumps light and quick.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 1-2 minutes\n"
                          "Intermediate: 3 sets of 2-3 minutes\n"
                          "Advanced: 4 sets of 3-5 minutes\n";
        imagePath = ":/images/jumpingrope.jpg";  // Make sure this path is correct
    }

    // Adding High-Intensity Interval Training (HIIT)
    else if (exerciseName.compare("High-Intensity Interval Training (HIIT)", Qt::CaseInsensitive) == 0 ||
             exerciseName.compare("HIIT", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: High-Intensity Interval Training (HIIT)\n"
                          "Description: Intense workout involving short bursts of activity followed by rest periods.\n\n"
                          "Procedure:\n"
                          "Perform a series of exercises (e.g., sprints, jumping jacks) at maximum effort for 20-30 seconds.\n"
                          "Rest for 10-15 seconds between exercises.\n"
                          "Repeat the cycle for 15-20 minutes.\n\n"
                          "Repetitions:\n"
                          "Beginner: 10-15 minutes, 2-3 times a week\n"
                          "Intermediate: 15-20 minutes, 3-4 times a week\n"
                          "Advanced: 20-30 minutes, 4-5 times a week\n";
        imagePath = ":/images/high.jpg";  // Make sure this path is correct
    }

    // Adding Leg Curl
    else if (exerciseName.compare("Leg Curl", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Leg Curl\n"
                          "Description: Strengthens the hamstrings and improves leg stability.\n"
                          "Muscles Worked: Hamstrings\n"
                          "Equipment: Leg Curl Machine\n\n"
                          "Procedure:\n"
                          "Lie face down on the leg curl machine with your ankles under the padded bar.\n"
                          "Curl your legs upward towards your buttocks.\n"
                          "Slowly lower your legs back to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/legcurl.jpg";  // Make sure this path is correct
    }

    else {
        exerciseDetails = "No exercise found with the name '" + exerciseName + "'.";
        imagePath = "";
    }

    // Set the exercise details and image on the UI
    ui->exerciseDetailsLabel2->setWordWrap(true);
    ui->exerciseDetailsLabel2->setText(exerciseDetails);
    ui->exerciseImagelabel2->setPixmap(QPixmap(imagePath));
    ui->exerciseImagelabel2->setScaledContents(true); // Scale image to fit the QLabel
}


//endomorph exercise showing


void MainWindow::on_Endoshowexercise_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Endoshowexercise);

    QString exerciseName = ui->exerciseName2->text().trimmed();

    // Variables to hold exercise details and image path
    QString exerciseDetails;
    QString imagePath;

    if (exerciseName.compare("Bench Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Bench Press\n"
                          "Description: Essential for upper body strength.\n"
                          "Muscles Worked: Chest, Shoulders, Triceps\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Lie on a bench with your feet flat on the floor.\n"
                          "Grasp the barbell with hands slightly wider than shoulder-width apart.\n"
                          "Lower the barbell to your chest, then press it back up to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 8-10 reps\n"
                          "Intermediate: 4 sets of 6-8 reps\n"
                          "Advanced: 5 sets of 5 reps\n";
        imagePath = ":/images/benchpress.jpg";
    } else if (exerciseName.compare("Squats", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Squats\n"
                          "Description: Builds lower body strength and power.\n"
                          "Muscles Worked: Quadriceps, Hamstrings, Glutes\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, barbell resting on your upper back.\n"
                          "Lower your body by bending your knees and hips, keeping your back straight.\n"
                          "Descend until your thighs are parallel to the ground.\n"
                          "Push through your heels to return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/squats.jpg";
    }    else if (exerciseName.compare("Biceps Curl", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Biceps Curl\n"
                          "Description: Strengthens the biceps, improves arm definition.\n"
                          "Muscles Worked: Biceps\n"
                          "Equipment: Dumbbells, Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding dumbbells or a barbell with palms facing forward.\n"
                          "Curl the weights up towards your shoulders while keeping your elbows close to your torso.\n"
                          "Slowly lower the weights back to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/bicepscurl.jpg";  // Ensure this path is correct
    } else if (exerciseName.compare("Pulley Push-down", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Pulley Push-down\n"
                          "Description: Targets the triceps, improving upper arm strength.\n"
                          "Muscles Worked: Triceps\n"
                          "Equipment: Cable Machine\n\n"
                          "Procedure:\n"
                          "Stand facing a pulley machine with a straight bar attached to the top pulley.\n"
                          "Grasp the bar with an overhand grip, elbows close to your sides.\n"
                          "Push the bar down until your arms are fully extended, then slowly return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/pulleypushdown.jpg";  // Ensure this path is correct
    }

    else if (exerciseName.compare("Deadlifts", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Deadlifts\n"
                          "Description: Builds overall body strength and muscle mass.\n"
                          "Muscles Worked: Back, Glutes, Hamstrings\n"
                          "Equipment: Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet hip-width apart, barbell in front of you.\n"
                          "Bend at the hips and knees to grip the barbell with both hands.\n"
                          "Lift the bar by straightening your back and legs, keeping the bar close to your body.\n"
                          "Lower the bar back to the ground with control.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 6-8 reps\n"
                          "Intermediate: 4 sets of 5-7 reps\n"
                          "Advanced: 5 sets of 4-6 reps\n";
        imagePath = ":/images/deadlift.jpg";

    } else if (exerciseName.compare("Lat Pulldowns", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Lat Pulldowns\n"
                          "Description: Targets the back muscles.\n"
                          "Muscles Worked: Latissimus Dorsi, Biceps\n"
                          "Equipment: Lat Pulldown Machine\n\n"
                          "Procedure:\n"
                          "Sit at the lat pulldown machine and grasp the bar with a wide grip.\n"
                          "Pull the bar down towards your chest, squeezing your shoulder blades together.\n"
                          "Slowly return the bar to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/lat-pulldown.jpg";
    } else if (exerciseName.compare("Leg Press", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Leg Press\n"
                          "Description: Strengthens the lower body.\n"
                          "Muscles Worked: Quadriceps, Hamstrings, Glutes\n"
                          "Equipment: Leg Press Machine\n\n"
                          "Procedure:\n"
                          "Sit in the leg press machine with feet shoulder-width apart on the platform.\n"
                          "Push the platform away from you by extending your legs, without locking your knees.\n"
                          "Slowly return to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
        imagePath = ":/images/legpress.jpg";

    } else if (exerciseName.compare("Kettlebell Swings", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Kettlebell Swings\n"
                          "Description: Full-body exercise that also boosts cardio.\n"
                          "Muscles Worked: Glutes, Hamstrings, Shoulders\n"
                          "Equipment: Kettlebell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding the kettlebell with both hands.\n"
                          "Bend your knees slightly and swing the kettlebell between your legs.\n"
                          "Explosively drive your hips forward to swing the kettlebell up to shoulder height.\n"
                          "Control the descent of the kettlebell back between your legs and repeat.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 15 reps\n"
                          "Intermediate: 4 sets of 12 reps\n"
                          "Advanced: 5 sets of 10 reps\n";
        imagePath = ":/images/kettlebellswing.jpg";
    } else if (exerciseName.compare("Walking/Jogging", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Walking/Jogging\n"
                          "Description: Easy to start and effective for weight loss.\n"
                          "Muscles Worked: Legs, Core\n"
                          "Equipment: None\n\n"
                          "Procedure:\n"
                          "Begin with a warm-up walk for 5-10 minutes.\n"
                          "Gradually increase your pace to a brisk walk or light jog.\n"
                          "Maintain the pace for the desired time, then cool down with a slower walk.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes\n"
                          "Intermediate: 30-45 minutes\n"
                          "Advanced: 45-60 minutes\n";
        imagePath = ":/images/walking.jpg";
    } else if (exerciseName.compare("Cycling", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Cycling\n"
                          "Description: Low-impact and great for burning calories.\n"
                          "Muscles Worked: Legs, Glutes, Core\n"
                          "Equipment: Bicycle\n\n"
                          "Procedure:\n"
                          "Start with a 5-10 minute warm-up at a low resistance.\n"
                          "Gradually increase your speed or resistance.\n"
                          "Cycle at a steady pace for the desired time, then cool down at a low resistance.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes\n"
                          "Intermediate: 30-45 minutes\n"
                          "Advanced: 45-60 minutes\n";
        imagePath = ":/images/cycling.jpg";

    }  else if (exerciseName.compare("Biceps Curl", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Biceps Curl\n"
                          "Description: Strengthens the biceps, improves arm definition.\n"
                          "Muscles Worked: Biceps\n"
                          "Equipment: Dumbbells, Barbell\n\n"
                          "Procedure:\n"
                          "Stand with feet shoulder-width apart, holding dumbbells or a barbell with palms facing forward.\n"
                          "Curl the weights up towards your shoulders while keeping your elbows close to your torso.\n"
                          "Slowly lower the weights back to the starting position.\n\n"
                          "Repetitions:\n"
                          "Beginner: 3 sets of 10-12 reps\n"
                          "Intermediate: 4 sets of 8-10 reps\n"
                          "Advanced: 5 sets of 6-8 reps\n";
    } else if (exerciseName.compare("Swimming", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Swimming\n"
                          "Description: Full-body workout that is gentle on joints.\n"
                          "Muscles Worked: Full Body\n"
                          "Equipment: Pool\n\n"
                          "Procedure:\n"
                          "Warm up with a few easy laps.\n"
                          "Increase your speed and distance based on your fitness level.\n"
                          "Incorporate different strokes to target various muscle groups.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes\n"
                          "Intermediate: 30-45 minutes\n"
                          "Advanced: 45-60 minutes\n";
        imagePath = ":/images/swimming.jpg";

    } else if (exerciseName.compare("Elliptical Trainer", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Elliptical Trainer\n"
                          "Description: Effective for cardiovascular health and weight loss.\n\n"
                          "Procedure:\n"
                          "Stand on the machine and hold the handles.\n"
                          "Begin pedaling at a steady pace.\n"
                          "Increase resistance and intensity gradually.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/elliptricaltrainer.jpg";
    }
    else if (exerciseName.compare("Rowing Machine", Qt::CaseInsensitive) == 0) {
        exerciseDetails = "Exercise: Rowing Machine\n"
                          "Description: Full-body workout that also builds endurance.\n\n"
                          "Procedure:\n"
                          "Sit on the rowing machine with feet secured on the footrests.\n"
                          "Grasp the handle with an overhand grip.\n"
                          "Push through your legs, then pull the handle towards your chest.\n"
                          "Return to the starting position in a controlled manner.\n\n"
                          "Repetitions:\n"
                          "Beginner: 20-30 minutes, 3 times a week\n"
                          "Intermediate: 30-40 minutes, 4 times a week\n"
                          "Advanced: 40-60 minutes, 5 times a week\n";
        imagePath = ":/images/Rowingmachine.jpg";
    }
    else {
        exerciseDetails = "No exercise found with the given name.";
        imagePath = ":/images/not_found.jpg";  // Replace with a 'not found' image path
    }

    // Set exercise details to label_7
    ui->exerciseDetailsLabel1->setWordWrap(true);
    ui->exerciseDetailsLabel1->setText(exerciseDetails);

    // Load image and set it to label_8
    QPixmap pixmap(imagePath);
    ui->exerciseImagelabel1->setPixmap(pixmap.scaled(ui->exerciseImagelabel1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
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
    ui->stackedWidget->setCurrentWidget(ui->Endomorphexercise);

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
    ui->stackedWidget->setCurrentWidget(ui->Mesomorphexercise);
}
