//author: Nassif Kareh
#include "Student.h"


Student::Student()
    : studentID(""), firstName(""), lastName(""), gpa(0.0), numberOfCourses(0), coursesCapacity(10) {
    coursesEnrolled = new Course[coursesCapacity];
    updateAcademicStatus();
}

Student::Student(const string& id, const string& first, const string& last, double gpa)
    : studentID(id), firstName(first), lastName(last), gpa(gpa), numberOfCourses(0), coursesCapacity(10) {
    coursesEnrolled = new Course[coursesCapacity];
    updateAcademicStatus();
}

Student::Student(const Student& other)
    : studentID(other.studentID), firstName(other.firstName), lastName(other.lastName),
    gpa(other.gpa), academicStatus(other.academicStatus),
    numberOfCourses(other.numberOfCourses), coursesCapacity(other.coursesCapacity) {
    coursesEnrolled = new Course[coursesCapacity];
    for (int i = 0; i < numberOfCourses; ++i) {
        coursesEnrolled[i] = other.coursesEnrolled[i];
    }
}

Student::~Student() {
    delete[] coursesEnrolled;
}


Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] coursesEnrolled;

        studentID = other.studentID;
        firstName = other.firstName;
        lastName = other.lastName;
        gpa = other.gpa;
        academicStatus = other.academicStatus;
        numberOfCourses = other.numberOfCourses;
        coursesCapacity = other.coursesCapacity;

        coursesEnrolled = new Course[coursesCapacity]{};
        for (int i = 0; i < numberOfCourses; ++i) {
            coursesEnrolled[i] = other.coursesEnrolled[i];
        }
    }
    return *this;
}

string Student::getID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

int Student::getNbCourses() const
{
    return numberOfCourses;
}

double Student::getGpa() const {
    return gpa;
}

string Student::getAcademicStatus() const {
    return academicStatus;
}

void Student::setID(const string& id) {
    studentID = id;
}

void Student::setFirstName(const string& first) {
    firstName = first;
}

void Student::setLastName(const string& last) {
    lastName = last;
}

void Student::setGpa(double newGpa) {
    if (newGpa < 0.0) {
        gpa = 0.0;
    }
    else if (newGpa > 4.0) {
        gpa = 4.0;
    }
    else {
        gpa = newGpa;
    }
    updateAcademicStatus();
}

void Student::setStudent(const string& id, const string& first, const string& last, double newGpa) {
    setID(id);
    setFirstName(first);
    setLastName(last);
    setGpa(newGpa);
}

void Student::updateAcademicStatus() {
    if (gpa < 2.0) {
        academicStatus = "Probation";
    }
    else {
        academicStatus = "Regular";
    }
}

void Student::addCourse(const Course& course) {
    if (numberOfCourses == coursesCapacity) {
        int newCapacity = coursesCapacity * 2;
        Course* newCourseArr = new Course[newCapacity];

        for (int i = 0; i < numberOfCourses; i++) {
            newCourseArr[i] = coursesEnrolled[i];
        }

        delete[] coursesEnrolled;
        coursesEnrolled = newCourseArr;
        coursesCapacity = newCapacity;
    }

    coursesEnrolled[numberOfCourses] = course;
    numberOfCourses++;
}


bool Student::removeCourse(const string& courseCode) {
    for (int i = 0; i < numberOfCourses; ++i) {
        if (coursesEnrolled[i].getCode() == courseCode) {
            for (int j = i; j < numberOfCourses - 1; ++j) {
                coursesEnrolled[j] = coursesEnrolled[j + 1];
            }
            numberOfCourses--;
            return true;
        }
    }
    return false;
}

void Student::listCourses(ostream& os) const {
    for (int i = 0; i < numberOfCourses; ++i) {
        cout << "- " << coursesEnrolled[i].getCode() << endl;
    }
}

void Student::display(ostream& os) const {
    os << "ID: " << studentID
        << "\nName: " << firstName << " " << lastName
        << "\nGPA: " << gpa
        << "\nStatus: " << academicStatus;
}

ostream& operator<<(ostream& os, const Student& student) {
    student.display(os);
    return os;
}

istream& operator>>(istream& in, Student& student) {
    string id, first, last;
    double gpa;

    in >> id;

    in >> first;

    in >> last;

    in >> gpa;

    student.setStudent(id, first, last, gpa);

    return in;
}
