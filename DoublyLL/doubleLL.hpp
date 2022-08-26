#ifndef DOUBLE_HPP
#define DOUBLE_HPP
#include <iostream>

using namespace std;

// struct that will be stored in the doublLL class
struct Node
{
    int key;                  // data value in doubly linked list
    Node *next;               // pointer to the next Node
    Node *prev;               // pointer to the previous Node
};

// class for storing and manipulating double linked-list of Nodes
class doubleLL {
    private:
        // pointer to head of doubly linked-list 
        Node* head; 
    
        // pointer to tail of doubly linked-list 
        Node* tail;
    
    public:
        doubleLL();
        ~doubleLL();
        bool isEmpty();
        void addNode(Node* previousNodeName, int input_key);
        void removeNode(int input_key);
        Node* searchNode(int input_key);
        void clearAllNodes();
        void displayNodes();
};
#endif
