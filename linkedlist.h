#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <iomanip>
#include <stdexcept> /// Necessary for std exceptions!


struct Node
{
    int data;
    Node* next;
};


class LinkedList
{
public:
    LinkedList();  /// Builds the initial Node!
    ~LinkedList(); /// Destroys the LinkedList to ensure there are no mem. leaks...
    void enqueue(int dat); /// Argument is the data to enqueue
    int dequeue(); /// Returns the data of the removed Node.
    bool is_empty(); /// Returns true iff the front of the list points to NULL.

    /// Misc. Functions
    void display();
    void bubble_sort();

private:
    Node* front; /// Front of the LinkedList
    Node* back;  /// Back of the Linked List
    /// REMEMBER: First In, First Out!
};

#endif // NODE_H_
