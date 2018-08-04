//
//  ListArray.cpp
//  Cs120Lab5_TamNguyen
//
//  Created by Nguyen Tam on 2/13/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <iostream>
#include <stdexcept>

using namespace std;

// Constructors
/* Default constructor
 @pre: none
 @post: creates an entry with unnamed author and empty contents */
template < typename DataType>
List<DataType>:: List ( int maxNumber) : size(0), maxSize(maxNumber), cursor(-1)
{
    if (maxNumber <= 0 )
        throw logic_error("maxNumber must be larger than 0");
    else
    {
        dataItems = new DataType[maxSize];
    }
} // Default constructor

/* Copy constructor
 @pre: none
 @post: Initializes the list to be equivalent to the other List object parameter*/
template < typename DataType>
List<DataType>:: List ( const List& source )
{
    dataItems = new DataType(source.maxSize);
    size = source.size;
    maxSize = source.maxSize;
    cursor = source.cursor;
    
    for(int i = 0; i < size; i++)
    {
        dataItems[i] = source.dataItems[i];
    }
    
}// End copy constructor

template <typename DataType>
List<DataType>& List<DataType>:: operator= ( const List &source )

// Overloaded assignment operator. Resets a list object to contain a
// deep-copy of the provided model object, source.

{
    // Set buffer to correct size. If current buffer too small, allocate a new one.
    // NOTE: this also happens to protect against self-destruction.  Explicit
    // checks against &source vs. this will appear later (e.g. Stack).
    if( source.maxSize > maxSize )
    {
        delete [] dataItems;
        dataItems = new DataType[maxSize];
    }
    
    maxSize = source.maxSize;
    size = source.size;
    cursor = source.cursor;
    
    for( int i=0; i<size; i++ )
    {
        dataItems[i] = source.dataItems[i];
    }
    
    // Return an object reference to support multiple assignment.
    return *this;
} //End overloaded assignment operator

template <typename DataType>
List<DataType>:: ~List ()
{
    //
} // End destructor

template <typename DataType>
void List<DataType>::insert ( const DataType& newDataItem ) throw (logic_error)
{
    if (size >= maxSize)
        throw logic_error ("The list is full");
    else if (size != 0)
    {
        for (int i = size; i > cursor; i--)
        {
            dataItems[i] = dataItems[i-1];    //insert newDataItem as the first (and only data item
        }
        dataItems[cursor + 1] = newDataItem; // if the list is not empty,
                                             //inserts newDataItem after the cursor
        size++;
        cursor++;
    }
    else
    {
        dataItems[0] = newDataItem;         // move the cursor to newDataItem
        size = 1;
        cursor = 0;
    }
} // End insert newDataItem into the list

template <typename DataType>
void List<DataType>:: remove() throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is empty");
    else if (size != 1)
    {
        for (int i = cursor; i < size; i++)
        {
            dataItems[i] = dataItems[i+1];
        }
        size --;
        if (cursor == size)      //check if cursor at the end,then move cursor to the beginning
            cursor = 0;
    }
    else
    {
        size = 0;
    }
} //End remove dataItem

template <typename DataType>
void List<DataType>:: replace ( const DataType& newDataItem) throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is emty");
    else
    {
            dataItems[cursor] = newDataItem;
    }
} // End replace the data item marked by the cursor with newDataItem
  // The cursor remains at newDataItem

template <typename DataType>
void List<DataType>:: clear()
{
    size = 0;
} // End clear list

template <typename DataType>
bool List<DataType>:: isEmpty() const
{
    if (size == 0)
        return true;
    
    return false;
} // end checking if the list is empty

template <typename DataType>
bool List<DataType>:: isFull() const 
{
    if (size == maxSize)
        return true;
    return false;
} // end checking if the list is full

template <typename DataType>
void List<DataType>:: gotoBeginning() throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is emtpy");
    else
        cursor = 0;
} //End moving the cursor to the data item at the beginning of the list

template <typename DataType>
void List<DataType>:: gotoEnd() throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is empty");
    else
        cursor = size-1;
} // End moving the cursor to the data item at the end of the list

template <typename DataType>
bool List<DataType>:: gotoNext() throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is empty");
    else if (cursor != size-1)
    {
        cursor++;
        return true;
    }
    else
    return false;
} // End moving the cursor to the next data item at the end of the list

template <typename DataType>
bool List<DataType>:: gotoPrior() throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is empty");
    else if (cursor != 0)
    {
        cursor --;
        return true;
    }
    return false;
}//End moving the cursor to the preceding data item in the list

template <typename DataType>
DataType List<DataType>:: getCursor() const throw (logic_error)
{
    if (size == 0)
        throw logic_error("The list is empty");
    else
        return dataItems[cursor];
}; // End return the value of the data item marked by the cursor

template <typename DataType>
void List<DataType>:: showStructure () const

// outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
    int j;   // loop counter
    
    if ( size == 0 )
        cout << "empty list" << endl;
        // The Ordered List code blows up below. Since this is just debugging
        // code, we check for whether the OrderedList is defined, and if so,
        // print out the key value. If not, we try printing out the entire item.
        // Note: This assumes that you have used the double-inclusion protection
        // in your OrderedList.cpp file by doing a "#ifndef ORDEREDLIST_CPP", etc.
        // If not, you will need to comment out the code in the section under
        // the "else", otherwise the compiler will go crazy in lab 4.
        // The alternative is to overload operator<< for all data types used in
        // the ordered list.
        else
    {
        cout << "size = " << size
        <<  "   cursor = " << cursor << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        for ( j = 0 ; j < size ; j++ ) {
            if( j == cursor ) {
                cout << "[";
                cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
                .getKey()
#endif
                ;
                cout << "]";
                cout << "\t";
            }
            else
                cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
                .getKey()
#endif
                << "\t";
        }
        cout << endl;
    }
        }
        
// End outputs the data items in the list.


