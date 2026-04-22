#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_COURSES = 20;
const int MAX_ADMINS = 3;

// ================= STRUCTS =================
struct Student {
    int studentID;
    string name;
    string password;
    int level;
    int registeredCourses[10];
    int numCourses;
};

struct Course {
    int courseID;
    string courseName;
    string instructorName;
    int creditHours;
    int maxCapacity;
    int currentEnrolled;
    string day;
    string time;
};

struct Admin {
    int adminID;
    string name;
    string password;
};

// ================= GLOBAL ARRAYS =================
extern Student students[MAX_STUDENTS];
extern Course courses[MAX_COURSES];
extern Admin admins[MAX_ADMINS];

extern int studentCount;
extern int courseCount;
extern int adminCount;

// ================= DECLERATION FUNCTION ==================
void showWelcome();
void mainMenu();
void studentMenu();
void studentFunctionMenu();
int studentLogin();
void studentSignUp();
void initData();
int findCourse(int id);
int findStudent(int id, string pass);
void viewAvailableCourses();