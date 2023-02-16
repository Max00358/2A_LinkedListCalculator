#include "calcInitialize.hpp"
#include "calcDefinition.cpp"
#include "calcNode.hpp"
#include <iostream>
using namespace std;
//g++ -o main calculatorMain.cpp linkedListCalculator.cpp -std=c++11
int main(){
    
    string input;
    int capacity;
    int cap_count = 0;
    int end = 0;

    Node* temp = new Node(0.0);
    List* queue = new List();
    queue->set_head(temp);
    queue->get_head()->next = NULL;

    while(cin>>input){
        if(input == "CRT"){
            cin>>capacity; 
            cout << "success" << endl;
        }
        if(input == "END"){
            break;
        }
        if(input == "DEF"){
            string newName;
            cin>>newName;

            double newVal;
            cin>>newVal;

            queue->define(queue->get_head(), newName, newVal, capacity, cap_count);
            //cout<<"count define: " + to_string(cap_count)<<endl;
        }
        if(input == "ADD"){
            string x;
            string y;
            string z;

            cin>>x;
            cin>>y;
            cin>>z;
            queue->add(queue->get_head(),x,y,z);
        }
        if(input == "SUB"){
            string x;
            string y;
            string z;

            cin>>x;
            cin>>y;
            cin>>z;
            queue->sub(queue->get_head(),x,y,z);
        }
        if(input == "REM"){
            string x;
            cin>>x;
            queue->remove(queue->get_head(), x, cap_count);
            //cout<<"count remove: " + to_string(cap_count)<<endl;
        }
        if(input == "PRT"){
            
            string x;
            cin>>x;
            queue->print(queue->get_head(), x);
            
            /*
            Node* temp = queue->head;
            while(temp != NULL){
                cout<<to_string(temp->val) + " -> "<<endl;
                temp = temp->next;
            }
            */
        }
    }
    delete queue;
}