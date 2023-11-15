//author: Malek Ouaida
/*-- DoublyLinkedList.h --------------------------------------------------------------
  Basic operations are:
     Constructor
     Copy constructor
     Destructor
     Assignment operator
     isEmpty:    Check if list is empty
     getSize:    Returns the size of the list
     insertSorted:   Inserts a Student depending on his ID
     deleteSorted:    Deletes a Student depending on his ID
     findByID: searches for student by ID
     getatpos: retrieves the student object located at a specific position in the
     display:  output the list
     << :      output operator
     >> :      Input operator
-------------------------------------------------------------------------*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

typedef Student StudentElementType;

class DoublyLinkedList {
public:
    /******** Function Members ********/
            /***** Class constructor *****/
    DoublyLinkedList();
    /*----------------------------------------------------------------------
         Construct a DoublyLinkedList object.

         Precondition: None.
     
         Postcondition: A new, empty DLL has been initialized.
    -----------------------------------------------------------------------*/
    
    /***** Copy constructor *****/
    DoublyLinkedList(const DoublyLinkedList& orig);
    /*----------------------------------------------------------------------
         Construct a copy of a DoublyLinkedList object.

         Precondition: A copy of orig is needed; orig is a const reference
         parameter representing an existing DLL.
     
         Postcondition: A copy of orig has been constructed, with all the
         nodes in the original list duplicated in the new list.
    -----------------------------------------------------------------------*/
    
    /***** Class destructor *****/
    ~DoublyLinkedList();
    /*----------------------------------------------------------------------
         Destructor for the DoublyLinkedList class.

         Precondition: The DLL instance exists.
     
         Postcondition: The DLL has been destroyed and all
         dynamically allocated memory associated with it has been released.
    -----------------------------------------------------------------------*/
    bool isEmpty() const;
    /*----------------------------------------------------------------------
         Check if the DoublyLinkedList is empty.

         Precondition: The DLL instance exists.
     
         Postcondition: Returns true if the list is empty (i.e., contains no
         elements), false otherwise. This operation does not modify the list.
    -----------------------------------------------------------------------*/
    int getSize() const;
    /*----------------------------------------------------------------------
         Retrieve the size of the DoublyLinkedList.

         Precondition: The DLL instance exists.
     
         Postcondition: Returns the number of elements in the list. This
         operation does not modify the list and does not change its state.
    -----------------------------------------------------------------------*/
    void insertSorted(const StudentElementType& value);
    /*----------------------------------------------------------------------
         Insert an element into the DoublyLinkedList in a sorted order.

         Precondition: The DLL instance exists. 'value' is the
         element to be inserted, of type StudentElementType.
     
         Postcondition: 'value' has been inserted into the list in a position
         that maintains the sorted student ID's of the list.
    -----------------------------------------------------------------------*/
    bool deleteSorted(string studentID);
    /*----------------------------------------------------------------------
         Delete an element from the DoublyLinkedList based on a student ID.

         Precondition: The DLL instance exists. 'studentID' is a
         string representing the ID of the student whose element is to be
         deleted from the list.
     
         Postcondition: If an element with 'studentID' exists in the list, it
         is removed and the function returns true. If no such element exists,
         the function returns false.
    -----------------------------------------------------------------------*/
    void display() const;
    /*----------------------------------------------------------------------
         Display the contents of the DoublyLinkedList.

         Precondition: The DLL instance exists.
     
         Postcondition: The elements of the DoublyLinkedList are displayed to
         a standard output device (like the console). The list itself remains
         unchanged and no elements are modified during this operation.
    -----------------------------------------------------------------------*/
    Student* findByIDForDD(const string& studentID) const;
    /*----------------------------------------------------------------------
         Search for a Student object by ID in the DoublyLinkedList.

         Precondition: The DoublyLinkedList instance exists. 'studentID' is the
         student's ID to search for.
     
         Postcondition: Returns a pointer to the Student object with the given
         ID, if found. If not found or the list is empty, returns nullptr. The
         list remains unchanged.
    -----------------------------------------------------------------------*/
    Student* getatpos(int) const;
     /*----------------------------------------------------------------------
          Retrieve the Student object at a specified position in the DoublyLinkedList.

          Precondition: The DLL instance exists. The input is an
          integer 'pos', representing the position in the list, where the first
          element is at position 0.
     
          Postcondition: Returns a pointer to the Student object at the specified
          position. The function iterates through the list, starting from the
          first node.
          If 'pos' is 0, it returns the data of the first node.
          Otherwise, it traverses the list until it reaches the position or the
          end of the list.
          If 'pos' is out of bounds or if the list is empty,
          returns NULL. The list remains unchanged by this operation.
     -----------------------------------------------------------------------*/
private:
    class DNode {
    public:
        StudentElementType data; // Holds the data of the node, of type StudentElementType (Student)
        DNode* next; // Pointer to the next node in the list
        DNode* prev; // Pointer to the previous node in the list
        };

    DNode* myFirst; // Pointer to the first node of the DLL
    int mySize; // Stores the current size of the list
};

//------ Prototype of output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& list);
istream& operator>>(istream& in, DoublyLinkedList& list);

#endif // DOUBLY_LINKED_LIST_H
