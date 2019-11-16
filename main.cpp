#include <iostream>
#include <string>
#include <stack>
#include "Data.h"
#include <fstream>
#include <sstream>
#include <queue>


using namespace std;

int main() {

    cout << "Opening program" << endl;
    cout << "Opening csv file" << endl;

    //create fstream object to get input

    ifstream getInputStack;

    getInputStack.open("index.csv");

    if(!getInputStack.is_open()){
        cout << "File to get input for Stack is not opened" << endl;
        return 1;
    }

    stack <Data> newObj;
    for (int i = 0; i < 177; i++){

        Data objForStack;
        string cpi;

        getline(getInputStack, objForStack.countryName, ',');
        getInputStack.clear();

        getline(getInputStack, objForStack.countryCode, ',');
        getInputStack.clear();

        getline(getInputStack, objForStack.countryRegion, ',');
        getInputStack.clear();

        getline(getInputStack, cpi );
        int j;
        getInputStack.clear();
        std::istringstream ( cpi ) >> j;
        objForStack.CPI = j;

        //push the object at the Stack
        newObj.push(objForStack);

    }



    //close file
    getInputStack.close();

    ofstream outputStack;

    outputStack.open("stacked.txt");

    if(!outputStack.is_open()){
        cout << "Output file failed to open" << endl;
        return 1;
    }

    for (int i = 0; i < 177; i++){
        outputStack << newObj.top();
        newObj.pop();
    }


    ifstream inputForQueue;

    inputForQueue.open("index.csv");

    if(!inputForQueue.is_open()){
        cout << "Input file is not opened" <<endl;
        return 1;
    }


    queue<Data> objInQueue;
    for (int i =0; i<177; i++){

        Data objForQueue;
        string cpi;

        getline(inputForQueue, objForQueue.countryName, ',');
        inputForQueue.clear();

        getline(inputForQueue, objForQueue.countryCode, ',');
        inputForQueue.clear();

        getline(inputForQueue, objForQueue.countryRegion, ',');
        inputForQueue.clear();

        getline(inputForQueue, cpi );
        int j;
        inputForQueue.clear();
        std::istringstream ( cpi ) >> j;
        objForQueue.CPI = j;

        //push the object into the queue
        objInQueue.push(objForQueue);
    }

    //close file
    inputForQueue.close();

    ofstream outputQueue;

    outputQueue.open("queued.txt");

    if(!outputQueue.is_open()){
        cout << "Output file for Queue failed to open" << endl;
        return 1;
    }

    for (int i = 0; i < 177 ; ++i) {

        outputQueue << objInQueue.front();
        objInQueue.pop();
    }

    //close output file for queue
    outputQueue.close();

    ifstream inputForPQ;


    inputForPQ.open("index.csv");

    if(!inputForPQ.is_open()){
        cout << "Input File for priority queue failed to open" << endl;
        return 1;
    }

    priority_queue<Data, vector <Data>, less<>> objPriority;

    for (int k = 0; k < 177; ++k) {
        Data objForPQ;
        string cpi;

        getline(inputForPQ, objForPQ.countryName, ',');
        inputForPQ.clear();

        getline(inputForPQ, objForPQ.countryCode, ',');
        inputForPQ.clear();

        getline(inputForPQ, objForPQ.countryRegion, ',');
        inputForPQ.clear();

        getline(inputForPQ, cpi );
        int j;
        inputForPQ.clear();
        std::istringstream ( cpi ) >> j;
        objForPQ.CPI = j;

        //push the object into the  priority queue
        objPriority.push(objForPQ);

    }

    inputForPQ.close();

    ofstream outputForPQ;

    outputForPQ.open("sorted.txt");

    if (!outputForPQ.is_open()){
        cout << "Output file for priority queue failed to open"<< endl;
        return 1;
    }

    while(!objPriority.empty()){
        outputForPQ << objPriority.top();
        objPriority.pop();

    }



    return 0;
}