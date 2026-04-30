#include "globals.h"

// ================= LOGIN FUNCTION =================
int studentLogin() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        int id;
        string password;

        cout << "\n=== STUDENT LOGIN ===" << endl;
        cout << "Enter Student ID: ";
        while (!(cin >> id)) {
            cout << "Invalid ID! Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n');

        cout << "Enter Password: ";
        getline(cin, password);

        int index = findStudent(id, password);

        if (index != -1) {
            cout << "\nLogin Successful!" << endl;
            cout << "Welcome, " << students[index].name
                << " (ID: " << students[index].studentID << ")" << endl;
            cout << "Level: " << students[index].level << endl;

            system("pause");
            system("cls");

            return index;
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
        }
    }
    return -1;
}

// =================== Sign Up Function ==========================
void studentSignUp() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Sorry, no more students can be added!" << endl;
        return;
    }

    Student s;
    bool idExist;

    do {
        idExist = false;
        // ID (numbers only)
        cout << "Enter Student ID(or enter 0 to go back): ";
        while (!(cin >> s.studentID)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid! ID must be numbers only. Try again: ";
        }

        if (s.studentID == 0) return;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == s.studentID) {
                cout << "ID already exists! Please try again." << endl;
                idExist = true;
                break;
            }
        }
    } while (idExist);

        // Name (no numbers allowed)
    cin.ignore(1000,'\n');
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
    getline(cin, s.password);

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

// ===================== Available Courses Function ===========================
void viewAvailableCourses() {
    cout << "========== VIEW AVAILABLE COURSES ============" << endl;

    bool found = false;

    for (int i = 0; i < courseCount; i++)
    {

        if (courses[i].currentEnrolled < courses[i].maxCapacity)
        {

            cout << "Course ID: " << courses[i].courseID << endl;
            cout << "Course Name: " << courses[i].courseName << endl;
            cout << "Instructor: " << courses[i].instructorName << endl;
            cout << "Schedule: " << courses[i].day << " at " << courses[i].time << endl;
            cout << "Available Seats: " << (courses[i].maxCapacity - courses[i].currentEnrolled) << endl;
            cout << "----------------------------------------" << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No courses are currently available for registration." << endl;
    }
}

// ===================== Register Courses Function =======================
void registerCourse(int studentIndex) {
    // Check if the student already has 10 courses.
    if (students[studentIndex].numCourses >= 10) {

        cout << "You reached the maximum limit" << endl;
        return;
    }

    int id;
    cout << "Enter Course ID to register: ";
    // ID (only number).
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID!Enter numbers only:";
    }

    int courseIndex = findCourse(id);
    // Ckeck if the course ID is exists in the system.
    if (courseIndex == -1) {

        cout << "course not found in the system" << endl;
        return;
    }

    // Check if there are available spaces in the course.
    if (courses[courseIndex].currentEnrolled >= courses[courseIndex].maxCapacity) {

        cout << "This course is full" << endl;
        return;
    }

    // Check if the student is already registered in this course.
    for (int i = 0; i < students[studentIndex].numCourses; i++) {
        if (students[studentIndex].registeredCourses[i] == id) {
            cout << "You are already registered in this course!" << endl;
            return;
        }
    }

    // Add the course to the student's list.
    students[studentIndex].registeredCourses[students[studentIndex].numCourses] = id;

    // Update counters for both student and course.
    students[studentIndex].numCourses++;
    courses[courseIndex].currentEnrolled++;

    cout << "Course Registered successfully" << endl;
}

// =================== Drop Courses Function =================
void dropcourses(int sIndex) {
    int id;
    cout << "Enter ID to drop: "; 
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID!Enter numbers only:";
    }

    int found = -1;
    for (int i = 0; i < students[sIndex].numCourses; i++) {

        if (students[sIndex].registeredCourses[i] == id) {
            
            found = i; break; 
        }
    }

    if (found != -1) {

        for (int i = found; i < students[sIndex].numCourses - 1; i++) {
            students[sIndex].registeredCourses[i] = students[sIndex].registeredCourses[i + 1];
        }
    
        students[sIndex].numCourses--;
        int cIdx = findCourse(id);
        if (cIdx != -1) {

            courses[cIdx].currentEnrolled--;
        }

        cout << "Course dropped successfullly." << endl;
    }
    else {
        cout << "Not found in your list." << endl;
    }
}

// ===================== View My Courses =========================
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
    system("pause");
}

// ====================== Logout Function ============================
bool studentLogout() {
    char confirm;
    while (true) {
        cout << "Are you sure you want to logout?(y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            cout << "Logging out successfully... Have a nice day!" << endl;
            system("pause");
            system("cls");
            return true;
        }

        else if (confirm == 'n' || confirm == 'N') {
            cout << "Returning to student menu" << endl;
            return false;
        }

        else {
            cout << "Invalid input! Please enter 'y' for Yes or 'n' for No." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}