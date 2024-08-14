#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_signupButton_clicked();
    void on_registerButton_clicked();
    void on_calculateButton_clicked();
    void on_nextButton_clicked();
    void on_backtobmiButton_clicked();
    void on_ectomorphButton_clicked();
    void on_mesomorphButton_clicked();
    void on_endomorphButton_clicked();

    //ectomorpph button
    void on_home1button_clicked();
    void on_backtoectobutton_clicked();
    void on_back1button_clicked();
    void on_back4button_clicked();
    void on_back5button_clicked();



    //endomorph button
    void on_home2button_clicked();
    void on_backtoendobutton_clicked();
    void on_back2button_clicked();
    void on_back6button_clicked();
    void on_back8button_clicked();


    //Mesomorph button
    void on_home3button_clicked();
    void on_backtomesobutton_clicked();
    void on_back3button_clicked();
    void on_back7button_clicked();
    void on_back9button_clicked();


    void on_EctomorphcharacteristicsButton_clicked();
    void on_EctomorphnutritionAndDietButton_clicked();
    void on_EctomorphexerciseAndWorkoutButton_clicked();

    void on_EndomorphcharacteristicsButton_clicked();
    void on_EndomorphnutritionAndDietButton_clicked();
    void on_EndomorphexerciseAndWorkoutButton_clicked();

    void on_MesomorphcharacteristicsButton_clicked();
    void on_MesomorphnutritionAndDietButton_clicked();
    void on_MesomorphexerciseAndWorkoutButton_clicked();

    void on_Ectoshowexercise_clicked();
    void on_Endoshowexercise_clicked();
    void on_Mesoshowexercise_clicked();





private:
    Ui::MainWindow *ui;
    int currentUserId; // Variable to store the ID of the currently logged-in user
    QString generatedUsername; // Variable to store the generated username
    void initializeDatabase();  // Method to initialize the database
    void storeBMIData(double weight, double height, double bmi); // Method to store BMI data
    void retrieveUserData(const QString& email);// Method to retrieve user data and set currentUserId
};

#endif // MAINWINDOW_H
