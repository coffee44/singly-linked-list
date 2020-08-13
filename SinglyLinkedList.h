//
//  SinglyLinkedList.h
//  SinglyLinkedList
//  change user input to file input


#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include "Node.h"

class SinglyLinkedList {
    
public:
    SinglyLinkedList();  // default constructor
    void addToHead(const std::string&);  // function to add a node to the head of the head
    void printList();
    void insert(const std::string&);
    void deleteNode(const std::string&);
    void reversePrintList();  // wrapper function, not wanna expose parameter
    
    
private:
    void reversePrintWorker(Node*);

    Node* head;  // head node
    int size;  // size associated with the linked list
    
};

#endif /* SinglyLinkedList_h */
