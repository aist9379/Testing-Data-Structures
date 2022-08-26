#ifndef HASH_HPP
#define HASH_HPP

#include <string>



using namespace std;


class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int *table;
    int numOfcolision =0;   // insert colisions
    int numOfcolision_s =0; // search colisions

public:
    HashTable(int bsize);  // Constructor
    ~HashTable(); // destructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    // hash function for double hashing
    unsigned int hashFunctionDH(int key);
    
    // returns number of insert colisions
    int numOfcol();
    
    // deletes numOfcolision counter
    void del_numOfcol();
   
    // returns number of insert colisions
    int numOfcol_s();
    
    // deletes numOfcolision_s counter
    void del_numOfcol_s();
    
    // prints hash table in order
    void printTable();

    // searches for item, returns bucket if found, returns -1 if not found
    int searchItem(int key);
};

#endif
