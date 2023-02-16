#ifndef _CALCNODE_HPP_
#define _CALCNODE_HPP_
#include <iostream>
using namespace std;

class Node{
//friend class List;
public:
    Node(double newVal){
        val = newVal;
    }
    double val;
    string name;
    Node* next;
};
#endif