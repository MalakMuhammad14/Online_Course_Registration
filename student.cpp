#include "globals.h"

// ================= LOGIN FUNCTION =================
bool login() {
    int id, role;
    string password;

    cout << "\n=== LOGIN ===" << endl;
    cout << "Select Role:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Admin" << endl;
    cout << "Enter choice (1-2): ";

    while (!(cin >> role)  role < 1  role > 2) {
        cout << "Invalid input! Please enter a number (1-2): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter ID: ";
    while (!(cin >> id)) {
        cout << "Invalid ID! Please enter a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    cout << "Enter Password: ";
    getline(cin, password);

    if (role == 1) {
        int studentIndex = findStudent(id, password);
        if (studentIndex != -1) {
            cout << "\nStudent Login Successful " << endl;
            cout << "Welcome, " << students[studentIndex].name << " (ID: "
                << students[studentIndex].studentID << ")" << endl;
            cout << "Level: " << students[studentIndex].level << endl;
            return true;
        }
        else {
            cout << "\nInvalid Student ID or Password!" << endl;
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                cout << "Attempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
            else {
                cout << "\nToo many failed attempts. Try again later..." << endl;
                system("pause");
                system("cls");
    }
    else if (role == 2) {
        int adminIndex = findAdmin(id, password);
        if (adminIndex != -1) {
            cout << "\nAdmin Login Successful" << endl;
            cout << "Welcome, " << admins[adminIndex].name << " (ID: "
                << admins[adminIndex].adminID << ")" << endl;
            return true;
        }
    }
    return -1;
}

void studentSignUp() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Sorry, no more students can be added!" << endl;
        return;
    }

    Student s;

    // ID (numbers only)
    cout << "Enter Student ID: ";
    while (!(cin >> s.studentID)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid! ID must be numbers only. Try again: ";
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == s.studentID) {
            cout << "ID already exists!" << endl;
            return;
        }
    }

    // Name (no numbers allowed)
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    while (true) {
        bool validName = true;
        for (int i = 0; i < s.name.length(); i++) {
            if (isdigit(s.name[i])) {
                validName = false;
                break;
            }
        }
        if (validName) break;
        cout << "Invalid! Name must be letters only. Try again: ";
        getline(cin, s.name);
    }

    // Password (anything allowed)
    cout << "Enter Password: ";
    cin >> s.password;

    // Level (1 to 4 only)
    cout << "Enter Level (1-4): ";
    while (!(cin >> s.level) || s.level < 1 || s.level > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid! Level must be between 1 and 4. Try again: ";
    }

    s.numCourses = 0;
    for (int i = 0; i < 10; i++)
        s.registeredCourses[i] = 0;

    students[studentCount] = s;
    studentCount++;

    cout << "Sign Up Successful!" << endl;
}

void viewAvailableCourses() {
    cout << "\n--- Available Courses List ---\n";

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].currentEnrolled < courses[i].maxCapacity) {
            cout << " Course ID   : " << courses[i].courseID << endl;
            cout << " Course Name : " << courses[i].courseName << endl;
            cout << " Instructor  : " << courses[i].instructorName << endl;
            cout << "    Day      : " << courses[i].day << endl;
            cout << "    Time     : " << courses[i].time << endl;
            cout << " Enrollment  : " << courses[i].currentEnrolled << "/" << courses[i].maxCapacity << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

/*void registerCourses(int studentIndx) {
    int id;
    cout << "Enter the course ID: ";
    cin >> id;
    int result = findCourse(id);
    while (result == -1) {
        cout << "There is no an available courses for this id.Please try again." << endl;
        cout << "Enter Course ID: ";
        cin >> id;
        result = findCourse(id);
    }
}*/
void registerCourse(int studenIndex)

{
    if (students[studentIndex].numCourses >= 10)

    {

        cout << "student reached max limit" << endl;

        return;

    }
    int id;
    cout << "Enter course id: ";
    cin >> id;


    if (studentIndex == -1)

    {

        cout << "student not found" << endl;

        return;

    }

    int courseIndex = findCourse(id);



  

    if (courseIndex == -1)

    {

        cout << "course not found" << endl;

        return;

    }



    if (courses[courseIndex].currentEnrolled >= courses[courseIndex].maxCapacity)

    {

        cout << "course is full" << endl;

        return;

    }





    students[studentIndex].registerCourses[students[studentIndex].numCourses] = courseID;

    students[studentIndex].numCourses++;

    courses[courseIndex].currentEnrolled++;



    cout << "registration successful" << endl;

}

//   ==========student drop course=========   //
void dropCourse() {  // ali [101, 102, 103, 104]

    int id;
    cout << "Enter Course ID to delete: ";
    cin >> id;

    int index = findCourse(id);

    if (index == -1) {
        cout << "Error: Course ID not found!\n";
        return;

    }

    if (courses[index].currentEnrolled > 0) {
        cout << "Error: Cannot delete course. There are students enrolled in it!\n";
    }
    else {
        for (int i = index; i < courseCount - 1; i++) {
            courses[i] = courses[i + 1];
        }
        courseCount--;
        cout << "Course deleted successfully.\n";
    }
}

void viewMyCourses(int studentIndex) {
    if (students[studentIndex].numCourses == 0) {
        cout << "No registered courses yet.\n";
        return;
    }

    cout << "\n=== My Registered Courses ===\n";

    for (int i = 0; i < students[studentIndex].numCourses; i++) {
        int courseID = students[studentIndex].registeredCourses[i];
        int c = findCourse(courseID);

        if (c != -1) {
            cout << "Course ID: " << courses[c].courseID << endl;
            cout << "Course Name: " << courses[c].courseName << endl;
            cout << "Instructor: " << courses[c].instructorName << endl;
            cout << "Credit Hours: " << courses[c].creditHours << endl;
            cout << "Day: " << courses[c].day << endl;
            cout << "Time: " << courses[c].time << endl;
            cout << "-----------------------------\n";
        }
    }
}