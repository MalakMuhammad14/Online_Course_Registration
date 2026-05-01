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

void adminMenu() {
        cout << "\n--- Admin Control Panel ---" << endl;
        cout << "1. Add Course\n2. Edit Course\n3. Delete Course\n4. View All Students\n0. Logout (Back)\nEnter your choice: ";
}

void studentPortal() {
    studentMenu();
    int studentChoice;
    cin >> studentChoice;
    system("cls");

    switch (studentChoice) {
    case 1:
        int studentIndex = studentLogin();

        if (studentIndex != -1) {
            int subChoice;
            do {
                system("cls");
                studentFunctionMenu(); 
                cin >> subChoice;

                switch (subChoice) {
                case 1:
                    viewAvailableCourses();
                    system("pause");
                    break;
                case 2:
                    registerCourse(studentIndex);
                    system("pause");
                    break;
                case 3:
                    dropCourse(studentIndex);
                    system("pause");
                    break;
                case 4:
                    viewMyCourses(studentIndex);
                    break;
                case 5:
                    if (studentLogout()) {
                        subChoice = 5;
                    }
                    else {
                        subChoice = -1;
                    }
                    break;
                default:
                    cout << "Invalid Choice!" << endl;
                }
            } while (subChoice != 5);
        }
        break;
    case 2:
        studentSignUp();
        break;
    case 0:
        break;
    default:
        cout << "Invalid Choice!" << endl;
    }
}

void adminPortal() {
    int adminIndex = adminLogin();

    if (adminIndex != -1) {
        int subChoice;

        do {
            system("cls");
            adminMenu();
            cin >> subChoice;

            switch (subChoice) {
            case 1:
                addCourse();
                system("pause");
                break;
            case 2:
                editCourse();
                system("pause");
                break;
            case 3:
                deleteCourse();
                system("pause");
                break;
            case 4:
                viewAllStudents();
                system("pause");
                break;
            case 0:
                logoutAdmin();
                system("pause");
                break;
            default:
                cout << "Invalid Choice!" << endl;
            }
        } while (subChoice != 0);
    }
}