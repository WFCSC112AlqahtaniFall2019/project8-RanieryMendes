#include <iostream>
#include <string>
#include <stack>
#include "Data.h"
#include <fstream>
#include <sstream>
#include <queue>


using namespace std;

int main() {

    //start program
    cout << "Opening program" << endl;
    cout << "Opening csv file" << endl;

    //create fstream object to get input
    ifstream getInputStack;

    //open csv file
    getInputStack.open("index.csv");

    //check if file was properly opened
    if(!getInputStack.is_open()){
        cout << "File to get input for Stack is not opened" << endl;
        return 1;
    }

    //create stack object to store Data objects
    stack <Data> newObj;

    cout <<"Reading data to store in Stack" << endl;
    //read data from dataset in "index.csv"
    for (int i = 0; i < 177; i++){

        //Create Data object to store data about countries
        Data objForStack;
        string cpi; // string that will be later converted into integer

        //read data to get country name
        getline(getInputStack, objForStack.countryName, ',');
        getInputStack.clear();

        //read data to get country code
        getline(getInputStack, objForStack.countryCode, ',');
        getInputStack.clear();

        //read data to get country region
        getline(getInputStack, objForStack.countryRegion, ',');
        getInputStack.clear();

        //read data to get country Corruption Index
        getline(getInputStack, cpi );
        int j;
        getInputStack.clear();
        std::istringstream ( cpi ) >> j; // convert string with CPI into an integer
        objForStack.CPI = j; //store finally the integer in Data CPI data member

        //push the object at the Stack
        newObj.push(objForStack);

    }

    //close file that provided input
    getInputStack.close();

    // create fstream object to print output
    ofstream outputStack;

    cout << "Opening output file for Stack" << endl;
    //open that output file
    outputStack.open("stacked.txt");

    //check if it was properly opened
    if(!outputStack.is_open()){
        cout << "Output file failed to open" << endl;
        return 1;
    }

    cout << "Printing from Stack into stacked.txt" << endl;
    //print all data from the stack into the txt file
    while(!newObj.empty()){
        outputStack << newObj.top();  // print data from Data object at the top of the stack
        newObj.pop(); //remove Data object at the top
    }

   //QUEUE

   //create fstream object to get input
    ifstream inputForQueue;

    //open file
    inputForQueue.open("index.csv");

    //check if it was properly opened
    if(!inputForQueue.is_open()){
        cout << "Input file is not opened" <<endl;
        return 1;
    }


//create queue object to store Data objects
    queue<Data> objInQueue;
    //read dataset from index.cvs
    cout <<"Reading data to store in Queue" << endl;
    for (int i =0; i<177; i++){

    //Data object to store data  about countries
        Data objForQueue;
        string cpi; //string to store Corruption Index that will be later converted into an integer

        //read data to get country name
        getline(inputForQueue, objForQueue.countryName, ',');
        inputForQueue.clear();

        //read data to get country code
        getline(inputForQueue, objForQueue.countryCode, ',');
        inputForQueue.clear();

        //read to get country region
        getline(inputForQueue, objForQueue.countryRegion, ',');
        inputForQueue.clear();

        //read to get country Corruption Index
        getline(inputForQueue, cpi );
        int j;
        inputForQueue.clear();
        std::istringstream ( cpi ) >> j; // convert string which has CPI content into an integer
        objForQueue.CPI = j;

        //push the object into the end of the queue
        objInQueue.push(objForQueue);
    }

    //close file
    inputForQueue.close();

    //create fstream object to print Data objects stored in the queue
    ofstream outputQueue;

    cout << "Opening output file for Queue" << endl;
    //open output file
    outputQueue.open("queued.txt");

    //check if it was properly opened
    if(!outputQueue.is_open()){
        cout << "Output file for Queue failed to open" << endl;
        return 1;
    }

    cout << "Printing from Queue into queued.txt" << endl;
    // print Data objects into the output file
    while(!objInQueue.empty()) {

        //print the Data object that is at the front of the queue
        outputQueue << objInQueue.front();
        //remove the Data object that is at the front of the queue
        objInQueue.pop();
    }

    //close output file for queue
    outputQueue.close();

    //PRIORITY QUEUE

    //create fstream object to read dataset from index.csv
    ifstream inputForPQ;

    //open file to get input
    inputForPQ.open("index.csv");

    //check if it was properly opened
    if(!inputForPQ.is_open()){
        cout << "Input File for priority queue failed to open" << endl;
        return 1;
    }

    //create priority Queue to store Data objects, sorting them.
    // The Data object with the highest CPI is at the top of the queue and the lowest at the end.
    priority_queue<Data, vector <Data>, less<>> objPriority;

    cout <<"Reading data to store in Priority Queue" << endl;
    //read data to store in Priority Queue object
    for (int k = 0; k < 177; ++k) {
        //create Data object to store info from dataset
        Data objForPQ;
        string cpi; //string to store Corruption Index that will latter converted into

        //read data to get country name
        getline(inputForPQ, objForPQ.countryName, ',');
        inputForPQ.clear();

        //read data to get country code
        getline(inputForPQ, objForPQ.countryCode, ',');
        inputForPQ.clear();

        //read data to get country region
        getline(inputForPQ, objForPQ.countryRegion, ',');
        inputForPQ.clear();

        //read data to get country corruption index
        getline(inputForPQ, cpi );
        int j;
        inputForPQ.clear();
        std::istringstream ( cpi ) >> j; //convert string that has corruption index data into integer
        objForPQ.CPI = j; //finally store into Data object the corruption index

        //push the object into the priority queue
        objPriority.push(objForPQ);

    }

    //close file that provided input
    inputForPQ.close();

    //create fstream object to print output from priority queue
    ofstream outputForPQ;

    cout << "Opening output file for Priority Queue" << endl;
    //open file
    outputForPQ.open("sorted.txt");

    //check if it was properly opened
    if (!outputForPQ.is_open()){
        cout << "Output file for priority queue failed to open"<< endl;
        return 1;
    }

    cout << "Printing from Priority Queue into sorted.txt" << endl;
    //print Data objects into output file
    while(!objPriority.empty()){
        outputForPQ << objPriority.top(); // print the Data object at the top of the queue
        objPriority.pop(); //remove Data object at top the queue

    }


    //finish program
    return 0;
}