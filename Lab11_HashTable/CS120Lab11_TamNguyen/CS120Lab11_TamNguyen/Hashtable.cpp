//
//  Hashtable.cpp
//  CS120Lab11_TamNguyen
//
//  Created by Nguyen Tam on 4/17/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//


#include <iostream>
#include "Hashtable.h"

using namespace std;

/* Default constructor
 @pre: none
 @post: Creates an empty Hash Table. Allocates enough memory for the Hash Table containing table_size*/
HashTable:: HashTable(int table_size): tableSize(table_size){
    Table.resize(tableSize);
}
    
/* Destructor
 @pre: none
 @post: Deallocates (free) the memory used to store the Hash Table*/
HashTable::~HashTable(){
}
    
/* Insert
 @pre: None
 @post: Inserts item into the table, a hashing function h
        is applied to the item to determine where it is to be placed in the table*/
void HashTable:: insert(const string & item){
    int index = hash(item);
    Table[index].push_front(item);
}
    
/* Overload Assigment operator
 @pre: None
 @post: Print each index in the table and a list of all the item stored ath that location*/
ostream & operator << (ostream &out, const HashTable& object) {
    int count = 0;
    for (vector<list<string>>::const_iterator j = object.Table.begin(); j != object.Table.end(); ++j) {
        cout << endl << "Index " << count <<": ";
        count ++;
        for(list<string>::const_iterator i = j->begin(); i != j->end(); ++i)
            cout << *i << "  ";
    }
    return out;
}

/* Find Key
 @pre: None
 @post: return true if key is in Hash Table. Otherwise, return false*/
bool HashTable:: isKeyInTable(const string & key) {
    int index = hash(key);
    for(list<string>::const_iterator i = Table[index].begin(); i != Table[index].end(); ++i)
        if (key == *i)
            return true;
    return false;
}

/* Retrieve key
 @pre: None
 @post: return the index location where the key is stored*/
int HashTable:: retrieveKey(const string & key) throw (logic_error) {
    if (!isKeyInTable(key))
        throw logic_error("Key is not in Hash Table");
    int index = hash(key);
    return index;
}

/* removeKey
 @pre: None
 @post: If key is in Hash Table, remove it and return true. Otherwise, return false*/
bool HashTable:: removeKey(const string & key) {
    if (!isKeyInTable(key)) {
        return false;
    }
    else {
        int index = hash(key);
        Table[index].remove(key);
        return true;
    }
}

/* print Collisons
 @pre: i must be smaller than size of the Hash Table
 @post:  print a list of items in the table at index i*/
void HashTable:: printCollisons(int i) throw (logic_error){
    if (i >= tableSize)
        throw logic_error("index must be smaller than table Size");
    else {
        for(list<string>::const_iterator j = Table[i].begin();  j != Table[i].end(); ++j)
            cout << *j << "  ";
    }
}

/* Hashing function
 @pre: None
 @post: Return the index where the aString should be stored in the Hash Table*/
int HashTable::  hash(const string & aString){
    int len = sizeof(aString);
    int index;
    if (len >= 3) {
        index = (aString[0]+aString[1]+aString[2]) % tableSize;
    }
    else if (len == 2) {
        index = (aString[0] + aString[1]) % tableSize;
    }
    else {
        index = aString[0] % tableSize;
    }
    return index;
}


