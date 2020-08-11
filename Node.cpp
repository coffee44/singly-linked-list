//
//  Node.cpp
//

#include <iostream>
#include "Node.h"

using namespace std;  // OK inside source file, not OK inside header

// default constructor
Node::Node(string n) : name(n), next(nullptr)
{
}

// overloaded insertion operator
ostream& operator<<(ostream &os, const Node& c) {
    return os << "name: " << c.name;
}



