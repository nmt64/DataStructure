//--------------------------------------------------------------------
//
//  Laboratory 3                                           ListArray.h
//  **Instructor's Solution**
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType >
class List
{
  public:

    static const int MAX_LIST_SIZE = 10;   // Default maximum list size
    
    // Constructors
    /* Default constructor
     @pre: none
     @post: creates an entry with unnamed author and empty contents */
    List ( int maxNumber = MAX_LIST_SIZE );    // Default constructor
    
    /* Copy constructor
     @pre: none
     @post: Initializes the list to be equivalent to the other List object parameter*/
    List ( const List& source );        // Copy constructor
    
    /* Overloaded assignment operator
     @pre: none
     @post: oveloaded assignment operator. Sets the list to be equivalent to the other object
     parameter and returns a reference to the object*/
    List& operator= ( const List& source );
    
    /* Destructor
     @pre: none
     @post: destructor. deallocates (free) memory osed to store the list*/
    virtual ~List ();
    
    // List manipulation operations
    
    /*Insert after cursor
     @pre: list is not empty
     @post: Insert newDataItem into the list.
     if the list is not empty, insert newDataItem after the cursor.
     otherwise, inserts newDataItem as the first (and only) data item in the list
     either case, moves the cursor to newDataItem*/
    virtual void insert ( const DataType& newDataItem ) throw ( logic_error );
    
    /*Remove data item
     @pre: list is not empty
     @post: Remove the data item marked by the cursor from the list.
     if the list is not empty, the cursor should now be marking the data item that followed the deleted data item
     if the delted data item was at the end of the list > cursor markeds the data item at the beginning of the list
     this operation preserves the order of the remaining data items in the list. */
    void remove () throw ( logic_error );
    
    /*Replace the data item
     @pre: list is not empty
     @post: Replaces the data item marked by the cursor with newDataItem. The cursor remains at           newDataItem*/
    virtual void replace ( const DataType& newDataItem ) throw ( logic_error );
    
    /*Remove all data items
     @pre: none
     @post: removes all the data items in the list*/
    void clear ();
    
    // List status operations
    
    /*Checking the list is empty or not
     @pre: none
     @post: returns true if the list is empty. Otherwise returns false*/
    bool isEmpty () const;
    
    /*Checking the list is full
     @pre: none
     @post: returns true if the list is full. Otherwise returns false*/
    bool isFull () const;
    
    // List iteration operations
    
    /*Moving cursor to the beginning
     @pre: List is not empty
     @post: if the list is not empty, move the cursor to the data item at the beginning of the list*/
    void gotoBeginning ()
    throw ( logic_error );
    
    /*Moving curosr to the end
     @pre: List is not empty
     @post: if the list is not empty, move the cursor to the data item at the end of the list*/
    void gotoEnd ()
    throw ( logic_error );
    
    /*Moving curosr to the next data item
     @pre: List is not empty
     @post: Moving curosr to the next data item if the cursor is not at the end, return true
     otherwise, return false*/
    bool gotoNext ()
    throw ( logic_error );
    
    /*Moving curosr to the prior data item
     @pre: List is not empty
     @post: Moving curosr to the prior data item if the cursor is not at the beginning, return true
     otherwise, return false*/
    bool gotoPrior ()                         // Go to prior data item
    throw ( logic_error );
    
    /*Get cursor
     @pre: list is not empty
     @post: returns the value of the data item marked by the cursor*/
    DataType getCursor () const
    throw ( logic_error );                // Return data item
    
    // Output the list structure -- used in testing/debugging
    /*Show data items in the list
     @pre: none
     @post: outputs the data items in the list
     if the list is empty > "Empty list"*/
    virtual void showStructure () const;
    
    // In-lab operations
    /* Move data item marked by cursor to posision n
     @pre: List is not empty
     @post: move data item to position n*/
    void moveToNth ( int n )
    throw ( logic_error );
    
    /* Find data item
     @pre: List is not empty
     @post: Return true if data item in the list, otherwise return false */
    bool find ( const DataType& searchDataItem )
    throw ( logic_error );

  protected:

    // Data members
    int maxSize,
        size,             // Actual number of data item in the list
        cursor;           // Cursor array index
    DataType *dataItems;  // Array containing the list data item
};


//--------------------------------------------------------------------
//
//  Laboratory 3                                         listarray
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>:: List ( int maxNumber )

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

: maxSize(maxNumber),
size(0),
cursor(-1)
{
    dataItems = new DataType[maxSize];
}

template <typename DataType>
List<DataType>:: List ( const List &source)

// Copy constructor. Creates a deep-copy list copied from 
// the provided model object, source.

: maxSize(source.maxSize),
size(source.size),
cursor(source.cursor)
{
    dataItems = new DataType[maxSize];
    for( int i=0; i<size; i++ ) {
        dataItems[i] = source.dataItems[i];
    }
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>& List<DataType>:: operator= ( const List &source ) 

// Overloaded assignment operator. Resets a list object to contain a
// deep-copy of the provided model object, source.

{
    // Set buffer to correct size. If current buffer too small, allocate a new one.
    // NOTE: this also happens to protect against self-destruction.  Explicit
    // checks against &source vs. this will appear later (e.g. Stack).
    if( source.maxSize > maxSize ) {
        delete [] dataItems;
        dataItems = new DataType[maxSize];
    }
    
    maxSize = source.maxSize;
    size = source.size;
    cursor = source.cursor;
    
    for( int i=0; i<size; i++ ) {
        dataItems[i] = source.dataItems[i];
    }
    
    // Return an object reference to support multiple assignment.
    // E.g., "a = b = c".
    return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>:: ~List ()

// Frees the memory used by a list.

{
    delete [] dataItems;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: insert ( const DataType &newDataItem ) 
throw ( logic_error )

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
    int j;   // Loop counter
    
    // Requires that list is not full
    if ( size >= maxSize )
        throw logic_error("list is full\n");
    
    for ( j = size ; j > cursor+1 ; j-- )
        dataItems[j] = dataItems[j-1];
    size++;
    dataItems[++cursor] = newDataItem;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: remove () throw ( logic_error )

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
    int j;   // Loop counter
    
    // Requires that the list is not empty
    if ( size == 0 )
    	throw logic_error("size == 0\n");
    
    for ( j = cursor ; j < size-1 ; j++ )
        dataItems[j] = dataItems[j+1];
    size--;
    if ( size == 0 )
        cursor = -1;
    else if ( size == cursor )
        cursor = 0;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: replace ( const DataType &newDataItem )
throw ( logic_error )

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
    // Requires that the list is not empty
    if ( size == 0 )
    	throw logic_error("size == 0\n");
    
    dataItems[cursor] = newDataItem;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: clear ()

// Removes all the data items from a list.

{
    size = 0;
    cursor = -1;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>:: isEmpty () const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
    return ( size == 0 );
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>:: isFull () const

// Returns 1 if a list is full. Otherwise, returns 0.

{
    return ( size == maxSize );
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: gotoBeginning () throw ( logic_error )

// Moves the cursor to the beginning of the list.

{
    if ( size == 0 )
        throw logic_error("list is empty");
    
    cursor = 0;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: gotoEnd () throw ( logic_error )

// Moves the cursor to the end of the list.

{
    if ( size == 0 )
        throw logic_error("list is empty");
    
    cursor = size - 1;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>:: gotoNext () throw ( logic_error )

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
    if ( size == 0 )
        throw logic_error("list is empty");
    
    if ( cursor != size-1 )
    {
        cursor++;
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>:: gotoPrior () throw ( logic_error )

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
    if ( size == 0 )
        throw logic_error("list is empty");
    
    if ( cursor != 0 )
    {
        cursor--;
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------

template <typename DataType>
DataType List<DataType>:: getCursor () const throw ( logic_error )

// Returns the item marked by the cursor.

{
    if ( size == 0 )
    	throw logic_error("list is empty\n");  // Requires that the list is not empty
    
    return dataItems[cursor];
}

//--------------------------------------------------------------------

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
#ifdef ORDEREDLIST_H
                .getKey()
#endif
                ;
                cout << "]";
                cout << "\t";
            }
            else
                cout << dataItems[j] 
#ifdef ORDEREDLIST_H
                .getKey()
#endif
                << "\t";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>:: moveToNth ( int n ) throw ( logic_error )

// Removes the data item marked by the cursor from a list and
// reinserts it as the nth data item in the list -- where the 
// data items are numbered from beginning to end, starting with 0.  
// Moves the cursor to the new position of the moved data
// item.

{
    int j;          // Loop counter
    DataType temp;  // Stores data item to be moved
    
    // Requires that the list is not empty
    if ( size == 0 )
    	throw logic_error("list is empty");  
    
    // Requires that the list is not empty
    if ( n >= size || n<0)
    	throw logic_error("n is not in valid range");
    
    // Requires that the list is not empty and that
    // there are at least n+1 data items in the list
    
    temp = dataItems[cursor];
    if ( n < cursor )
        for ( j = cursor-1 ; j >= n ; j-- )
            dataItems[j+1] = dataItems[j];
    else
        for ( j = cursor ; j < n ; j++ )
            dataItems[j] = dataItems[j+1];
    dataItems[n] = temp;
    cursor = n;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>:: find ( const DataType &searchDataItem ) throw ( logic_error )

// Searches a list for searchDataItem. Begins the search with the
// data items marked by the cursor. Moves the cursor through the list
// until either searchDataItem is found (returns true) or the end of the
// list is reached (returns false).

{
    if ( size == 0 )
    	throw logic_error("list is empty");  
    
    while ( cursor < size  &&  dataItems[cursor] != searchDataItem )
        cursor++;
    
    if ( cursor < size )
        return true;
    else
    {
        cursor--;
        return false;
    }
}


#endif

