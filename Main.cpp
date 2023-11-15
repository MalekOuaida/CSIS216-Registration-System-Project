//authors: Faysal el Estwani, Maya Masri, Malek Ouaida

#include <iostream>
#include <fstream>
#include <istream>
#include "Student.h"
#include "Course.h"
#include "LListWithDummyNode.h"
#include "DoublyLinkedList.h"

using namespace std;

void displayMenu();
void registerStudent(const string& studentID, const string& code, LListWithDummyNode& offeredCourses,
    DoublyLinkedList& registeredStudents, DoublyLinkedList& nonRegisteredStudents);

int main() {
    DoublyLinkedList nonRegisteredStudents;
    DoublyLinkedList registeredStudents;
    ifstream studentFile("Student.txt");

    if (!studentFile.is_open()) {
        cerr << "Error opening file 'students.txt'" << endl;
        return -1;
    }

    Student newStudent;
    string studentID, code;

    int numStudents;
    studentFile >> numStudents;


    for (int i = 0; i < numStudents; ++i) {
        studentFile >> newStudent;
        nonRegisteredStudents.insertSorted(newStudent);
    }

    studentFile.close();


    ifstream courseFile("Course.txt");
    if (!courseFile.is_open()) {
        cerr << "Error opening file 'courses.txt'" << endl;
        return -1;
    }

    int numCourses;
    courseFile >> numCourses;


    LListWithDummyNode offeredCourses;

    Course newCourse;
    for (int i = 0; i < numCourses; ++i) {
        courseFile >> newCourse;
        offeredCourses.addCourse(newCourse);
    }

    courseFile.close();

    bool isRunning = true;
    int choice;

    while (isRunning) {
        displayMenu();
        cin >> choice;
        while (choice < 1 || choice > 10) {
            cout << "Invalid choice. Please enter a number between 1 and 10." << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            // Displays the students who did not register yet
            cout << "\nStudents that didn’t register yet:" << endl;
            cout << nonRegisteredStudents;
            break;
        case 2:
            // Displays the list of courses
            cout << "\nList of Offered Courses:" << endl;
            cout << offeredCourses;
            break;
        case 3: {
            // Displays the list of registered students with the registered courses
            // If the doublyllist of registered students is empty, displays no students registered
            if (registeredStudents.getSize() == 0) {
                cout << "No students registered yet." << endl;
            }
            else //if the doublyllist of registered students is not empty
                // Iterate through the registered students doubly llist
                for (int i = 0; i < registeredStudents.getSize(); i++) {
                    Student* stu = registeredStudents.getatpos(i);
                    cout << "Student: " << stu->getID() << " - " << stu->getLastName() << "," << stu->getFirstName() << endl;
                    stu->listCourses(cout); //display the registered courses for each student
                }
            break;
        }
        case 4: {
            // Display the list of offered courses with the registered students
            // Iterate through the linked list of offered courses
            for (int i = 0; i < offeredCourses.getSize(); i++) {
                Course* course = offeredCourses.getatposLL(i);
                cout << "Course: " << course->getCode() << " - " << course->getName() << endl;
                course->displayStudents(); //display the students registered in each course
                cout << endl;
            }
            break;
        }
        case 5: {
            // Display the registered courses for a student
            cout << "Enter student ID: ";
            cin >> studentID;
            // Search for the student in the registered students doubly llist
            Student* stu = registeredStudents.findByIDForDD(studentID);
            // if student not found in the registered students doubly llist
            if (stu == NULL) {
                cout << "Student " << studentID << " is not registered in any course." << endl;
                break;
            }
            // if student is found, display the information of the student
            cout << studentID << " - " << stu->getFirstName() << " " << stu->getLastName() << endl;
            cout << "Courses: " << endl;
            stu->listCourses(cout); // display the courses registered by the student
            cout << endl;
            break;
        }
        case 6: {
            // Display the list of students registered in a course
            cout << "Enter the course code: ";
            cin >> code;
            Course* course = offeredCourses.searchCourseById(code);
            // if course not found
            if (course == NULL) {
                cout << "Course not offered." << endl;
                break;
            }
            // if course found
            cout << "Course: " << code << " - " << course->getName() << endl;
            course->displayStudents(); //display students in the course
            break;
        }
        case 7: {
            // Display the information related to a specific student
            cout << "Enter the student ID: ";
            cin >> studentID;
            Student* stu = nonRegisteredStudents.findByIDForDD(studentID);
            // if student not found in the nonregistered students doubly llist search in the registered students
            if (stu == NULL)
                stu = registeredStudents.findByIDForDD(studentID);
            // if student not found in any doubly llist, exit case 7
            if (stu == NULL) {
                cout << "Student ID " << studentID << " not found." << endl;
                break;
            }
            // if student found, display its information
            stu->display(cout);
            break;
        }
        case 8: {
            // Register a student
            char add;
            cout << "Enter the student ID: ";
            cin >> studentID;
            do {
                cout << "Enter the course code: ";
                cin >> code;
                // call the register student method
                registerStudent(studentID, code, offeredCourses, registeredStudents, nonRegisteredStudents);
                cout << "\nDo you need to add more courses [Y] yes or [N] no: ";
                cin >> add;
                // if character different than Y, y, n and N
                while (add != 'Y' && add != 'y' && add != 'n' && add != 'N') {
                    cout << "Invalid character. Enter [Y] for yes or [N] for no: ";
                    cin >> add;
                }
            } while (add == 'Y' || add == 'y'); //exit the loop when the answer is N or n
            break;
        }
        case 9: {
            // Choose a student to add/drop a course for him/her
            cout << "Enter student ID: ";
            cin >> studentID;
            Student* stu = registeredStudents.findByIDForDD(studentID);
            // if student not registered yet exit from case 9
            if (stu == NULL) {
                cout << "Student not registered yet." << endl;
                break;
            }
            // if student registered, display the courses registered by the student
            cout << studentID << " - " << stu->getFirstName() << " " << stu->getLastName() << endl;
            cout << "Courses: " << endl;
            stu->listCourses(cout);
            char cont, aORd;
            do {
                // choose if the user wants to Add or Drop a course
                cout << "Add course [A] or Drop course [D]: ";
                cin >> aORd;
                // if the character is different than a, A, d and D
                while (aORd != 'A' && aORd != 'a' && aORd != 'd' && aORd != 'D') {
                    cout << "Invalid character. Enter [A] to Add or [D] to drop course: ";
                    cin >> aORd;
                }
                cout << "Choose course code: ";
                cin >> code;
                // if the user wants to add a course
                if (aORd == 'A' || aORd == 'a') {
                    // call the registerStudent method
                    registerStudent(studentID, code, offeredCourses, registeredStudents, nonRegisteredStudents);
                }
                else {
                    // if the user wants to drop a course
                    // if the course is registered by the user, remove the course
                    if (stu->removeCourse(code)) {
                        Course* course = offeredCourses.searchCourseById(code); // find the course in the offeredcourses llist
                        course->dropStudent(studentID); //drop student from the course
                        cout << "Course dropped successfully.\n\n" << endl;
                    }
                    else // if the course is not registered by the user
                        cout << "Course not found.\n\n";
                }
                cout << "Do you want to continue [Y] yes or [N] no: ";
                cin >> cont;
                // if the user entered a charactered different than y, Y, n or N
                while (cont != 'Y' && cont != 'y' && cont != 'n' && cont != 'N') {
                    cout << "Invalid character. Enter [Y] for yes or [N] for no: ";
                    cin >> cont;
                }
            } while (cont == 'Y' || cont == 'y'); //exit loop when n or Nis entered
            break;
        }
        case 10:
            // Quit application
            cout << "Exiting app.";
            isRunning = false;
            break;

        }

    }

    return 0;
}

void displayMenu() {
    cout << "\n1. Display the list of non-registered students.\n";
    cout << "2. Display the list of offered courses.\n";
    cout << "3. Display the list of registered students with the registered courses.\n";
    cout << "4. Display the list of offered courses with the registered students.\n";
    cout << "5. Display the registered courses for a student.\n";
    cout << "6. Display the list of students registered in a course.\n";
    cout << "7. Display the information related to a specific student.\n";
    cout << "8. Register a student.\n";
    cout << "9. Choose a student to add/drop a course for him/her.\n";
    cout << "10. Quit the application.\n";
    cout << "\nEnter your choice: ";
}

void registerStudent(const string& studentID, const string& code, LListWithDummyNode& offeredCourses, DoublyLinkedList& registeredStudents, DoublyLinkedList& nonRegisteredStudents) {
    // Search for the course by its code
    Course* app = offeredCourses.searchCourseById(code);
    if (app == NULL) {
        cout << "Course " << code << " is not offered." << endl;
        return;
    }

    // Find the student in the non-registered list
    Student* stu = nonRegisteredStudents.findByIDForDD(studentID);


    // If not found, find in the registered list
    if (stu == NULL) {
        stu = registeredStudents.findByIDForDD(studentID);
    }

    // Check if student was found in any list
    if (stu == NULL) {
        cout << "Student ID " << studentID << " not found." << endl;
        return;
    }

    // Enroll the student in the course if not full
    if (app->enrollStudent(studentID)) {
        cout << "Student " << studentID << " enrolled in course " << code << "." << endl;
        stu->addCourse(*app); // Add the course to the student's list of courses
        if (stu == nonRegisteredStudents.findByIDForDD(studentID)) {
            registeredStudents.insertSorted(*stu); // Insert into registered list
            nonRegisteredStudents.deleteSorted(studentID); // Remove from non-registered list
        }
    }
    else {
        cout << "Could not enroll Student " << studentID << " in course " << code << "." << endl;
    }
}
