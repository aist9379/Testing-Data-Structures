#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <vector>
#include "doubleLL.hpp"

using namespace std;

int main()
{
    string dataSetA = "dataSetA-updated.csv";
    int size = 10000; // predetermined size of input data set
    int intArr[size]; // storing vals from the csv file
    float insert[50]; // store runtimes when we insert the data into the data structure 
    float search[50]; // store the search runtimes of when we search for items in the data structure
    
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

    // Calling double LL class
    doubleLL LL = doubleLL();
    
    
// ---------------------------- ** INSERTION TESTING ** ---------------------------- //
    // do 200 insertions 50 times
    x = 0; //incriments everytime an item from intArr is inserted into data structure

    for(int i = 0; i < 50; i++) 
    {
        auto start = chrono::steady_clock::now(); 

        // search next 200 items in data structure
        for(int p = 0; p < 200; p++)
        {
            // when calling nullptr, data will automatticlly be added at the end of the linked list
            LL.addNode(nullptr, intArr[x]);
            x++;
        }

        auto end = chrono::steady_clock::now();

        // time it took to read 200 items from data set
        insert[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200; // divide by 200 to get average
        
        
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
            LL.searchNode(randArray[p]);
        }

        end = chrono::steady_clock::now();

        // time it took to read 200 items from data set
        search[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200;              
    }
    
// ---------------------------- ** Writting Data ** ---------------------------- //
    ofstream out_file;
    out_file.open("Double_LL.csv");
    
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
    
    out_file.close();

}