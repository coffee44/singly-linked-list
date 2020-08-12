//  
//  Node.h
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>

class Node {
    // Should it be private or public? So far it works properly.
    friend std::ostream& operator<<(std::ostream& os, const Node& n);
    friend class SinglyLinkedList; // enable SinglyLinkedList class to access private data members
public:
    Node(std::string name="none");
    
private:
    std::string name;
    Node* next;
    
};


#endif /* Node_h */
