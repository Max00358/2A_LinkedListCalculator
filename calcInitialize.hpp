#ifndef _CALCINITIALIZE_HPP_
#define _CALCINITIALIZE_HPP_
#include <iostream>
#include "calcNode.hpp"
using namespace std;

class List{
public:
    List(){
        Node *head;
        head = NULL;
    }
    ~List();
    //void create(Node* head, int capacity);
    //void insert(Node* head, double num);
    void insertName(Node* head, double num, string newName);
    bool match(Node* head, string newName);
    void define(Node* head, string name, double val, int capacity, int& cap_count);
    Node* locate(Node* head, string target);
    void add(Node* head, string x, string y, string z);
    void sub(Node* head, string x, string y, string z);
    void remove(Node* head, string x, int& cap_count);
    void print(Node* head, string x);
    Node* get_head();
    void set_head(Node* newVal);

private:
    Node* head;
};
#endif