//--------------------------------------------------------------------
//
//  Laboratory 5                                          ListLinked.h
//
//  Class declaration for the linked implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class List {
public:
    
    /*Constructor
     @pre: none
     @post: constructor. Create an empty list*/
    List(int ignored = 0);
    
    /*Copy constructor
     @pre: none
     @post: copy constructor. Initialize the list to be equivalent to the other list*/
    List(const List& other);
    
    /*Overloaded assigment operator
     @pre: none
     @post: overloaded assignment operator. Sets the list to be equivalent to the other lists and returns a reference to this object*/
    List& operator=(const List& other);
    
    /*Destructor
     @pre: none
     @post: destructor. Free memory used to store the nodes in the list*/
    ~List();
	
    /*Insert newDataItem into the list
     pre: list is not full
     @post: inserts the newDataItem into the list.
            If the list is not empty, then inserts newDataItems after the cursor.
            Otherwise, inserts newDataItem as the first and only data item in the list
            Move the cursor to newDataItem*/
    void insert(const DataType& newDataItem) throw (logic_error);
    
    /*Remove DataItem marked by cursor
     pre: list is not empty
     @post: Remove DataItem marked by cursor
            If the result is not empty, then moves the cursor to the data item that followed the deleted data item
            If the deleted data item was at the end of the list, then moves the cursor to the beginning of the list*/
    void remove() throw (logic_error);
    
    /*Replace data item marked by cursor
     @pre: list is not empty
     @post: replaces the data item marked by the cursor with newDataItem. The cursor remains at newDataItem*/
    void replace(const DataType& newDataItem) throw (logic_error);
    
    
    /*Replace duplicates from a sorted list*/
    void RemoveDuplicates(List<DataType> &List) throw (logic_error);
    
    /*Empty list
     @pre: none
     @post: removes all data item in the list*/
    void clear();
	
    /* Checking list is empty
     @pre: none
     @post: return true if the list is empty. Otherwise, return false*/
    bool isEmpty() const;
    
    /* Checking list is full
     @pre: none
     @post: return true if the list is full. Otherwise, return false*/
    bool isFull() const;
	
    /*Go to beginning of the list
     @pre: list is not empty
     @post: moves the cursor to the beginning of the list*/
    void gotoBeginning() throw (logic_error);
    
    /* Go to end of the list
     @pre: list is not empty
     @post: moves the cursor to the end of the list*/
    void gotoEnd() throw (logic_error);
    
    /*Go to next
     @pre: list is not empty
     @post: if the cursor is not at the end of the list, move the curosr to mart the next data item in the list > return true
            Otherwise, return false*/
    bool gotoNext() throw (logic_error);
    
    /*Go to prior
    @pre: list is not empty
    @post: if the cursor is not at the beginning of the list, move the curosr to mart the preceding data item in the list > return true
        Otherwise, return false*/
    bool gotoPrior() throw (logic_error);
	
    /*Get cursor
     @pre: list is not empty
     @post: return the value of the data item marked by the cursor*/
    DataType getCursor() const throw (logic_error);
	
    // Programming exercise 2
    void moveToBeginning () throw (logic_error);
	
    // Programming exercise 3
    void insertBefore(const DataType& newDataItem) throw (logic_error);
    
    /*Show structure
    @pre: none
    @post:Outputs the items in a list. If the list is empty, outputs
    "Empty list". This operation is intended for testing and
        debugging purposes only.*/
    void showStructure() const;
	
private:
    class ListNode {
	public:
        /*pre: none
         post: default constructor.
         creates an initialized ListNode by setting the ListNode's data item to the value nodeData and the ListNode's next pointer to the value of nextPtr*/
		ListNode(const DataType& nodeData, ListNode* nextPtr);
		
		DataType dataItem;
		ListNode* next;
    };
	
    ListNode* head;
    ListNode* cursor;
	
};

#endif


/*pre: none
 post: default constructor.
 creates an initialized ListNode by setting the ListNode's data item to the value nodeData and the ListNode's next pointer to the value of nextPtr*/


/*Constructor
 @pre: none
 @post: constructor. Create an empty list*/
template <typename DataType>
List<DataType>::List(int ignored) : head(nullptr), cursor(nullptr){
    //
}

/*Copy constructor
 @pre: none
 @post: copy constructor. Initialize the list to be equivalent to the other list*/
template <typename DataType>
List<DataType>::List(const List& other) {
    
    ListNode* currentPointer = other.head;
    
    if (currentPointer == nullptr) {
        head = nullptr;
        cursor = nullptr;
    }
    else {
        head = new ListNode(currentPointer -> dataItem, currentPointer->next);
        ListNode* chainPointer = head;
        cursor = chainPointer;
        while(currentPointer->next != nullptr)
        {
            currentPointer = currentPointer-> next;
            chainPointer->next = new ListNode(currentPointer->dataItem, currentPointer->next);
            chainPointer = chainPointer->next;
            if (other.cursor == currentPointer){
                cursor = chainPointer;
            }
        }
    }
}

/*Overloaded assigment operator
 @pre: none
 @post: overloaded assignment operator. Sets the list to be equivalent to the other lists and returns a reference to this object*/
template <typename DataType>
List<DataType>& List<DataType>:: operator=(const List& other) {
    if ( this != &other) {
        clear();
        ListNode* currentPointer = other.head;
        if (currentPointer == nullptr) {
            head = nullptr;
            cursor = nullptr;
        }
        else {
            head = new ListNode(currentPointer->dataItem, currentPointer->next);
            ListNode* chainPointer = head;
            cursor = chainPointer;
            while(currentPointer->next != nullptr)
            {
                currentPointer = currentPointer-> next;
                chainPointer->next = new ListNode(currentPointer->dataItem, currentPointer->next);
                chainPointer = chainPointer->next;
                if (other.cursor == currentPointer) {
                    cursor = chainPointer;
                }
            }
        }
    }
    return *this;
}

/*Destructor
 @pre: none
 @post: destructor. Free memory used to store the nodes in the list*/
template <typename DataType>
List<DataType>:: ~List() {
    clear();
}


/*Insert newDataItem into the list
 pre: list is not full
 @post: inserts the newDataItem into the list.
 If the list is not empty, then inserts newDataItems after the cursor.
 Otherwise, inserts newDataItem as the first and only data item in the list
 Move the cursor to newDataItem*/
template <typename DataType>
void List<DataType>:: insert(const DataType& newDataItem) throw (logic_error) {
    if (isFull()) {
        throw logic_error ("List is full");
    }
    else {
        if (head == nullptr) {
            head = new ListNode(newDataItem, nullptr);
            cursor = head;
        }
        else {
            ListNode *newNode = new ListNode(newDataItem,cursor ->next);
            cursor->next = newNode;
            cursor = cursor->next;
        }
    }
}

/*Remove DataItem marked by cursor
 pre: list is not empty
 @post: Remove DataItem marked by cursor
 If the result is not empty, then moves the cursor to the data item that followed the deleted data item
 If the deleted data item was at the end of the list, then moves the cursor to the beginning of the list*/
template <typename DataType>
void List<DataType>:: remove() throw (logic_error){
    if (isEmpty()) {
        throw logic_error ("List is empty");
    }
    else if (cursor-> next == nullptr)
    {
        if (head == cursor)
        {
            delete head;
            head = nullptr;
            cursor = nullptr;
        }
        else
        {
            ListNode* currentPointer = head;
            
            while(currentPointer->next != cursor)
            {
                currentPointer = currentPointer->next;
            }
            currentPointer-> next = nullptr;
            delete cursor;
            cursor = head;
            currentPointer = nullptr;
        }
    }
    else
    {
        if (head != cursor)
        {
            ListNode* currentPointer = head;
            while (currentPointer ->next != cursor)
            {
                currentPointer = currentPointer->next;
            }
            currentPointer->next = cursor->next;
            delete cursor;
            cursor = currentPointer->next;
            currentPointer = nullptr;
        }
        else {
            head = head->next;
            delete cursor;
            cursor = head;
        }
    }
}



/*Replace duplicates from a sorted list*/
template <typename DataType>
void List<DataType>:: RemoveDuplicates(List<DataType> &L) throw (logic_error) {
    
    ListNode *currentPointer = head;
    
    if(isEmpty()) {
        throw logic_error("List is empty");
    }
    
    while (currentPointer->next != nullptr) {
        if (currentPointer->dataItem == currentPointer->next->dataItem)
        {
            ListNode *deletePointer = currentPointer->next;
            currentPointer->next = currentPointer->next->next;
            delete(deletePointer);
        }
        else {
            currentPointer = currentPointer->next;
        }
    }
}


/*Replace data item marked by cursor
 @pre: list is not empty
 @post: replaces the data item marked by the cursor with newDataItem. The cursor remains at newDataItem*/
template <typename DataType>
void List<DataType>:: replace(const DataType& newDataItem) throw (logic_error){
    if (isEmpty()) {
        throw logic_error ("List is empty");
    }
    else {
        cursor ->dataItem = newDataItem;
    }
    
}  

/*Empty list
 @pre: none
 @post: removes all data item in the list*/
template <typename DataType>
void List<DataType>:: clear() {
    ListNode* currentPointer = head;
    while (currentPointer != nullptr) {
        currentPointer = currentPointer->next;
        delete head;
        head = currentPointer;
    }
    cursor = nullptr;
}

/* Checking list is empty
 @pre: none
 @post: return true if the list is empty. Otherwise, return false*/
template <typename DataType>
bool List<DataType>:: isEmpty() const{
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

/* Checking list is full
 @pre: none
 @post: return true if the list is full. Otherwise, return false*/
template <typename DataType>
bool List<DataType>:: isFull() const{
    return false;
}

/*Go to beginning of the list
 @pre: list is not empty
 @post: moves the cursor to the beginning of the list*/
void gotoBeginning() throw (logic_error);
template <typename DataType>
void List<DataType>:: gotoBeginning() throw (logic_error){
    if (isEmpty()) {
        throw logic_error ("List is empty");
    }
    else {
        cursor = head;
    }
    
}

/* Go to end of the list
 @pre: list is not empty
 @post: moves the cursor to the end of the list*/
template <typename DataType>
void List<DataType>:: gotoEnd() throw (logic_error){
    if (isEmpty()) {
        throw logic_error ("List is empty\n");
    }
    else {
        ListNode* currentPointer = head;
        while(currentPointer-> next != nullptr) {
            currentPointer = currentPointer-> next;
        }
        cursor = currentPointer;
        currentPointer = nullptr;
    }
}

/*Go to next
 @pre: list is not empty
 @post: if the cursor is not at the end of the list, move the curosr to mart the next data item in the list > return true
 Otherwise, return false*/
template <typename DataType>
bool List<DataType>:: gotoNext() throw (logic_error){
    if (isEmpty()) {
        throw logic_error("List is empty\n");
    }
    else if (cursor-> next != nullptr){
        cursor = cursor-> next;
        return true;
    }
    else {
        return false;
    }
    
}


/*Go to prior
 @pre: list is not empty
 @post: if the cursor is not at the beginning of the list, move the curosr to mart the preceding data item in the list > return true
 Otherwise, return false*/
template <typename DataType>
bool List<DataType>:: gotoPrior() throw (logic_error){
    if (isEmpty()) {
        throw logic_error("List is empty\n");
    }
    else if (cursor != head) {
        ListNode* currentPointer = head;
        while(currentPointer-> next != cursor){
            currentPointer = currentPointer->next;
        }
        cursor= currentPointer;
        currentPointer = nullptr;
        return true;
    }
    else {
        return false;
    }
}

/*Get cursor
 @pre: list is not empty
 @post: return the value of the data item marked by the cursor*/
template <typename DataType>
DataType List<DataType>:: getCursor() const throw (logic_error){
    if (isEmpty()) {
        throw logic_error ("List is empty");
    }
    else {
        return cursor ->dataItem;
    }
}


/*Show structure
 @pre: none
 @post:Outputs the items in a list. If the list is empty, outputs
 "Empty list". This operation is intended for testing and
 debugging purposes only.*/
template <typename DataType>
void List<DataType>::showStructure() const
{
    if ( isEmpty() )
    {
        cout << "Empty list" << endl;
    }
    else
    {
        for (ListNode* temp = head; temp != 0; temp = temp->next) {
            if (temp == cursor) {
                cout << "[";
            }
            
            // Assumes that dataItem can be printed via << because
            // is is either primitive or operator<< is overloaded.
            cout << temp->dataItem;
            
            if (temp == cursor) {
                cout << "]";
            }
            cout << " ";
        }
        cout << endl;
    }
}



