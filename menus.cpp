#include "globals.h"

void showWelcome() {
    cout << "*********************************************" << endl;
    cout << "      Online Course Registration System      " << endl;
    cout << "*********************************************" << endl;
    cout << "Welcome!Your journey to learning starts here." << endl;
}

void mainMenu() {
    cout << "\nContinue as:" << endl;
    cout << "-------------------" << endl;
    cout << " 1. Student." << endl;
    cout << " 2. Admin." << endl;
    cout << " 0. Exit." << endl;
    cout << "Enter your choice(1, 2 or 0): ";
}

void studentMenu() {
    cout << "----------------Student-----------------" << endl;
    cout << "1. Have you account already?(Log in)." << endl;
    cout << "2. Are you first here?(sign up)." << endl;
    cout << "0. Go Back." << endl;
    cout << "Enter your choice(1, 2 or 0): ";
}

void studentFunctionMenu() {
    cout << "----------------Student-----------------" << endl;
    cout << "1. View Available Courses." << endl;
    cout << "2. Register Course." << endl;
    cout << "3. Drop Course." << endl;
    cout << "4. View My Course." << endl;
    cout << "5. Logout." << endl;
    cout << "Enter your choice(1, 2, 3, 4 or 5): ";                                                                                
}