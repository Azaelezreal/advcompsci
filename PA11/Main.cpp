#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList* list = new LinkedList();
    // Test append, prepend, and display
    list->append(10);
    list->prepend(5);
    list->display();

    // Test remove
    list->remove(10);
    list->display();

    // Test insertAfter and reverse (for advanced tasks)
    list->insertAfter(5, 7);
    list->reverse();
    list->display();

    //Avoid memory leaks by deleting the list.
    delete list;

    return 0;
}