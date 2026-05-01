#include "globals.h"

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