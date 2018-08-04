//
//  Hashtable.hpp
//  CS120Lab11_TamNguyen
//
//  Created by Nguyen Tam on 4/17/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
class HashTable {
public:
    /* Default constructor
     @pre: none
     @post: Creates an empty Hash Table. Allocates enough memory for the Hash Table containing table_size*/
    HashTable(int table_size);
    
    /* Destructor
     @pre: none
     @post: Deallocates (free) the memory used to store the Hash Table*/
    ~HashTable();

    /* Insert
     @pre: None
     @post: Inserts item into the table, a hashing function h
     is applied to the item to determine where it is to be placed in the table*/
    void insert(const string & item);

    /* Assigment operator
     @pre: None
     @post: Print each index in the table and a list of all the item stored ath that location*/
    friend ostream & operator << (ostream &out, const HashTable& object);

    /* Find Key
     @pre: None
     @post: return true if key is in Hash Table. Otherwise, return false*/
    bool isKeyInTable(const string & key);

    /* Retrieve key
     @pre: None
     @post: return the index location where the key is stored*/
    int retrieveKey(const string & key) throw (logic_error);

    /* removeKey
     @pre: None
     @post: If key is in Hash Table, remove it and return true. Otherwise, return false*/
    bool removeKey(const string & key);

    /* print Collisons
     @pre: i must be smaller than size of the Hash Table
     @post:  print a list of items in the table at index i*/
    void  printCollisons(int i) throw (logic_error);
    
private:
    vector<list<string>> Table; // Hash Table data item
    int tableSize; // size of the Hash Table
    
    /* Hashing function
     @pre: None
     @post: Return the index where the aString should be stored in the Hash Table*/
    int hash(const string & aString) ;
};


#endif /* Hashtable_h*/

