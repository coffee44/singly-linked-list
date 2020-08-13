//
//  SinglyLinkedList.cpp
//  SinglyLinkedList
//


#include "SinglyLinkedList.h"
using namespace std;

// default constructor, with head pointer set null, size 0 in the initializer list
SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0)
{}

// whenever call addToHead function and pass in the name, it means to creating a new Node node having a name and the address of next contact node
void SinglyLinkedList::addToHead(const std::string& name){
    
    Node* newOne = new Node(name);
    
    if (head == nullptr) {// check to see if head is null
        head = newOne;
    }
    else {
        newOne->next = head;  // to access private data member next, you have to make SinglyLinkedList class Node's friend
        head = newOne;
    }
    size++;
}


void SinglyLinkedList::printList() {
    
    Node* traversingPtr = head;
    while (traversingPtr != nullptr) {
        cout << *traversingPtr << "\n";
        traversingPtr = traversingPtr->next;
    }
}


void SinglyLinkedList::insert(const std::string &name) {
    
    Node* newNode = new Node(name);
    
    // case 1 - insert into an empty linked list
    if (head == nullptr) {
        head = newNode;
    }
    else {
        
        Node* curr = head;
        Node* trailingPtr = 0;  // not head
        
        while (curr) {
            
            if (curr->name >= newNode->name) {
                break;
            }
            else {  // be careful of the order of moving the two pointers
                trailingPtr = curr;
                curr = curr->next;
            }
        }
        
        if (curr == head) {  // case 2 - insert into the head of linked list, which already has at least a node
            newNode->next = head;
            head = newNode;
        }
        else {  // case 3 - insert into anywhere else except for the head of list , which already has at least a node
            newNode->next = curr;
            trailingPtr->next = newNode;
            
        }
    }
    size++;
}


void SinglyLinkedList::deleteNode(const string& name) {
    
    // case 1 - list is empty
    if (head == 0) {  // 0 or empty?
        cout << "cannot delete a node from empty list...\n";
    }
    else {
        
        Node* curr = head;
        Node* trailingPtr = 0;
        
        while (curr != 0) {
            
            if (curr->name == name) {
                break;
            }
            else {
                trailingPtr = curr;
                curr = curr->next;
            }
        }
        // case 2 - Node with "name" not found in list
        if (curr == 0) {
            cout << name << " node not found...\n";
        }
        else {
            // case 3 - delete from the head node
            if (head == curr) {
                head = head->next;
            }
            // case 4 - node found after head node
            else {
                cout << "Node found!\n";
                trailingPtr->next = curr->next;
            }
            delete curr;
            size--;
        }
    }
}


void SinglyLinkedList::reversePrintList() {
    reversePrintWorker(head);
}


void SinglyLinkedList::reversePrintWorker(Node* curr) {
    if (curr != 0) {
        reversePrintWorker(curr->next);
        cout << *curr << endl;
    }
}

