#include "LListWithDummyNode.h"
#include <iomanip>

// Default Constructor
// Initializes an empty list with a dummy node and sets the size to 0.
LListWithDummyNode::LListWithDummyNode() :mysize(0)
{
    myFirst = new(nothrow) Node(Course());
}

// Copy Constructor
// Creates a deep copy of another list. Initializes the dummy node and copies elements from the rhs list.
LListWithDummyNode::LListWithDummyNode(const LListWithDummyNode& rhs)
    :mysize(0)
{
    // Start with the first node after the dummy node in rhs
    NodePtr rhsNode = rhs.myFirst->next;
    // Initialize the dummy node for the new list
    NodePtr node = new(nothrow) Node(Course());
    myFirst = node;
    // Incorrectly sets rhsNode to myFirst, which is a logic error
    rhsNode = myFirst;
    // Iterate through the rhs list and copy each node
    while (rhsNode != NULL) {
        NodePtr node = new(nothrow) Node(rhsNode->data);
        rhsNode->next = node;
        rhsNode = rhsNode->next;
    }
}

// Destructor
// Releases the memory allocated for the dummy node.
LListWithDummyNode::~LListWithDummyNode()
{
    delete myFirst;
}

// Function: isEmpty
// Returns true if the list contains only the dummy node.
bool LListWithDummyNode::isEmpty() const
{
    return (myFirst->next == NULL);
}

// Function: getSize
// Returns the number of elements in the list (excluding the dummy node).
int LListWithDummyNode::getSize() const
{
    return mysize;
}

// Function: addCourse
// Adds a new Course to the list in a sorted manner based on the course code.
bool LListWithDummyNode::addCourse(const ElementType& Course) {

    // Creating a new node for the course
    NodePtr newCourse = new Node(Course);
    // Start with the dummy node
    NodePtr current = myFirst;

    // Traverse the list to find the right position for the new course
    while (current->next != NULL && current->next->data.getCode().substr(0, 4) != Course.getCode().substr(0, 4)) {
        current = current->next;
    }

    // Insert the new course node in the correct position
    if (current->next == NULL) {
        current->next = newCourse;
    }
    else {
        newCourse->next = current->next;
        current->next = newCourse;
    }
    // Increment the size of the list
    mysize++;
    return true;
}

// Function: searchCourseById
// Searches for a course by its code in the list.
Course* LListWithDummyNode::searchCourseById(const string& courseCode)
{
    NodePtr current = myFirst->next; // Start from the first real node (skip dummy)
    while (current != NULL) {
        // Check if the current node's course code matches the search code
        if (current->data.getCode() == courseCode) {
            return &(current->data); // Return a pointer to the course if found
        }
        current = current->next; // Move to the next node
    }
    return NULL; // Return NULL if the course is not found
}

// Function: DeleteCourse
// Deletes a course from the list.
bool LListWithDummyNode::DeleteCourse(const ElementType& course)
{
    NodePtr trash = searchCourse(course); // Find the course to be deleted

    // Check if the course to be deleted is the first real node
    if (trash == myFirst->next) {
        delete trash; // Delete the node
        mysize--; // Decrement the list size
        return true;
    }

    NodePtr temp = myFirst->next; // Start from the first real node

    // Traverse the list to find the node preceding the one to be deleted
    while (temp->next != trash && temp->next != NULL) {
        temp = temp->next;
    }

    // Check if the course to be deleted was found
    if (temp->next != NULL) {
        delete temp; // Delete the preceding node (incorrect, should delete `trash`)
        mysize--; // Decrement the list size
        return true;
    }

    // Re-link the list to exclude the deleted node
    temp->next = trash->next;
    delete trash; // Delete the node
    mysize--; // Decrement the list size
    return true;
}

// Function: getatposLL
// Retrieves a course at a specified position in the list.
Course* LListWithDummyNode::getatposLL(int pos) const
{
    if (pos == 0) {
        // Return the first real node's data if position is 0
        return &(myFirst->next->data);
    }

    NodePtr current = myFirst->next->next; // Start from the second real node
    int count = 1; // Initialize count

    // Traverse the list to find the node at the specified position
    while (current != NULL) {
        if (count == pos) {
            return &(current->data); // Return the course at the position
        }
        current = current->next;
        count++;
    }

    return NULL; // Return NULL if position is out of bounds
}

// Function: display
// Displays the contents of the list to an output stream.
void LListWithDummyNode::display(ostream& out) const
{
    out << left << setw(10) << "Code"
        << setw(30) << "Title"
        << setw(15) << "#Credits"
        << setw(15) << "Enrolled"
        << setw(15) << "Capacity" << endl;

    NodePtr temp = myFirst->next; // Start from the first real node
    while (temp != NULL) {
        out << left << setw(10) << temp->data.getCode()
            << setw(30) << temp->data.getName()
            << setw(15) << temp->data.getCredits()
            << setw(15) << temp->data.getNumEnrolled()
            << setw(15) << temp->data.getCapacity() << endl; // Output the data of each node
        temp = temp->next; // Move to the next node
    }
}

// Function: searchCourse
// Searches for a course in the list.
LListWithDummyNode::NodePtr LListWithDummyNode::searchCourse(const ElementType& course) const
{
    NodePtr temp = myFirst;
    while (temp->next != NULL) {
        // Check if the current node's course matches the search course
        if (temp->data == course) {
            return temp; // Return the node if found
        }
        temp = temp->next; // Move to the next node
    }
    return NULL; // Return NULL if the course is not found
}

// Operator Overload: <<
// Overloads the output stream operator to display the list.
ostream& operator<<(ostream& out, const LListWithDummyNode& courses)
{
    courses.display(out); // Display the list contents
    return out;
}

// Operator Overload: >>
// Overloads the input stream operator to input courses into the list.
istream& operator>>(istream& in, LListWithDummyNode& list)
{
    Course course;
    while (in >> course) { // Read courses from the input stream
        list.addCourse(course); // Add each course to the list
    }
    return in;
}