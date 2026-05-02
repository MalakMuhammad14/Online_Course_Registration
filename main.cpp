#include <cstdlib>
#include "globals.h"

int main() {
    loadAllData();
    //initData();
    showWelcome();

    int choice;
    do {
        mainMenu();
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            studentPortal();
            break;
        case 2:
            adminPortal();
            break;
        case 0:
            saveAllData();
            cout << "Goodbye!"<< endl;
            break;
        default :
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    return 0;
}