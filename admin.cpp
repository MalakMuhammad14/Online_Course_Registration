#include "globals.h"

// ====================== Admin Login Function ============================
int adminLogin() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        int id;
        string password;

        cout << "\n================ ADMIN LOGIN ===============\n" << endl;
        cout << "\tEnter Admin ID: ";
        while (!(cin >> id)) {
            cout << "\n\tInvalid ID! Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore(1000, '\n');

        cout << "\n\tEnter Password: ";
        getline(cin, password);

        int index = findAdmin(id, password);

        if (index != -1) {
            cout << "\n\tLogin Successful!";
            cout << "\tWelcome " << admins[index].name
                << " (ID: " << admins[index].adminID << ")" << endl;

            system("pause");
            system("cls");
            return index;
        }

        else {
            cout << "\n\tInvalid Admin ID or Password!" << endl;
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                cout << "\n\tAttempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
            else {
                cout << "\n\tToo many failed attempts. Try again later..." << endl;
                system("pause");
                system("cls");
            }
        }
    }
    return -1;
}

//  ============== Add Course Function =================
void addCourse() {
    // Check if there is still space in the courses array before adding.
    if (courseCount < MAX_COURSES) {
        int id;
        cout << "\n\tEnter Course ID: ";
        id = isNumber();
        // Check if the ID already exist.
        int result = findCourse(id);
        while (result != -1) {
            cout << "\n\tThis id is already exist to another course.Please try again." << endl;
            cout << "\n\tEnter Course ID(or enter 0 to go back): ";
            id = isNumber();
            if (id == 0) return;
            result = findCourse(id);
        }
        courses[courseCount].courseID = id;

        string courseName;
        cout << "\n\tEnter Course Name: ";
        getline(cin, courseName);
        while (!isValidInstructor(courseName)) {
            cout << "\n\tInvalid! Name must contain letters only. Try again: ";
            getline(cin, courseName);
        }
        courses[courseCount].courseName = courseName;

        string instructorName;
        cout << "\n\tEnter Instructor Name: ";
        getline(cin, instructorName);
        while (!isValidInstructor(instructorName)) {
            cout << "\n\tInvalid! Name must contain letters only. Try again: ";
            getline(cin, instructorName);
        }
        courses[courseCount].instructorName = instructorName;

        int creditHours;
        cout << "\n\tEnter Credit Hours: ";
        creditHours = isNumber();
        courses[courseCount].creditHours = creditHours;

        int maxCapacity;
        cout << "\n\tEnter Maximum Capacity: ";
        maxCapacity = isNumber();
        courses[courseCount].maxCapacity = maxCapacity;

        string day;
            cout << "\n\tChoose scheduled day:-\n\t------------------------------" << endl;
            cout << "\t1. Saturday          2. Sunday" << endl;
            cout << "\t3. Monday            4. Tuesday" << endl;
            cout << "\t5. Wednesday         6. Thursday" << endl;
            cout << "\t6. Friday\n\t------------------------" << endl;
            cout << "\tEnter your choice: ";

            while (true) {
            int choice;
            choice = isNumber();
            switch (choice) {
            case 1:
                day = "Saturday";
                break;
            case 2:
                day = "Sunday";
                break;
            case 3:
                day = "Monday";
                break;
            case 4:
                day = "Tuesday";
                break;
            case 5:
                day = "Wednesday";
                break;
            case 6:
                day = "Thursday";
                break;
            case 7:
                day = "Friday";
                break;
            default:
                cout << "\n\tInvalid choice! Please select(1-7)." << endl;
                cout << "\n\tEnter your choice: ";
                continue;
            }
            break;
        }
        courses[courseCount].day = day;

        string time;
        cout << "\n\tEnter scheduled time(ex. 10:00 AM): ";
        getline(cin, time);
        courses[courseCount].time = time;

        // Initialize enrollment count to zero.
        courses[courseCount].currentEnrolled = 0;

        courseCount += 1;

        cout << "\n\tCourse " << courseName << " added successfully!" << endl;
    }
    else {
        // Error message if the array is full.
        cout << "\n\tUnable to add new course. System capacity is full." << endl;
    }
}

// ======================= Edit Course Function ==========================
void editCourse() {
    int id;
    cout << "Enter Course ID to edit: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid! ID must be numbers only. Try again: ";
    }

    int index = findCourse(id);
    if (index == -1) {
        cout << "Course not found!" << endl;
        return;
    }

    int choice;
    cout << "What do you want to edit?" << endl;
    cout << "1. Instructor Name" << endl;
    cout << "2. Credit Hours" << endl;
    cout << "3. Max Capacity" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        cin.ignore();
        cout << "Enter new Instructor Name: ";
        getline(cin, courses[index].instructorName);
        while (!isValidInstructor(courses[index].instructorName)) {
            cout << "Invalid! Name must contain letters only. Try again: ";
            getline(cin, courses[index].instructorName);
        }
        break;
    }
    case 2:
        cout << "Enter new Credit Hours (1-4): ";
        while (!(cin >> courses[index].creditHours) || courses[index].creditHours < 1 || courses[index].creditHours > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid! Credit Hours must be between 1 and 4. Try again: ";
        }
        break;
    case 3:
        cout << "Enter new Max Capacity (1-300): ";
        while (!(cin >> courses[index].maxCapacity) || courses[index].maxCapacity < 1 || courses[index].maxCapacity > 300) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid! Max Capacity must be between 1 and 300. Try again: ";
        }
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Course updated successfully!" << endl;
}

// ============================ Delete Course Function ======================
void deleteCourse() {
    int id;
    cout << "Enter course id to delete: ";
    cin >> id;

    int index = findCourse(id);

    if (index == -1) {
        cout << "Course not found.\n";
        return;
    }

    // Check if there are student in this course
    if (courses[index].currentEnrolled == 0) {

        // shift all courses left
        for (int i = index; i < courseCount - 1; i++) {
            courses[i] = courses[i + 1];
        }


        courseCount--;

        cout << "Course deleted successfully.\n";
    }

    else {
        cout << "deleted failed due to exist students in this course.";
    }
}

// ==================== View All Students =======================
void viewAllStudents() {
   
    if (studentCount == 0)
    {
        cout << "No students found\n";
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        cout << i + 1 << ". ";
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].studentID << endl;
        cout << "Level: " << students[i].level << endl;
        cout << "Number of Courses: " << students[i].numCourses << endl;
        cout << "---------------------------------" << endl;
    }
}

// ================== Logout Admin Function ======================
void logoutAdmin() {
    cout << "You have logged out successfully." << endl;
}