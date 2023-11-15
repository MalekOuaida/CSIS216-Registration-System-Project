/*-- Course.h ----------------------------------------------------------------------

  This header file defines the data type Course for representing academic courses.
  Basic operations are:
     Constructors
     Copy constructor
     Destructor
     Assignment operator
     Accessors:       getCode, getName, getCredits, getCapacity, getEnrolledCount
     Setters:         setCode, setName, setCredits, setCapacity, setCourse
     enrollStudent:   To add student to course
     dropStudent:     To remove student from course
     display:         To display the course information
     displayStudents: To display the ID of students enrolled in the course
     >>, <<:          Input and Output operators
     relops:          ==

----------------------------------------------------------------------------------*/

#ifndef COURSE_H
#define COURSE_H


#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    /***** Function Members *****/
    /*** Class constructors ***/
    Course();
    /*-------------------------------------------------------------------------
         Constructs a Course object (default).

         Precondition:  None.
         Postcondition: Course object is initialized with default values;
            that is,code, name, credits, and capacity are initialized
            to "0", " ", 1, 5, respectively. The enrolled array is created
            with capacity of 5, and enrolledCount is set to 0.
    -------------------------------------------------------------------------*/

    Course(string, string, int, int);
    /*-------------------------------------------------------------------------
         Constructs a Course object (explicit values).

         Precondition:  courseCode, courseName, courseCredits, courseCapacity
            are initial values for the data members; they must preserve the
            class invariant.
         Postcondition: Data members code, name, credits, capacity,
            have been initialized to courseCode, courseName, courseCredits,
             courseCapacity respectively. The enrolled array is created with a
             capacity of courseCapacity, and enrolledCount is set to 0.
    -------------------------------------------------------------------------*/


    Course(const Course&);
    /*-------------------------------------------------------------------------
         Copy constructer.

         Precondition:  The existence of a valid Course object with
            initialized values.
         Postcondition: A copy of an original Course object has been
            constructed.
    -------------------------------------------------------------------------*/

    /*** Class destructor ***/
    ~Course();
    /*-------------------------------------------------------------------------
         Destructs a Course object.

         Precondition:  The existance of a valid Course object.
         Postcondition: Deallocates the memory used by the 'enrolled' array
    -------------------------------------------------------------------------*/

    /*** Accessors ***/
    string getCode() const;
    /*-------------------------------------------------------------------------
         Retrieve the value stored in the code data member.

         Precondition:  None.
         Postcondition: Value stored in code is returned.
    -------------------------------------------------------------------------*/

    string getName() const;
    /*-------------------------------------------------------------------------
         Retrieve the value stored in the name data member.

         Precondition:  None.
         Postcondition: Value stored in name is returned.
    -------------------------------------------------------------------------*/

    int getCredits() const;
    /*-------------------------------------------------------------------------
         Retrieve the value stored in the credits data member.

         Precondition:  None.
         Postcondition: Value stored in credits is returned.
    -------------------------------------------------------------------------*/

    int getCapacity() const;
    /*-------------------------------------------------------------------------
         Retrieve the value stored in the capacity data member.

         Precondition:  None.
         Postcondition: Value stored in capacity is returned.
    -------------------------------------------------------------------------*/

    int getNumEnrolled() const;
    /*-------------------------------------------------------------------------
         Retrieve the value stored in the enrolledCount data member.

         Precondition:  None.
         Postcondition: Value stored in enrolledCount is returned.
    -------------------------------------------------------------------------*/

    /*** Setters ***/
    void setCode(string);
    /*-------------------------------------------------------------------------
          Set the data member code of a Course object to specified value.

          Preconditions: None.
          Postconditon:  Data member code is set to courseCode.
    -------------------------------------------------------------------------*/

    void setName(string);
    /*-------------------------------------------------------------------------
          Set the data member name of a Course object to specified value.

          Preconditions: None.
          Postconditon:  Data member name is set to courseName.
    -------------------------------------------------------------------------*/

    void setCredits(int);
    /*-------------------------------------------------------------------------
          Set the data member credits of a Course object to specified value.

          Preconditions: 1 <= courseCredits.
          Postconditon:  Data member credits is set to courseCredits.
    -------------------------------------------------------------------------*/

    void setCapacity(int);
    /*-------------------------------------------------------------------------
          Set the data member capacity of a Course object to specified value.

          Preconditions: 5 <= courseCapacity.
          Postconditon:  Data member capacity is set to courseCapacity.
    -------------------------------------------------------------------------*/

    void setCourse(string, string, int, int);
    /*-------------------------------------------------------------------------
          Set all the data members of a Course object to specified value.

          Preconditions: None.
          Postconditon:  Data members are set to specified values. Allocates
             a new memory for the enrolled array with the given capacity
             and initializes enrolledCount to 0.
    -------------------------------------------------------------------------*/

    /*** Add student to the course ***/
    bool enrollStudent(const string&);
    /*-------------------------------------------------------------------------
          Add a student ID to the enrolled array.

          Preconditions: The existance of a Course object.
          Postconditon:  Checks if the student is already enrolled; if so,
             outputs a message and returns false. If there is space available,
             adds the student to the enrolled array, increments enrolledCount,
             and returns true. If the course is full, outputs a message and
             returns false.
    -------------------------------------------------------------------------*/

    /*** Remove student from the course***/
    bool dropStudent(const string&);
    /*-------------------------------------------------------------------------
          Remove a student ID to the enrolled array.

          Preconditions: The existance of a Course object.
          Postconditon:  If there are no students registered in the course,
            outputs a message and returns false. If the student is found,
            removes the student from the enrolled array, shifts the remaining
            students to fill the gap, decrements enrolledCount, and returns
            true. If the student is not found, outputs a message and returns
            false.
    -------------------------------------------------------------------------*/

    /*** Output ***/
    void display(ostream&) const;
    /*-------------------------------------------------------------------------
      Display course information using output stream out.

      Precondition:  The ostream out is open.
      Postcondition: Outputs the course information.
    -------------------------------------------------------------------------*/

    void displayStudents() const;
    /*-------------------------------------------------------------------------
      Display enrolled students.

      Precondition:  The ostream out is open.
      Postcondition: If there are enrolled students in the course, outputs
            the list of enrolled students. If no students are enrolled,
            outputs a message indicating that there are no registered students.
    -------------------------------------------------------------------------*/

    /*** Relational operators ***/
    bool operator==(const Course&);
    /*----------------------------------------------------------------------
       Determine if one Course object is equal to another Course object.

       Precondition:  None.
       Postcondition: true is returned if courseCode1 is equal to
            courseCode2 and false otherwise.
    ----------------------------------------------------------------------*/
private:
    /*** Data Members ***/
    string code;           //course code
    string name;           //course name
    int credits;           //course number of credits
    int capacity;          //the maximum number of students
    string* enrolled;      //array of students ID enrolled in the course
    int enrolledCount;     //total number of students enrolled in the course
};

//----- << and >> operators
ostream& operator<<(ostream&, const Course&);
istream& operator>>(istream&, Course&);

#endif // COURSE_H