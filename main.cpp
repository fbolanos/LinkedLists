#include <iostream>    /// std I/O
#include "linkedlist.h"

#include <time.h>    /// Needed to seed the random numbers
#include <stdlib.h>  /// Contains random function


using std::cout;
using std::cin;
using std::endl;

int main()
{

    srand(time(0)); // Seeds the random number generator
    int SIZE = 10;  // Size of the LinkedList

    LinkedList lon; /// Initialize Class LinkedList (Constructor takes no params)

    // Generate LinkedList of 100 members with data consisting
    //  of 10 random numbers from 0-100.
    for (int k=0; k<SIZE; k++)
    {
        lon.enqueue(rand()%100);
    }

    cout << "Before Sorting:" << endl;
    lon.display(); // Displays the LinkedList by traversing it. BigO(n)



    // Bubble sort Algorithm! Not sure of its BigO... :(
    lon.bubble_sort();



    cout << endl << "After Sorting:" << endl;
    lon.display();



    // Removes all elements of the list
    cout << endl << "Deleting Nodes:" << endl;
    for (int k=0; k<SIZE; k++)
    {
        cout << lon.dequeue() << "\t [DELETED]" << endl;
    }

    //cout << lon.dequeue(); // Will throw exception because list is empty atm!
    // Prints nothing! Because we deleted ALL the nodes.
    lon.display();

    // Re-enqueue some data...
    lon.enqueue(1);
    lon.enqueue(3);
    lon.enqueue(3);
    lon.enqueue(7);

    cout << endl << "Some Data:" << endl;
    lon.display();




    return 0;
}
