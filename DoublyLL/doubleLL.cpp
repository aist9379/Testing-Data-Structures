#include <iostream>
#include "doubleLL.hpp"
#include <cstring>
#include <string>

using namespace std;

doubleLL::doubleLL() {
    head = nullptr;
    tail = nullptr;
}

doubleLL::~doubleLL() {
    Node *temp;
    
    // deletes head and moves it up one until entire linked list is deleted
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    //cout << "Deleted Linked List" << endl;
}


bool doubleLL::isEmpty() {
    return(head == nullptr);
}


void doubleLL::addNode(Node* previousNode, int input_key) {
    Node *input = new Node;
    input->key = input_key;
    
    if(previousNode == nullptr) 
    {
        if(head == nullptr) // If LL is empty, make new Node head of LL
        {
            head = input;
            tail = input;
            input->next = nullptr;
            input->prev = nullptr;
            //cout << "adding key: " << input_key << " (HEAD)" << endl;
        }
        
        else // add key to end of LL 
        {
            Node *temp;
            temp = tail;
        
            temp->next = input;
            tail = input;
        
            //cout << "adding key: " << input_key << " (TAIL)" << endl;
        }
        
    }
    
    else if(previousNode == tail) // add key to end of LL
    {
        Node *temp;
        temp = tail;

        temp->next = input;
        tail = input;

        //cout << "adding key: " << input_key << " (TAIL)" << endl;
    }
    
    else // add key after given node in the middle of the linke list
    {
        Node* temp;
        temp = previousNode->next;
        
        previousNode->next = input;
        input->next = temp;     
        //cout << "adding: " << input_key << " (prev: " << previousNode->key << ")" << endl;
    }   
    
}

Node* doubleLL::searchNode(int input_key){
    Node *temp = head;
    
    // traverses linked list unitl key that is being searched for is found
    while(temp != nullptr)
    {
        if(temp->key == input_key)
            return temp;
        
        else
            temp = temp->next;
    }
    
    // if while loop ends, then key was not found
    return nullptr;
}

void doubleLL::clearAllNodes(){ // destructor function implimented for free use
    if(head != nullptr)
    {
        Node *temp = head;
        while(temp  != nullptr)
        {
            head = head -> next;
            delete temp;
            temp = head;  
        }
        
        tail = nullptr;
        //cout << "Deleted network" << endl;
    }
}

void doubleLL::displayNodes() {
    if(head==nullptr)
        cout << "nothing in path" << endl;
    
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->key << "-> ";
            temp = temp->next;
        }
        
        cout << "nullptr" << endl;
        
    }
}


// void doubleLL::removeNode(int input_key) {
//     if(head == nullptr)
//         cout << "Empty list" << endl;
    
//     else
//     {
//         Node* ret_node = searchNode(input_key); // grabbing pointer of node to be deleted
        
//         if(ret_node == nullptr)
//             cout << "Node does not exist" << endl;
        
//         else
//         {
            
//             if(head == ret_node) // deleting head
//             {
//                 head = head->next;
//                 delete ret_node;
//             }
            
//             else if(tail == ret_node)
//             {
//                 ret_node->prev->next = nullptr;
//                 tail = ret_node->prev;
//             }
//             else // deleting node in middle of LL
//             {
//                 temp = ret_node->prev;
//                 temp->next = ret_node->next;
//                 ret_node->next->prev = temp;
                
//                 delete ret_node;
            
//             }
            
//         }

//     }
// }