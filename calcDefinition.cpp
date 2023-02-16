#include <iostream>
#include "calcInitialize.hpp"
#include "calcNode.hpp"
using namespace std;

Node *List::get_head(){
    return head;
}
void List::set_head(Node* newVal){
    head = newVal;
}
void List::insertName(Node* head, double num, string newName){
    /*
    if(head == NULL){
        head->val = num;
        head->name = newName;
        head->next = NULL;
    }
    */
    
    Node* temp = head;
    Node* new_insert = new Node(num);
    new_insert->name = newName;
    new_insert->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=new_insert;
    
    return;
}
bool List::match(Node* head, string newName){
    if(head==NULL){
        return false;//cannot find any name in the list that matches the new name
    }
    else{
        Node* temp = head;
        while(temp != NULL){
            if(temp->name==newName){
                //found a matching name
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}
void List::define(Node* head, string newName, double newVal, int capacity, int& cap_count){
    if(capacity == cap_count || match(head, newName) == true){
        cout<<"failure"<<endl;
    }
    else if(capacity > cap_count && match(head, newName) == false){
        //if there's no matching name, then we can add this to the linked list
        insertName(head, newVal, newName);
        cout<<"success"<<endl;
        cap_count++;
    }
    else{
        cout<<"failure"<<endl;
    }
    return;
}
Node* List::locate(Node* head, string target){
    Node* temp = head;
    while(temp != NULL){
        if(temp->name==target){
            //found a matching name
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//Duplicate names are allowed in add & sub
void List::add(Node* head, string x, string y, string z){
    if(match(head, x)==true && match(head, y)==true && match(head, z)==true){
        locate(head, z)->val = locate(head, x)->val + locate(head, y)->val;
        cout<<"success"<<endl;
    }
    else if(match(head, x)==false || match(head, y)==false || match(head, z)==false){
        cout<<"failure"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
    return;
}
void List::sub(Node* head, string x, string y, string z){
    if(match(head, x)==true && match(head, y)==true && match(head, z)==true){
        locate(head, z)->val = locate(head, x)->val - locate(head, y)->val;
        cout<<"success"<<endl;
    }
    else if(match(head, x)==false || match(head, y)==false || match(head, z)==false){
        cout<<"failure"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
    return;
}
void List::remove(Node* head, string x, int& cap_count){
    if(match(head, x) == false){
        cout<<"failure"<<endl;
    }
    else{
        if(head->next->name == x){//if x exist next to head
            Node* temp = head->next->next;
            //delete head->next;
            delete locate(head, x);
            head->next = temp;
        }
        else if(locate(head, x)->next == NULL){//if x exist at the end
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            //delete temp->next->next;
            delete locate(head, x);
            temp->next = NULL;
        }
        else{
            Node* trav = head;
            while(trav->next->name != x){
                trav = trav->next;
            }
            //Node* temp = trav->next->next;
            //now we are next to target node
            delete locate(head, x);
            trav->next = trav->next->next;
        }

        if(match(head, x) == false){//if string has been cleared, output success
            cout<<"success"<<endl;
            cap_count--;
        }
        return;
    }
    return;
}
void List::print(Node* head, string x){
    if(match(head, x) == true){
        cout<<locate(head, x)->val<<endl;
    }
    else if(match(head, x) == false){
        cout<<"variable " + x + " not found"<<endl;
    }
    return;
}
List::~List(){
    Node *p_temp = head;

	while(head != NULL){
		p_temp = p_temp ->next;
		delete head;
		head = p_temp;
	}
}