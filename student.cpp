#include "globals.h"

// ================= LOGIN FUNCTION =================
int studentLogin() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        system("cls");
        int id;
        string password;

        cout << "\n============ STUDENT LOGIN ==============\n" << endl;
        cout << "\tEnter Student ID: ";
        while (!(cin >> id)) {
            cout << "\n\tInvalid ID! Please enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n');

        cout << "\n\tEnter Password: ";
        getline(cin, password);

        int index = findStudent(id, password);

        if (index != -1) {
            cout << "\n\tLogin Successful!";
            cout << "\tWelcome " << students[index].name
                << " (ID: " << students[index].studentID << ")" << endl;
            cout << "\t\t\t\t\tLevel: " << students[index].level << endl;

            system("pause");
            system("cls");

            return index;
        }
        else {
            cout << "\n\tInvalid Student ID or Password!" << endl;
            attempts++;
            if (attempts < MAX_ATTEMPTS) {
                cout << "\n\tAttempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
                system("pause");
            }
            else {
                cout << "\n\tToo many failed attempts. Try again later..." << endl;
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

    // ID (numbers only)
    cout << "\n\tEnter Student ID: ";
    while (!(cin >> s.studentID)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\tInvalid! ID must be numbers only. Try again: ";
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == s.studentID) {
            cout << "\n\tID already exists!" << endl;
            return;
        }
    }

    // Name (no numbers allowed)
    cin.ignore();
    cout << "\n\tEnter Name: ";
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
        cout << "\n\tInvalid! Name must be letters only. Try again: ";
        getline(cin, s.name);
    }

    // Password (anything allowed)
    cout << "\n\tEnter Password: ";
    getline(cin, s.password);

    // Level (1 to 4 only)
    cout << "\n\tEnter Level (1-4): ";
    while (!(cin >> s.level) || s.level < 1 || s.level > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\tInvalid! Level must be between 1 and 4. Try again: ";
    }

    s.numCourses = 0;
    for (int i = 0; i < 10; i++)
        s.registeredCourses[i] = 0;

    students[studentCount] = s;
    studentCount++;

    cout << "\n\tSign Up Successful!" << endl;
}

// ===================== Available Courses Function ===========================
void viewAvailableCourses() {
    cout << "\n========== VIEW AVAILABLE COURSES ============" << endl;

    bool found = false;

    for (int i = 0; i < courseCount; i++)
    {

        if (courses[i].currentEnrolled < courses[i].maxCapacity)
        {

            cout << "\tCourse ID      : " << courses[i].courseID << endl;
            cout << "\tCourse Name    : " << courses[i].courseName << endl;
            cout << "\tInstructor     : " << courses[i].instructorName << endl;
            cout << "\tSchedule       : " << courses[i].day << " at " << courses[i].time << endl;
            cout << "\tAvailable Seats: " << (courses[i].maxCapacity - courses[i].currentEnrolled) << endl;
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

        cout << "\n\tYou reached the maximum limit" << endl;
        return;
    }

    int id;
    cout << "\n\tEnter Course ID to register: ";
    // ID (only number).
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\tInvalid ID!Enter numbers only:";
    }

    int courseIndex = findCourse(id);
    // Ckeck if the course ID is exists in the system.
    if (courseIndex == -1) {

        cout << "\n\tcourse not found in the system" << endl;
        return;
    }

    // Check if there are available spaces in the course.
    if (courses[courseIndex].currentEnrolled >= courses[courseIndex].maxCapacity) {

        cout << "\n\tThis course is full" << endl;
        return;
    }

    // Check if the student is already registered in this course.
    for (int i = 0; i < students[studentIndex].numCourses; i++) {
        if (students[studentIndex].registeredCourses[i] == id) {
            cout << "\n\tYou are already registered in this course!" << endl;
            return;
        }
    }

    // Add the course to the student's list.
    students[studentIndex].registeredCourses[students[studentIndex].numCourses] = id;

    // Update counters for both student and course.
    students[studentIndex].numCourses++;
    courses[courseIndex].currentEnrolled++;

    cout << "\n\tCourse Registered successfully" << endl;
}

// =================== Drop Courses Function =================
void dropCourse(int sIndex) {
    int id;
    cout << "\n\tEnter ID to drop: "; 
    cin >> id;

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

        cout << "\n\tCourse dropped successfullly." << endl;
    }
    else {
        cout << "\n\tNot found in your list." << endl;
    }
}

// ===================== View My Courses =========================
void viewMyCourses(int studentIndex) {
    if (students[studentIndex].numCourses == 0) {
        cout << "\n\tNo registered courses yet.\n";
        return;
    }

    cout << "\n================ My Registered Courses ==================\n";

    for (int i = 0; i < students[studentIndex].numCourses; i++) {
        int courseID = students[studentIndex].registeredCourses[i];
        int c = findCourse(courseID);

        if (c != -1) {
            cout << "\tCourse ID   : " << courses[c].courseID << endl;
            cout << "\tCourse Name : " << courses[c].courseName << endl;
            cout << "\tInstructor  : " << courses[c].instructorName << endl;
            cout << "\tCredit Hours: " << courses[c].creditHours << endl;
            cout << "\tDay         : " << courses[c].day << endl;
            cout << "\tTime        : " << courses[c].time << endl;
            cout << "--------------------------------------\n";
        }
    }
    system("pause");
}

// ====================== Logout Function ============================
bool studentLogout() {
    char confirm;
    while (true) {
        cout << "\n\tAre you sure you want to logout?(y/n): ";
        cin >> confirm;
        cin.ignore(100, '\n');

        if (confirm == 'y' || confirm == 'Y') {
            cout << "\n\tLogging out successfully... Have a nice day!" << endl;
            system("pause");
            system("cls");
            return true;
        }

        else if (confirm == 'n' || confirm == 'N') 
            return false;

        else {
            cout << "\n\tInvalid input! Please enter 'y' for Yes or 'n' for No." << endl;
            cin.clear();
        }
    }
}