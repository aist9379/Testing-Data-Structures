#include <string>
#include <iostream>
#include "hashDH.hpp"   

HashTable::HashTable(int bsize){  // Constructor
    tableSize = bsize;
    table = new int[tableSize];
    
    // initializing all empty blocks to -1
    for(int i = 0; i < bsize; i++)
        table[i] = -1;
}

HashTable::~HashTable(){ // destructor
    delete [] table;
}


// inserts a key into hash table
bool HashTable::insertItem(int key){
    unsigned int bucket = hashFunction(key);
    int n = 0; // n is incrimented if collision occurs
        
    //Searches for next avalibale bucket, stops if emtpy slot or existing key is found
    while(table[bucket] != -1)
    {
        bucket = (hashFunction(key) + n*hashFunctionDH(key)) % tableSize;
        n++;
    }
        
    // if key isnt already in table and a collsion has occured
    if(n > 0 and table[bucket] != key)
        numOfcolision++;

    // add key to table
    table[bucket] = key;
    
    // return true if succesfully added
    return true; 
            
}

// hash function to map values to key
unsigned int HashTable::hashFunction(int key){
    return(key % tableSize);
}

// double hashing function
unsigned int HashTable::hashFunctionDH(int key){
    return(1621 - (key % 1621));
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++)
        cout << i << " -> " << table[i] << endl;
}

int HashTable::searchItem(int key){
    unsigned int bucket = hashFunction(key);
    int n = 0; // n is incrimented if collision occurs
          
    // Searches for next avalibale bucket, stops if emtpy slot or existing key is found
    while(table[bucket] != key and n<10009)
    {
        bucket = (hashFunction(key) + n*hashFunctionDH(key))%tableSize;
        n++;
    }

    
    // if  a collsion has occured
    if(n > 0)
        numOfcolision_s++;
    
    // check if key was found and return it
    if(table[bucket] == key)
        return bucket;  // return bucket of found key]
    
    else
        return -1; // return -1 if key not found
}


int HashTable::numOfcol(){
    return numOfcolision;
}

void HashTable::del_numOfcol(){
    numOfcolision = 0;
}
   

int HashTable::numOfcol_s(){
    return numOfcolision_s;
}

void HashTable::del_numOfcol_s(){
    numOfcolision_s = 0;
}