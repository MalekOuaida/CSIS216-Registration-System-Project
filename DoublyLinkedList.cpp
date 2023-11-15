#include "DoublyLinkedList.h"
#include "Student.h"
#include <iomanip>

/* Constructor for DoublyLinkedList: Initializes 'myFirst' to NULL and 'mySize' to 0,
indicating an empty list at creation. */

DoublyLinkedList::DoublyLinkedList() :myFirst(NULL), mySize(0) {}

/* Copy Constructor for DoublyLinkedList: Initializes an empty list, then iterates through
the original list orig, copying each element to create an equivalent list. The new list
maintains the same order and size as the original. */

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& orig) : myFirst(NULL), mySize(0) {
    DNode* current = NULL;
    DNode* origNode = orig.myFirst;

    while (origNode != NULL) {
        DNode* newNode = new DNode(origNode->data);

        if (current != NULL) {
            current->next = newNode;
        }
        else {
            myFirst = newNode;
        }

        current = newNode;
        origNode = origNode->next;
        mySize++;
    }
}

/* Retrieves the Student object at position 'pos' in the list. Returns a pointer to the
Student object if 'pos' is valid, or NULL if 'pos' is out of range or the list is empty. */

Student* DoublyLinkedList::getatpos(int pos) const
{
    if (pos == 0) {
        return &(myFirst->data);
    }

    DNode* current = myFirst->next;
    int count = 1;
    while (current->next != NULL) {
        if (count == pos) {
            return &(current->data);
        }
        current = current->next;
        count++;
    }
    return NULL;
}

/* Destructor for DoublyLinkedList: Iterates through the list, deleting each node,
and resets the list to an empty state. */

DoublyLinkedList::~DoublyLinkedList() {
    DNode* current = myFirst;
    while (current != NULL) {
        DNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    myFirst = NULL;
    mySize = 0;
}

// Checks if the list is empty. Returns true if empty, false otherwise.

bool DoublyLinkedList::isEmpty() const {
    return myFirst == NULL;
}

// Returns the current size (number of students) of the list.

int DoublyLinkedList::getSize() const {
    return mySize;
}

// Inserts a new node with 'studID' into the list in a sorted order based on student IDs.

void DoublyLinkedList::insertSorted(const StudentElementType& studID) {
    DNode* newNode = new DNode(studID);

    if (myFirst == NULL || myFirst->data.getID() >= newNode->data.getID()) {
        newNode->next = myFirst;
        if (myFirst != NULL) {
            myFirst->prev = newNode;
        }
        myFirst = newNode;
    }
    else {
        DNode* current = myFirst;
        while (current->next != NULL && current->next->data.getID() < newNode->data.getID()) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    mySize++;
}

// Deletes the node with the specified 'studentID' from the list. Returns true if deleted, false if not found.

bool DoublyLinkedList::deleteSorted(string studentID) {
    if (myFirst == NULL) {
        return false;
    }

    DNode* current = myFirst;
    while (current != NULL && current->data.getID() != studentID) {
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        myFirst = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    mySize--;

    return true;
}

// Displays the details of each student in the list, including ID, name, GPA, and academic status.

void DoublyLinkedList::display() const {

    cout << left << setw(15) << "ID"
        << setw(20) << "Name"
        << setw(10) << "GPA"
        << setw(30) << "Academic Status" << endl;

    DNode* current = myFirst;
    while (current != NULL) {
        cout << left << setw(15) << current->data.getID()
            << setw(20) << current->data.getLastName() + ", " + current->data.getFirstName()
            << setw(10) << current->data.getGpa()
            << setw(30) << current->data.getAcademicStatus() << endl;
        current = current->next;
    }
}

// Searches for and returns a pointer to the student with the given 'studentID'. Returns NULL if not found.

Student* DoublyLinkedList::findByIDForDD(const string& studentID) const {
    DNode* current = myFirst;
    while (current != NULL) {
        if (current->data.getID() == studentID) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}

// Overloads the << operator to display the contents of the DoublyLinkedList using the display() method.

ostream& operator<<(ostream& out, const DoublyLinkedList& list) {
    list.display();
    return out;
}

// Overloads the >> operator to read StudentElementType objects from an input stream and insert them into the list in sorted order.

istream& operator>>(istream& in, DoublyLinkedList& list) {
    StudentElementType student;
    while (in >> student) {
        list.insertSorted(student);
    }
    return in;
}
