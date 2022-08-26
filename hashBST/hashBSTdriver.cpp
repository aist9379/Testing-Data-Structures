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

int main()
{
    string dataSetA = "dataSetA-updated.csv";
    int size = 10000;
    int intArr[size]; // storing vals from the csv file
    float insert[50]; // store runtimes when we insert the data into the data structure 
    float search[50]; // store the search runtimes of when we search for items in the data structure
    float insert_col[50]; // store the number of insert colisions for 200 inserts
    float search_col[50]; // store the number of search colisions for 200 searches
    
    // reading.csv file to intArr
    ifstream in_file;
    in_file.open(dataSetA);
    string read;
    
    int x = 0;
    while(std::getline(in_file, read, ','))
    {
        intArr[x] = stoi(read);
        x++;
    }

    // Initializing Hash Table BST class 
    HashTable ht = HashTable(10009);
    
// ---------------------------- ** INSERTION TESTING ** ---------------------------- // 
    // do 200 insertions 50 times
    x = 0; //incriments everytime an item from intArr is inserted into data structure

    for(int i = 0; i < 50; i++) 
    {
        auto start = chrono::steady_clock::now();

        // search next 200 items in data structure
        for(int p = 0; p < 200; p++)
        {
            ht.insertItem(intArr[x]);
            x++;
        }

        auto end = chrono::steady_clock::now();

        // time it took to read 200 items from data set
        insert[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200; // divide by 200 to get average
        
        // number of updated colisions
        insert_col[i] = ht.numOfcol();
        
        // setting insert colisions to 0 for next inseration
        ht.del_numOfcol();
        
        
// ---------------------------- ** SEARCH TESTING ** ---------------------------- //
        
        // random number generation
        vector<int> randArray;
        for(int p = 0; p < 200; p++)
        {
            // chooses a random student ID that has already been added in the data structure to ensure value can be searched for and found
            randArray.push_back(intArr[rand() % (200*(i+1))]); // dynamically chooses values as more data is added
        }
        
        start = chrono::steady_clock::now();

        // search next 200 items in data structure
        for(int p = 0; p < 200; p++)
        {
            ht.searchItem(randArray[p]);
        }

        end = chrono::steady_clock::now();

        // time it took to read 200 items from data set
        search[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200;
        
        // number of updated search colisions
        search_col[i] = ht.numOfcol_s();
        
        // setting search colisions to 0 for next search
        ht.del_numOfcol_s();
        
    }
    
// ---------------------------- ** Writting Data ** ---------------------------- //
    ofstream out_file;
    out_file.open("Hash_BST.csv");
    
    // Inserting insert data into first line
    for(int i = 0; i < sizeof(insert)/sizeof(float); i++)
    {
        out_file << insert[i] << ',';
    }
    
    out_file << "\n";
    
    // Inserting search data into second line
    for(int i = 0; i < sizeof(search)/sizeof(float); i++)
    {
        out_file << search[i] << ',';
    }
    
    out_file << "\n";
    
    // Inserting insert colisions data into third line
    for(int i = 0; i < sizeof(search)/sizeof(float); i++)
    {
        out_file << insert_col[i] << ',';
    }
    
    out_file << "\n";
    
    // Inserting search colision data into fourth line
    for(int i = 0; i < sizeof(search)/sizeof(float); i++)
    {
        out_file << search_col[i] << ',';
    }
    
    out_file.close();
    
}