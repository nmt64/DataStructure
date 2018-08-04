//
//  main.cpp
//  CS120Lab6_TamNguyen
//
//  Created by Nguyen Tam on 2/16/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//


#include <iostream>
#include <stdexcept>

using namespace std;

#include "OrderedList.h"

/* Create default constructor
 @Pre: None
 @Post: Creates an empty list. Allocates enough memory for a list containing maxNumber data Items*/
template < typename DataType, typename KeyType>
OrderedList<DataType,KeyType>:: OrderedList ( int maxNumber) : List<DataType> (maxNumber)
{
   //
} // End default constructor

/*Insert in appropriate position
 @pre: list is not empty
 @post: Insert newDataItem in its appropriate position.
 if a data item with the same key as newDataItem already exists > update that data with newdataitems
 Moves the cursor to mark newDataItem*/
template < typename DataType, typename KeyType>
void OrderedList<DataType,KeyType>::insert ( const DataType& newDataItem ) throw (logic_error)
{
    if (size >= maxSize)
        throw logic_error ("The OrderedList is full\n"); // Requires that list is not full
    
    bool search = binarySearch(newDataItem.getKey(), cursor);
    if (search)
    {
        dataItems[cursor] = newDataItem;
    }
    
    else
    {
        for ( int j = size ; j > cursor+1 ; j-- )
            dataItems[j] = dataItems[j-1];
            dataItems[++cursor] = newDataItem;
            size ++;
        
    }
}// End insert newDataItem into the OrderedList

/* Replace marked dataItems with newDataIem
 @pre: list is not empty
 @post: Replace marked dataItems with newDataIem
 Remove the data item at the cursor inserting newDataItem at the proper location
 Move cursor to newDataItem*/
template < typename DataType, typename KeyType>
void OrderedList<DataType,KeyType>:: replace ( const DataType& newDataItem) throw (logic_error)
{
    if (size == 0) {
        throw logic_error("The OrderedList is emty\n");
    }
    remove();
    insert(newDataItem);
} // End replace the data item marked by the cursor with newDataItem
// The cursor remains at newDataItem

/*Search data items
 @pre: none
 @post: searches a list for the data item with key searchKey
 if found data items: move cursor to data item, copy to searchDataItems >return true
 otherwise: return false*/
template < typename DataType, typename KeyType>
bool OrderedList<DataType,KeyType>:: retrieve (const KeyType& searchKey, DataType& searchDataItem)
{
    int DataIndex;
    bool search = binarySearch(searchKey, DataIndex);
    if (search)
    {
        cursor = DataIndex;
        searchDataItem = dataItems[cursor];
        return true;
    }
    else
        return false;
} // End retrieve

/* Binary search routine.
 @pre: none
 @post: Searches a list for the data item with key searchKey.
        If the data item is found > returns true with index returning the array index of the entry containing searchKey.
        Otherwise, returns false with index returning the array index of the entry containing the largest key that is smaller than searchKey
                    (or -1 if there is no such key) */
template < typename DataType, typename KeyType>
bool OrderedList<DataType,KeyType>:: binarySearch ( KeyType searchKey, int &index )

{
    int low  = 0,           // Low index of current search range
    high = size - 1;    // High index of current search range
    bool result;            // Result returned
    
    while ( low <= high )
    {
        index = ( low + high ) / 2;               // Compute midpoint
        if ( searchKey < dataItems[index].getKey() )
            high = index - 1;                      // Search lower half
        else if ( searchKey > dataItems[index].getKey() )
            low = index + 1;                       // Search upper half
        else
            break;                                 // searchKey found
    }
    
    if ( low <= high )
        result = true;       // searchKey found
    else
    {
        index = high;        // searchKey not found, adjust index
        result = false;
    }
    
    return result;
}

// Output the list structure -- used in testing/debugging
/*Show data items in the list
 @pre: none
 @post: outputs the data items in the list
 if the list is empty > "Empty list"*/
template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: showStructure () const
{
    if ( size == 0 )
        cout << "Empty list" << endl;
    else
    {
        cout << "size = " << size
        <<  "   cursor = " << cursor << endl;
        
        for ( int j = 0 ; j < maxSize ; ++j )
            cout << j << "\t";
        cout << endl;
        
        for ( int j = 0 ; j < size ; ++j ) {
            if( j == cursor ) {
                cout << "[" << dataItems[j].getKey() << "]\t";
            } else {
                cout << dataItems[j].getKey() << "\t";
            }
        }
        cout << endl;
    }
}

// End outputs the data items in the OrderedList.





