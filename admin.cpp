#include "globals.h"

int adminLogin() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        int id;
        string password;

        cout << "\n=== ADMIN LOGIN ===" << endl;
        cout << "Enter Admin ID: ";
        while (!(cin >> id)) {
            cout << "Invalid ID! Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore(1000, '\n');

        cout << "Enter Password: ";
        getline(cin, password);

        int index = findAdmin(id, password);

        if (index != -1) {
            cout << "\nLogin Successful!" << endl;
            cout << "Welcome, " << admins[index].name
                << " (ID: " << admins[index].adminID << ")" << endl;

            system("pause");
            system("cls");
            return index;
        }

        else {
            cout << "\nInvalid Admin ID or Password!" << endl;
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                cout << "Attempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
            else
                cout << "\nToo many failed attempts. Try again later..." << endl;
        }
    }

    return -1;
}

//  ============== Add Course Function =================
/*void addCourse() {
    // Check if there is still space in the courses array before adding.
    if (courseCount < MAX_COURSES) {
        int id;
        cout << "Enter Course ID: " << endl;
        cin >> id;
        // Check if the ID already exist.
        int result = findCourse(id);
        while (result != -1) {
            cout << "This id is already exist to another course.Please try again." << endl;
            cout << "Enter Course ID: ";
            cin >> id;
            result = findCourse(id);
        }
        courses[courseCount].courseID = id;

        cin.ignore();
        string courseName;
        cout << "Enter Course Name: " << endl;
        getline(cin, courseName);
        courses[courseCount].courseName = courseName;

        string instructorName;
        cout << "Enter Instructor Name: " << endl;
        getline(cin, instructorName);
        courses[courseCount].instructorName = instructorName;

        int creditHours;
        cout << "Enter Credit Hours: " << endl;
        cin >> creditHours;
        courses[courseCount].creditHours = creditHours;

        int maxCapacity;
        cout << "Enter Maximum Capacity: " << endl;
        cin >> maxCapacity;
        courses[courseCount].maxCapacity = maxCapacity;

        cin.ignore();
        string day;
        cout << "Enter scheduled day(ex. Monday): " << endl;
        getline(cin, day);
        courses[courseCount].day = day;

        string time;
        cout << "Enter scheduled time(ex. 10:00 AM): " << endl;
        getline(cin, time);
        courses[courseCount].time = time;

        // Initialize enrollment count to zero.
        courses[courseCount].currentEnrolled = 0;

        courseCount += 1;

        cout << "Course " << courseName << " added successfully!" << endl;
    }
    else {
        // Error message if the array is full.
        cout << "Unable to add new course. System capacity is full." << endl;
    }
}

// Used by editCourse only - removes spaces from name for flexible comparison
string normalizeName(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            result += s[i];
    return result;
}

// Used by editCourse only - checks if instructor name has letters only
bool isValidInstructor(string name) {
    string normalized = normalizeName(name);

    if (normalized.length() == 0)
        return false;

    for (int i = 0; i < normalized.length(); i++)
        if (!isalpha(normalized[i]) && normalized[i] != '.')
            return false;

    return true;
}

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

void deleteCourse() {
    int id;
    cout << "Enter course id to delete: ";
    cin >> id;

    int index = findCourse(id);

    if (index == -1) {
        cout << "Course not found.\n";
        return;
    }

    if (index != 1 && courses[index].currentEnrolled == 0) {

        // shift all courses left
        for (int i = index; i < courseCount - 1; i++) {
            courses[i] = courses[i + 1];
        }


        courseCount--;

        cout << "Course deleted successfully.\n";
    }
    else {
        cout << "deleted failed";
    }
}

void viewAllStudents() {
   
    if (studentCount == 0)
    {
        cout << "No students found\n";
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        cout << "Student ID: " << students[i].studentID << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "Number of Courses: " << students[i].numCourses << endl;
        cout << "------------------------" << endl;
    }
}

void logoutAdmin() {

}*/