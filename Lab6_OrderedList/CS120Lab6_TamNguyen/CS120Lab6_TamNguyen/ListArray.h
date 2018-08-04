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


// Constructors
/* Default constructor
 @pre: none
 @post: creates an entry with unnamed author and empty contents */
template <typename DataType>
List<DataType>:: List ( int maxNumber ) : maxSize(maxNumber), size(0), cursor(-1)
{
    dataItems = new DataType[maxSize];
}// Default constructor

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
                cout << &dataItems[j]
#ifdef ORDEREDLIST_CPP
                .getKey()
#endif
                ;
                cout << "]";
                cout << "\t";
            }
            else
                cout << &dataItems[j]
#ifdef ORDEREDLIST_CPP
                .getKey()
#endif
                << "\t";
        }
        cout << endl;
    }
}

// End outputs the data items in the list.

