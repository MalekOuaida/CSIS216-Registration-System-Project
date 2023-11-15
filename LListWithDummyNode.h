/*-- LListWithDummyNode.h --------------------------------------------------------------

  This header file defines the data type DeleteCourse for processing lists with a dummy
  node.
  Basic operations are:
	 Constructor
	 Copy constructor
	 Destructor
	 Assignment operator
	 isEmpty:    Check if list is empty
	 addCourse:   Insert a course
	 DeleteCourse:    Remove an item
	 getatposLL: finds a course at a postion
	 searchCourseById: finds a course by its id
	 searchCourse: searches for an item
	 display:  Output the list
	 << :      Output operator
-------------------------------------------------------------------------*/

#include <iostream>
#include "course.h"

using namespace std;

typedef Course ElementType;

#ifndef LLIST
#define LLIST

class LListWithDummyNode {
private:
	class Node {
	public:
		ElementType data; //the data inside of the node( a course object )
		Node* next; // points to the next node

		Node(const ElementType& data) : data(data), next(NULL) {}
	};
	typedef Node* NodePtr;

public:
	/******** Function Members ********/
		/***** Class constructor *****/
	LListWithDummyNode();
	/*----------------------------------------------------------------------
	 Construct an LListWithDummyNode object.

	 Precondition:  None.
	 Postcondition: An empty LListWithDummyNode object is constructed;
	 myFirst points to a dummy node;
	 mySize is 0.
	-----------------------------------------------------------------------*/

	/***** Copy constructor *****/
	LListWithDummyNode(const LListWithDummyNode&);
	/*----------------------------------------------------------------------
	 Construct a copy of an LListWithDummyNode object.

	 Precondition:  A copy of origList is needed; origList is a const
	  reference parameter.
	 Postcondition: A copy of origList has been constructed.
	-----------------------------------------------------------------------*/

	/***** Class destructor *****/
	~LListWithDummyNode();
	/*----------------------------------------------------------------------
	 Destroys an LListWithDummyNode object.

	 Precondition:  The life of an LListWithDummyNode object is over.
	 Postcondition: The memory dynamically allocated by the constructor
		 for the nodes pointed to by myFirst has been returned to the heap.
	-----------------------------------------------------------------------*/

	bool isEmpty() const;
	/*----------------------------------------------------------------------
	Check if a LListWithDummyNode is empty.

	Precondition: None
	Postcondition: true is returned if the list is empty, false if not.
	-----------------------------------------------------------------------*/

	int getSize() const;
	/*----------------------------------------------------------------------
	Returns the size of a LListWithDummyNode.

	Precondition: None
	Postcondition: the size of the list.
	-----------------------------------------------------------------------*/

	/***** addCourse *****/
	bool addCourse(const ElementType&);
	/*----------------------------------------------------------------------
	Insert a value into the list according to the course code.

	Precondition: A course has a valid courseId.
	Postcondition: item has been inserted into the list wihin its range of
	course code
	-----------------------------------------------------------------------*/

	Course* searchCourseById(const string& courseCode);
	/*----------------------------------------------------------------------
	Finds the course depending on the code.
	Precondition: The list is not empty and course code is a valid course code.
	Postcondition: Returns pointer to the course that has the given id.
	----------------------------------------------------------------------*/

	/***** DeleteCourse *****/
	bool DeleteCourse(const ElementType&);
	/*----------------------------------------------------------------------
	Remove a Course from the list.
	Precondition: The list is not empty and the position course exists in the
	list.
	Postcondition: element pointed to has been removed.
	----------------------------------------------------------------------*/


	Course* getatposLL(int) const;
	/*----------------------------------------------------------------------
	Points to a course .
	Precondition: The list is not empty and the position course exists in the
	list.
	Postcondition: Course at the given position is pointed to.
	----------------------------------------------------------------------*/


	/***** output *****/
	void display(ostream&) const;
	/*----------------------------------------------------------------------
	Display a list.
.
	Precondition: None.
	Postcondition: The list represented by this LListWithDummyNode object has been
	inserted into out.
	----------------------------------------------------------------------*/

private:
	NodePtr myFirst; //points to the first node

	int mysize; //current size of the Linked List

	/******** search course ********/
	NodePtr searchCourse(const ElementType&) const;
	/*----------------------------------------------------------------------
	searches for a course in the list (aux).
.
	Precondition: the list is not empty.
	Postcondition: the position of the node is pointed to.
	----------------------------------------------------------------------*/
};

//------output operator------//
ostream& operator<<(ostream&, const LListWithDummyNode&);
//------input operator------//
istream& operator>>(istream&, LListWithDummyNode&);


#endif