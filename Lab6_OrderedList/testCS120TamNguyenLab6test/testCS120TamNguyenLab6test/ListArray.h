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


#endif

