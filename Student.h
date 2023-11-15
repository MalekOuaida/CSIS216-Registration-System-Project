//author: Nassif Kareh

/**
 *
 * class Student
 *
 * Represents a student with their academic details.
 *
 * This class provides functionalities to set and get details of a student.
 * It encapsulates details such as student ID, first name, last name, gpa,
 * academic status, and the courses in which the student is enrolled.
 *
 * Created by Nassif Kareh
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <istream>
#include "Course.h"

using namespace std;

class Student {
public:

    /**
     * Function: Student (default constructor)
     * Purpose: Initialize a student object with default values.
     * Precondition: None.
     * Post-condition: A Student object is created with empty ID, names, GPA of 0.0,
     * and academic status updated according to the GPA.
     */
    Student();

    /**
     * Function: Student (parameterized constructor)
     * Purpose: Initialize a student object with given values.
     * Precondition: gpa should be a value between 0.0 and 4.0.
     * Post-condition: A Student object is created with the provided ID, names, GPA,
     * and academic status updated according to the GPA.
     */
    Student(const string& id, const string& first, const string& last, double gpa);

    /**
     * Function: Student (copy constructor)
     * Purpose: Initialize a student object as a copy of another student object.
     * Precondition: An existing Student object.
     * Post-condition: A new Student object is created with the same properties as
     * the other Student object.
     */
    Student(const Student& other);

    /**
     * Destructor: ~Student
     * Purpose: Deallocates any dynamic memory associated with the student.
     * Precondition: A dynamically allocated Student object.
     * Post-condition: The Student object is properly cleaned up to prevent memory leaks.
     */
    ~Student();

    /**
     * Operator: =
     * Purpose: Assigns one Student object the values of another.
     * Precondition: Two existing Student objects.
     * Post-condition: The left-hand side Student object has the same values as the right-hand side object.
     */
    Student& operator=(const Student& other);

    // Accessor methods

    /**
     * Function: getID
     * Purpose: Retrieve the student's ID.
     * Precondition: None.
     * Post-condition: Returns the student's ID as a string.
     */
    string getID() const;

    /**
     * Function: getFirstName
     * Purpose: Retrieve the student's first name.
     * Precondition: None.
     * Post-condition: Returns the student's first name as a string.
     */
    string getFirstName() const;

    /**
     * Function: getLastName
     * Purpose: Retrieve the student's last name.
     * Precondition: None.
     * Post-condition: Returns the student's last name as a string.
     */
    string getLastName() const;

    int getNbCourses() const;
    /**
     * Function: getGpa
     * Purpose: Retrieve the student's GPA.
     * Precondition: None.
     * Post-condition: Returns the student's GPA as a double.
     */
    double getGpa() const;

    /**
     * Function: getAcademicStatus
     * Purpose: Retrieve the student's academic status.
     * Precondition: None.
     * Post-condition: Returns the student's academic status as a string.
     */
    string getAcademicStatus() const;

    // Mutator methods

    /**
     * Function: setID
     * Purpose: Set the student's ID.
     * Precondition: The provided string should not be empty for a valid ID.
     * Post-condition: The student's ID is updated to the provided string.
     */
    void setID(const string& id);

    /**
     * Function: setFirstName
     * Purpose: Set the student's first name.
     * Precondition: The provided string should not be empty for a valid first name.
     * Post-condition: The student's first name is updated to the provided string.
     */
    void setFirstName(const string& first);

    /**
     * Function: setLastName
     * Purpose: Set the student's last name.
     * Precondition: The provided string should not be empty for a valid last name.
     * Post-condition: The student's last name is updated to the provided string.
     */
    void setLastName(const string& last);

    /**
     * Function: setGpa
     * Purpose: Set the student's GPA.
     * Precondition: The provided double should be between 0.0 and 4.0.
     * Post-condition: The student's GPA is updated to the provided double, and
     * the academic status is updated accordingly.
     */
    void setGpa(double gpa);

    /**
    * Function: setStudent
    * Purpose: Sets the student's ID, first name, last name, and GPA with the provided values.
    * Precondition: The id should not be an empty string, the first and last names should be valid non-empty strings,
    *               and the newGpa should be a double value between 0.0 and 4.0.
    * Post-condition: The student's ID, first name, last name, and GPA are updated to the provided values,
    *                 and the academic status is updated according to the new GPA.
    */
    void setStudent(const string& id, const string& first, const string& last, double newGpa);

    // Other methods

    /**
     * Function: addCourse
     * Purpose: Adds a new course to the student's course list.
     * Precondition: A valid Course object provided and sufficient capacity in the courses array.
     * Post-condition: The course is added to the student's list of courses, and the number of courses is incremented.
     */
    void addCourse(const Course& course);

    /**
     * Function: removeCourse
     * Purpose: Removes a course from the student's course list based on the course code.
     * Precondition: A valid course code that exists in the student's current course list.
     * Post-condition: The course is removed from the student's list of courses, and the number of courses is decremented.
     */
    bool removeCourse(const string& courseCode);

    /**
     * Function: listCourses
     * Purpose: Outputs a list of courses the student is currently enrolled in to a provided stream.
     * Precondition: An ostream object is available to receive the course listing.
     * Post-condition: The student's course list is sent to the provided ostream.
     */
    void listCourses(ostream& os) const;

    /**
    * Function: display
    * Purpose: Outputs the student's details including ID, name, GPA, and academic status to a provided stream.
    * Precondition: An ostream object is available to receive the student's details.
    * Post-condition: The student's details are sent to the provided ostream, formatted for display.
    */
    void display(ostream& os) const;

private:
    string studentID;        // Student's ID
    string firstName;        // Student's first name
    string lastName;         // Student's last name
    double gpa;              // Student's grade point average
    string academicStatus;   // Student's academic status
    Course* coursesEnrolled; // Pointer to array of Course objects
    int numberOfCourses;     // Number of courses student is currently enrolled in
    int coursesCapacity;     // Capacity of the courses array

    /**
     * Function: updateAcademicStatus
     * Purpose: Updates the academic status based on the current GPA.
     * Precondition: None.
     * Post-condition: academicStatus is set to "Probation" if GPA is below 2.0,
     * otherwise, it is set to "Regular".
     */
    void updateAcademicStatus();

};

/**
* Operator: <<
* Purpose: Overloads the output stream operator to output the student's details.
* Precondition: An ostream object is available and a valid Student object exists.
* Post-condition: The student's details are output to the provided ostream, using the display function.
*/
ostream& operator<<(ostream& os, const Student& student);

/**
* Operator: >>
* Purpose: Overloads the input stream operator to input the student's details from the user.
* Precondition: An istream object is ready to receive input, and a valid Student object exists to store the input data.
* Post-condition: The student's ID, first name, last name, and GPA are set to the values input by the user.
*/
istream& operator>>(istream& in, Student& student);

#endif //STUDENT_H
