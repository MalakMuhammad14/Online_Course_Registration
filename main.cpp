#include <cstdlib>
#include "globals.h"

int main() {
    initData();
    showWelcome();

    int choice;
    do {
        mainMenu();
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            studentMenu();
            int studentChoice;
            cin >> studentChoice;
            system("cls");

            switch (studentChoice) {
            case 1: {
                int studentIndex = studentLogin();
                int subChoice;
                cin >> subChoice;

                switch (subChoice) {
                case 1:
                    viewAvailableCourses();
                    system("pause");
                }
                break;
            }
            case 2:
                studentSignUp();
                break;
            case 0:
                break;
            }
            break;
        case 2:
            cout << "//Log in admin";
            break;
        case 0:
            cout << "Goodbye!";
            break;
        default :
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
}