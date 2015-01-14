#include "linkedlist.h"


LinkedList::LinkedList()
{
    front = NULL;
    back = NULL;
}

LinkedList::~LinkedList()
{
    while(!is_empty())
    {
        Node* node_ptr;
        node_ptr = front;
        front = node_ptr->next;
        delete node_ptr;
    }

}

void LinkedList::enqueue(int dat)
{
    if (is_empty())
    {
        front = new Node;
        front->data = dat;
        front->next = NULL;
        back = front; /// For some reason this line is necessary.
    }
    else
    {
        back->next = new Node;
        back = back->next;
        back->data = dat;
        back->next = NULL;
    }
}


int LinkedList::dequeue()
{

    if (!is_empty())
    {
        Node* node_ptr = front;
        int return_data = front->data;
        front = front->next;
        delete node_ptr;

        return return_data;
    }
    else
    {
        throw std::length_error("Length Error: The LinkedList was empty!!!");
    }
}


bool LinkedList::is_empty()
{
    return (front == NULL);
}


void LinkedList::display()
{
    for (Node* node_ptr = front;
        node_ptr != NULL;
        node_ptr = node_ptr->next)
    {
        std::cout << std::setw(2) << node_ptr->data <<  "\t" << node_ptr->next << std::endl;
    }

}


void LinkedList::bubble_sort()
{
    /// Potentially shitty implementation of bubble sort algorithm...
    bool exchanges;

    do
    {
        exchanges = false;

        for(Node* node_ptr = front;
            node_ptr != back;
            node_ptr = node_ptr->next)
        {
            if ( (node_ptr->data > node_ptr->next->data) )
            {
                /// Will switch the two values, because they are out of order.
                int temp = node_ptr->data;
                node_ptr->data = node_ptr->next->data;
                node_ptr->next->data = temp;
                exchanges = true;
            }
        }
    } while (exchanges);

}
