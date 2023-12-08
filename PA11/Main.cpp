#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList* list = new LinkedList();
    // Test append, prepend, and display
    list->append(10);
    list->append(2);
    list->prepend(5);
    list->display();

    // Test remove
    
    list->remove(10);
    list->append(12);
    list->display();

    // Test insertAfter and reverse (for advanced tasks)
    
    list->insertAfter(5, 7);
    list->display();

    cout<<"testing reverse -----------------"<<endl;
    list->reverse();
    cout<<"reverse completed. output: ";
    list->display();

    //Avoid memory leaks by deleting the list.
    //delete list;
    return 0;
}