//
//  main.cpp
//  CS120Lab11_TamNguyen
//
//  Created by Nguyen Tam on 4/17/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <iostream>
#include "Hashtable.h"
#include <fstream>
#include <cassert>

using namespace std;


int main(){
    
    // TEST INPUT 1
    HashTable Hash1(13);
    
    ifstream infile1;
    string name1;
    
    infile1.open("test1.txt");
    if(infile1.fail())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    
    while(!infile1.eof())
    {
        infile1 >> name1;
        if(infile1.eof())
            break;
        Hash1.insert(name1);
        
    }
    
    
    infile1.close();
    
    cout << "Here is your hashtable of TEST 1 :" ;
    cout<< Hash1 << endl << endl;
    
    // TEST INPUT 2
    HashTable Hash2(13);
    
    ifstream infile2;
    string name2;
    
    infile2.open("test2.txt");
    if(infile2.fail())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    while(!infile2.eof())
    {
        infile2 >> name1;
        if(infile2.eof())
            break;
        Hash2.insert(name1);
        
    }
    
    infile2.close();
    
    cout << "Here is your hashtable of TEST2 :" ;
    cout<< Hash2 << endl << endl;
    
    
    // TEST FILE TXT
    HashTable aHash(13);
    
    cout << " enter a file name :";
    string inFileName;
    cin >> inFileName;
    ifstream infile;
    string name;
    infile.open(inFileName);
    if(infile.fail())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    while(!infile.eof())
    {
        infile >> name;
        if(infile.eof())
            break;
        aHash.insert(name);
        
    }
    infile.close();
    
    cout << "Here is your hashtable :" ;
    cout<< aHash;
    
    
    // TEST isKeyInTable
    cout << endl << "Enter the key you want to check: ";
    string key1;
    cin >> key1;
    if (aHash.isKeyInTable(key1))
        cout << key1 << " is in the table" << endl;
    else
        cout << key1 << " is not in the table" << endl;
    
    
    //TEST retrieveKey
    cout << endl << "Enter the key you want to retrieve: ";
    string key2;
    cin >> key2;
    cout << "The index of " << key2 << " is :" << aHash.retrieveKey(key2) << endl;
    
    
    // TEST remove
    cout << endl << "Enter the key you want to remove: ";
    string key3;
    cin >> key3;
    if (aHash.removeKey(key3))
        cout << "You have sucessfully removed " << key3 << endl;
    else
        cout << key3 << " is not in the table" << endl;
    cout << "The table list is now: " << endl;
    cout << aHash;
    
    
    //TEST printCollisions
    cout << endl << "Enter the index of list you want to print: ";
    int index1;
    cin >> index1;
    cout << "list of items in the table at index " << index1 <<":" << endl;
    aHash.printCollisons(index1);
    cout << endl;
    
    
    return 0;
}
