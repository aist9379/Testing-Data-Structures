#ifndef HASHBST_HPP
#define HASHBST_HPP

#include <string>
#include "BST.hpp"


using namespace std;


class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    BST *table;
    int numOfcolision = 0; // insert colisions
    int numOfcolision_s =0; // search colisions

public:
    HashTable(int bsize);  // Constructor
    ~HashTable();

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);
    
    // returns number of insert colisions
    int numOfcol();
    
    // deletes numOfcolision counter
    void del_numOfcol();
   
    // returns number of insert colisions
    int numOfcol_s();
    
    // deletes numOfcolision_s counter
    void del_numOfcol_s();

    // prints each BST in order 
    void printTable();

    // Searches for key in hash table and returns its Node
    Node* searchItem(int key);
};

#endif
