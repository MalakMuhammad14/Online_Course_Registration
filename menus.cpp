#include "globals.h"

void showWelcome() {
    cout << "\n                        **************************************************" << endl;
    cout << "                          *                                            *" << endl;
    cout << "                             *  Online Course Registration System   *" << endl;
    cout << "                          *                                            *" << endl;
    cout << "                        **************************************************" << endl;
    cout << "                        ||                                               ||" << endl;
    cout << "                        || Welcome!Your journey to learning starts here. ||" << endl;
    cout << "                         =================================================\n" << endl;
    system("pause");
    system("cls");
}

void mainMenu() {
    cout << "\n                                  Continue as : " << endl;
    cout << "           -----------------------------------------------------------" << endl;
    cout << "           |      1. Student.                         2. Admin.      |" << endl;
    cout << "           |                                                         |" << endl;
    cout << "           |                        0. Exit.                         |" << endl;
    cout << "           -----------------------------------------------------------\n" << endl;
    cout << "           Enter your choice(1, 2 or 0): ";
}

void studentMenu() {
    cout << "         - - - - - - - - - - - Student - - - - - - - - - - - -\n" << endl;
    cout << "         |  1. Have you account already?(Log in).            |\n" << endl;
    cout << "         |  2. Are you first here?(sign up).                 |\n" << endl;
    cout << "         |  0. Go Back.                                      |" << endl;
    cout << "         - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;
    cout << "           Enter your choice(1, 2 or 0): ";
}

void studentFunctionMenu() {
    cout << "           - - - - - - - - - - - Student - - - - - - - - - - -\n" << endl;
    cout << "           |  1. View Available Courses.                     |\n" << endl;
    cout << "           |  2. Register Course.                            |\n" << endl;
    cout << "           |  3. Drop Course.                                |\n" << endl;
    cout << "           |  4. View My Course.                             |\n" << endl;
    cout << "           |  5. Logout.                                     |" << endl;
    cout << "           - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;
    cout << "             Enter your choice(1, 2, 3, 4 or 5): ";                                                                                
}

void adminMenu() {
    cout << "           - - - - - - - - - Admin Control Panel - - - - - - - -\n" << endl;
    cout << "           |  1. Add Course.                                   |\n" << endl;
    cout << "           |  2. Edit Course.                                  |\n" << endl;
    cout << "           |  3. Delete Course.                                |\n" << endl;
    cout << "           |  4. View All Students.                            |\n" << endl;
    cout << "           |  0. Logout.                                       |" << endl;
    cout << "           - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;
    cout << "             Enter your choice(1, 2, 3, 4 or 0): ";
}

void studentPortal() {
    int studentChoice;
    while (true) {
        studentMenu();
        studentChoice = isNumber();
        system("cls");

        switch (studentChoice) {
        case 1: {
            int studentIndex = studentLogin();

            if (studentIndex != -1) {
                int subChoice;
                do {
                    system("cls");
                    studentFunctionMenu();
                    subChoice = isNumber();

                    switch (subChoice) {
                    case 1:
                        system("cls");
                        viewAvailableCourses();
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        registerCourse(studentIndex);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        dropCourse(studentIndex);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
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
                        system("pause");
                    }
                } while (subChoice != 5);
            }
            break;
        }
        case 2:
            studentSignUp();
            break;
        case 0:
            break;
        default:
            cout << "Invalid Choice! Please try again." << endl;
            continue;
        }
        break;
    }
}

void adminPortal() {
    int adminIndex = adminLogin();

    if (adminIndex != -1) {
        int subChoice;

        do {
            system("cls");
            adminMenu();
            subChoice = isNumber();

            switch (subChoice) {
            case 1:
                system("cls");
                addCourse();
                system("pause");
                break;
            case 2:
                system("cls");
                editCourse();
                system("pause");
                break;
            case 3:
                system("cls");
                deleteCourse();
                system("pause");
                break;
            case 4:
                system("cls");
                viewAllStudents();
                system("pause");
                break;
            case 0:
                logoutAdmin();
                system("pause");
                break;
            default:
                cout << "Invalid Choice! Please try again." << endl;
                system("pause");
            }
        } while (subChoice != 0);
    }
}