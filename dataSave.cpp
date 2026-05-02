#include "globals.h"
#include <fstream>

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
Admin admins[MAX_ADMINS];

int studentCount = 0;
int courseCount = 0;
int adminCount = 0;

// ================= HELPERS =================
int findStudent(int id, string pass) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].studentID == id && students[i].password == pass)
            return i;
    return -1;
}

int findAdmin(int id, string pass) {
    for (int i = 0; i < adminCount; i++)
        if (admins[i].adminID == id && admins[i].password == pass)
            return i;
    return -1;
}

int findCourse(int id) {
    for (int i = 0; i < courseCount; i++)
        if (courses[i].courseID == id)
            return i;
    return -1;
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

// =============== INITIAL DATA (DEFAULT) =================
void initData() {
    students[0] = { 1, "Ali", "123", 1, {0}, 0 };
    students[1] = { 2, "Omar", "123", 2, {0}, 0 };
    studentCount = 2;

    courses[0] = { 101, "Math", "Dr.Ahmed", 3, 30, 0, "Sun", "10AM" };
    courses[1] = { 102, "CS", "Dr.Samy", 3, 25, 0, "Mon", "12PM" };
    courses[2] = { 103, "English", "Dr.Emad", 2, 35, 0, "Tue", "2PM" };
    courseCount = 3;

    admins[0] = { 1, "Admin", "admin123" };
    adminCount = 1;
}

void saveAllData() {

    ofstream sFile("students.txt");
    sFile << studentCount << endl;
    for (int i = 0; i < studentCount; i++) {
        sFile << students[i].studentID << "|" << students[i].name << "|" << students[i].password
            << "|" << students[i].level << "|" << students[i].numCourses;
        for (int j = 0; j < students[i].numCourses; j++) sFile << "|" << students[i].registeredCourses[j];
        sFile << endl;
    }
    sFile.close();


    ofstream cFile("courses.txt");
    cFile << courseCount << endl;
    for (int i = 0; i < courseCount; i++) {
        cFile << courses[i].courseID << "|" << courses[i].courseName << "|" << courses[i].instructorName
            << "|" << courses[i].creditHours << "|" << courses[i].maxCapacity
            << "|" << courses[i].currentEnrolled << "|" << courses[i].day << "|" << courses[i].time << endl;
    }
    cFile.close();


    ofstream aFile("admins.txt");
    aFile << adminCount << endl;
    for (int i = 0; i < adminCount; i++) {
        aFile << admins[i].adminID << "|" << admins[i].name << "|" << admins[i].password << endl;
    }
    aFile.close();
}


void loadAllData() {
    ifstream sFile("students.txt");
    if (sFile.is_open()) {
        sFile >> studentCount;
        for (int i = 0; i < studentCount; i++) {
            sFile >> students[i].studentID; 
            sFile.ignore();
            getline(sFile, students[i].name, '|');
            getline(sFile, students[i].password, '|');
            sFile >> students[i].level;
            sFile.ignore();
            sFile >> students[i].numCourses;

            for (int j = 0; j < students[i].numCourses; j++) {
                sFile.ignore();
                sFile >> students[i].registeredCourses[j]; 
            }
        }
        sFile.close();
    }

    ifstream cFile("courses.txt");
    if (cFile.is_open()) {
        cFile >> courseCount;
        for (int i = 0; i < courseCount; i++) {
            cFile >> courses[i].courseID;
            cFile.ignore();
            getline(cFile, courses[i].courseName, '|');
            getline(cFile, courses[i].instructorName, '|');
            cFile >> courses[i].creditHours;
            cFile.ignore();
            cFile >> courses[i].maxCapacity;
            cFile.ignore();
            cFile >> courses[i].currentEnrolled;
            cFile.ignore();
            getline(cFile, courses[i].day, '|');
            getline(cFile, courses[i].time);
        }
        cFile.close();
    }

    ifstream aFile("admins.txt");
    if (aFile.is_open()) {
        aFile >> adminCount;
        for (int i = 0; i < adminCount; i++) {
            aFile >> admins[i].adminID;
            aFile.ignore();
            getline(aFile, admins[i].name, '|');
            getline(aFile, admins[i].password);
        }
        aFile.close();
    }
}