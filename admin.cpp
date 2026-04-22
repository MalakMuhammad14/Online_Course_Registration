#include "globals.h"

void adminLogin() {

}

//  ============== Add Course Function =================
void addCourse() {
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

        // Clear the buffer before reading strings to use getline() correctly.
        cin.ignore();
        // Input course and instructor names.
        string courseName;
        cout << "Enter Course Name: " << endl;
        getline(cin, courseName);
        courses[courseCount].courseName = courseName;

        string instructorName;
        cout << "Enter Instructor Name: " << endl;
        getline(cin, instructorName);
        courses[courseCount].instructorName = instructorName;

        // Input credit hours and capacity.
        int creditHours;
        cout << "Enter Credit Hours: " << endl;
        cin >> creditHours;
        courses[courseCount].creditHours = creditHours;

        int maxCapacity;
        cout << "Enter Maximum Capacity: " << endl;
        cin >> maxCapacity;
        courses[courseCount].maxCapacity = maxCapacity;

        // Clear buffer again and input schedule details.
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

        // Update total courses.
        courseCount += 1;

        cout << "Course " << courseName << " added successfully!" << endl;
    }
    else {
        // Error message if the array is full.
        cout << "Unable to add new course. System capacity is full." << endl;
    }
}

void editCourse() {

}

void deleteCourse() {

}

void viewAllStudents() {

}

void logoutAdmin() {

}