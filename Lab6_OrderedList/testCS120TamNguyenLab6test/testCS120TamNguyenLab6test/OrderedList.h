//--------------------------------------------------------------------
//
//  Laboratory 4                                         OrderedList.h
//
//  Class declaration for the array implementation of the Ordered
//  List ADT -- inherits the array implementation of the List ADT
//
//
//--------------------------------------------------------------------

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <stdexcept>
#include <iostream>

using namespace std;
#include "ListArray.h"

template < typename DataType, typename KeyType >
class OrderedList : public List<DataType>
{
  public:
     static const int DEFAULT_MAX_LIST_SIZE = 10; // Default maximum list size

    // Constructor
    /* Create default constructor
     @Pre: None
     @Post: Creates an empty list. Allocates enough memory for a list containing maxNumber data Items*/
    OrderedList ( int maxNumber = DEFAULT_MAX_LIST_SIZE );

    // Modified (or new) list manipulation operations
    
    /*Insert in appropriate position
     @pre: list is not empty
     @post: Insert newDataItem in its appropriate position.
            if a data item with the same key as newDataItem already exists > update that data with newdataitems
            Moves the cursor to mark newDataItem*/
    virtual void insert ( const DataType &newDataItem ) throw ( logic_error );
    
    /*Search data items
     @pre: none
     @post: searches a list for the data item with key searchKey
            if found data items: move cursor to data item, copy to searchDataItems >return true
            otherwise: return false*/
    bool retrieve ( const KeyType& searchKey, DataType &searchDataItem );
    
    /* Replace marked dataItems with newDataIem
     @pre: list is not empty
     @post: Replace marked dataItems with newDataIem
            Remove the data item at the cursor inserting newDataItem at the proper location
            Move cursor to newDataItem*/
    virtual void replace ( const DataType &newDataItem ) throw ( logic_error );
    
    
    // Output the list structure -- used in testing/debugging
    /*Show data items in the list
     @pre: none
     @post: outputs the data items in the list
     if the list is empty > "Empty list"*/
    void showStructure () const;

    // In-lab operations
    void merge ( const OrderedList<DataType,KeyType> &other ) throw ( logic_error );
    
    bool isSubset ( const OrderedList<DataType,KeyType> &other );

    // Inheritance using templates is somewhat ugly in C++. It feels like you
    // should be able to access base class member functions and data without the
    // scope resolution operator. Sadly, you cannot when using templates.
    // See http://www.parashift.com/c++-faq-lite/templates.html#faq-35.19
    // Tell compiler to use these base class methods.
    using List<DataType>::remove;
    using List<DataType>::clear;
    using List<DataType>::isEmpty;
    using List<DataType>::isFull;
    using List<DataType>::gotoBeginning;
    using List<DataType>::gotoEnd;
    using List<DataType>::gotoNext;
    using List<DataType>::gotoPrior;

private:
	
    // Locates an element (or where it should be) based on its key
    bool binarySearch ( KeyType searchKey, int &index );
	
    // Tell compiler to use these base class data members
    using List<DataType>::maxSize;
    using List<DataType>::cursor;
    using List<DataType>::size;
    using List<DataType>::dataItems;
};

#endif // #ifndef ORDEREDLIST_H










