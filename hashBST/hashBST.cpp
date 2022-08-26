#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <vector>
#include "hashBST.hpp"

using namespace std;

HashTable::HashTable(int bsize){  // Constructor
    tableSize = bsize;
    table = new BST[bsize];
}

HashTable::~HashTable(){          // destructor
    delete [] table;
}

// inserts a key into hash table
bool HashTable::insertItem(int key){
    unsigned int bucket = hashFunction(key);
    
    // adding node to BST at given bucket
    table[bucket].addNode(key);
    
    // finding root node of bucket
    Node* temp =  table[bucket].getRoot();
    
    //checking for colision
    if(temp != NULL){
        if(temp->key != key)
            numOfcolision++;
    }
    
    return true;
}

// hash function to map values to key
unsigned int HashTable::hashFunction(int key){
    return(key % 10009);
}

// returns number of insert colisions
int HashTable::numOfcol(){
    return numOfcolision;
}

// deletes numOfcolision counter
void HashTable::del_numOfcol(){
    numOfcolision = 0;
}

// returns number of insert colisions
int HashTable::numOfcol_s(){
    return numOfcolision_s;
}

// deletes numOfcolision_s counter
void HashTable::del_numOfcol_s(){
    numOfcolision_s = 0;
}

// prints hash table
void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++)
        table[i].printTree();
}

Node* HashTable::searchItem(int key){
    unsigned int bucket = hashFunction(key);
    
    // finding root node of bucket
    Node* temp =  table[bucket].getRoot();
    
    //checking for colision
    if(temp != NULL){
        if(temp->key != key)
            numOfcolision_s++;
    }
    
    // returns address of node of key being searched. Returns NULL if not found
    return(table[bucket].searchKeyHelper(temp, key));
}
