/*-- Course.cpp------------------------------------------------------------

   This file implements the Course member functions.

-------------------------------------------------------------------------*/

#include "Course.h"
#include <iostream>
using namespace std;

// Default Constructor
Course::Course() {
    setCourse("0", " ", 1, 5);
}

// Consturctor that takes explicit values
Course::Course(string courseCode, string courseName, int courseCredits, int courseCapacity) {
    //Calls the setCourse method
    setCourse(courseCode, courseName, courseCredits, courseCapacity);
}

// Copy Constructor
Course::Course(const Course& orig) {
    // Sets the Course information equal to the original Course
    code = orig.code;
    name = orig.name;
    credits = orig.credits;
    capacity = orig.capacity;
    // Creates an empty dynamic array with the given capacity
    enrolled = new string[capacity];
    enrolledCount = orig.enrolledCount;
    // Iterate through the array Enrolled to copy each element
    for (int i = 0; i < enrolledCount; i++)
        enrolled[i] = orig.enrolled[i];
}

// Destructor
Course::~Course() {
    // realease memory allocated for the dynamic array
    delete[] enrolled;
}

//Function: getCode
string Course::getCode() const {
    return code; //returns the course code
}

// Function: getName
string Course::getName() const {
    return name; //returns the course name
}

// Function: getCredits
int Course::getCredits() const {
    return credits; //returns the course number of credits
}

// Function: getCapacity
int Course::getCapacity() const {
    return capacity; //returns the course capacity
}

// Function: getNumEnrolled
int Course::getNumEnrolled() const {
    return enrolledCount; //returns the enrolledCount in the course
}

// Function: setCode
void Course::setCode(string courseCode) {
    // convert code to upper case
    for (int i = 0; i < courseCode.length(); i++)
        courseCode[i] = toupper(courseCode[i]);
    code = courseCode;
}

// Function: setName
void Course::setName(string courseName) {
    name = courseName;
}

// Fucntion: setCredits
void Course::setCredits(int courseCredits) {
    // Check if number of credits is >0
    if (courseCredits <= 0)
        credits = 1;
    else
        credits = courseCredits;
}

// Function: setCapacity
void Course::setCapacity(int courseCapacity) {
    // Sets the capacity minimum to 5
    if (courseCapacity < 5)
        capacity = 5;
    else
        capacity = courseCapacity;
}

// Function: setCourse
void Course::setCourse(string courseCode, string courseName, int courseCredits, int courseCapacity) {
    // Calls the setters
    setCode(courseCode);
    setName(courseName);
    setCredits(courseCredits);
    setCapacity(courseCapacity);

    // Initialize the enrolled dynamic array with the given capacity
    enrolled = new string[capacity];
    enrolledCount = 0; //sets the enrolledCount to 0
}

// Function: enrollStudent
bool Course::enrollStudent(const string& studentID) {
    // Check if enrolledCount < capacity to enroll student
    if (enrolledCount < capacity) {
        // add student to course
        enrolled[enrolledCount] = studentID;
        enrolledCount++; //increment enrolledCount
        return true;
    }
    // else - if enrolled > or = capacity
    cout << "Course is full. Unable to enroll student: " << studentID << endl;
    return false;
}

// Function: dropStudent
bool Course::dropStudent(const string& studentID) {
    // Check if no students in the course
    if (enrolledCount == 0) {
        cout << "No students registered in the course." << endl;
        return false;
    }
    // else if there are students registered in the course
    // Iterate through the enrolled array 
    for (int pos = 0; pos < enrolledCount; pos++) {
        // if student ID is found
        if (enrolled[pos] == studentID) {
            for (int j = pos; j < enrolledCount; j++)
                enrolled[j] = enrolled[j + 1]; // shift the remaining elements to fill the gap
            enrolledCount--; // decrement enrolledCount
            return true;
        }
    }
    // if student ID not found
    cout << "Student not found in the course." << endl;
    return false;
}

// Function: display
void Course::display(ostream& out) const {
    //Displays the course information
    out << "Course Code: " << code << endl;
    out << "Course Name: " << name << endl;
    out << "Credits: " << credits << endl;
    out << "Enrolled: " << enrolledCount << "/" << capacity << endl;
}

// Function: dsiplayStudents
void Course::displayStudents() const {
    // if there is students in the course
    if (enrolledCount > 0) {
        // iterate through the enrolled array and display the students ID
        for (int i = 0; i < enrolledCount; i++) {
            cout << (i + 1) << ". " << enrolled[i] << endl;
        }
    }
    // if no students in the course
    else {
        cout << "No registered students." << endl;
    }
}

// Operator Overload: <<
ostream& operator<<(ostream& out, const Course& c) {
    c.display(out); // Dsiplay the course information
    return out;
}

// Operator Overload: >>
// Overloads the input stream operator to input Course infromation
istream& operator>>(istream& in, Course& course) {
    string code, name;
    int credits, capacity;

    // read course code
    in >> code;
    in >> ws; //avoid spaces

    // stops when a digit is encountered
    while (!isdigit(in.peek())) {
        name += (char)in.get();
    }

    //read course credits and capacity
    in >> credits;
    in >> capacity;

    //setCourse with the given information
    course.setCourse(code, name, credits, capacity);

    cout << course;

    return in;
}

// Overload Operator ==
// returns true if 2 courses have the same code
bool Course::operator==(const Course& rhscourse) {
    return code == rhscourse.code;
}