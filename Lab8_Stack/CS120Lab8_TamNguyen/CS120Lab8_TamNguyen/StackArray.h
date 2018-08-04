//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
public:
    
    /* Default constructor
       @pre: none
       @post: Creates an empty array-based stack. Allocate enough memory for
     a stack containing maxNumber data item.*/
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    
    /* Copy constructor
     @pre: none
     @post: Initialize the array-based stack to be equivalent to the other*/
    StackArray(const StackArray& other);
    
    /* Assignment operator
     @pre: none
     @post: Set the array-based stack to be equivalent to the other*/
    StackArray& operator=(const StackArray& other);
    
    /*Destructor
     @pre: none
     @post: Deallocates the memory used to store the stack*/
    ~StackArray();
    
    /*push:
     @pre: Stack is not full
     @post: inserts newDataItem into the top of the stack*/
    void push(const DataType& newDataItem) throw (logic_error);
    
    /*pop
     @pre: Stack is not empty
     @post: Removes the top data item from the stack and
            returns the value of the deleted item*/
    DataType pop() throw (logic_error);
    
    /*clear
     @Precondition: None
     @Postcondition: Removes all the data items in the stack*/
    void clear();
    
    /*isEmpty
     @Prec: None
     @post: Returns true if the stack is empty. Otherwise
            return false*/
    bool isEmpty() const;
    
    /*isFull
    @pre: none
     @Post: Returns true if the stack is full. Otherwise
                    return false*/
    bool isFull() const;;
    
    /* showStructure
     @Pre:None
     @Post:Output the data items in a stack. Output "Empty stack"
            if the stack is empty*/
    void showStructure() const;
    
private:
    int maxSize; // maximum number of data items the stack can hold
    int top;    // the array index of the topmost data item
    DataType* dataItems;    // stack data items
};

/* Default constructor
@pre: none
@post: Creates an empty array-based stack. Allocate enough memory for
a stack containing maxNumber data item.*/
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : maxSize(maxNumber), top(-1){
    
    dataItems = new DataType[maxSize];
}

/* Copy constructor
 @pre: none
 @post: Initialize the array-based stack to be equivalent to the other*/
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other) : maxSize(other.maxSize), top(other.top){
    dataItems = new DataType[maxSize];
    for (int i = 0; i <= top; i++){
        dataItems[i] = other.dataItems[i];
    }
}

/* Assignment operator
 @pre: none
 @post: Set the array-based stack to be equivalent to the other*/
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){
    if (this != &other){
        if (other.maxSize > maxSize){
            delete [] dataItems;
            maxSize = other.maxSize;
            dataItems = new DataType(maxSize);
        }
        
        top = other.top;
        for(int i = 0; i <= top; i++){
            dataItems[i] = other.dataItems[i];
        }
        
    }
    return *this;
}

/*Destructor
 @pre: none
 @post: Deallocates the memory used to store the stack*/
template <typename DataType>
StackArray<DataType>:: ~StackArray(){
    clear();
}

/*push:
 @pre: Stack is not full
 @post: inserts newDataItem into the top of the stack*/
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error){
    if (isFull()) {
        throw logic_error("Stack is full");
    }
    else {
        top++;
        dataItems[top] = newDataItem;
    }
}
/*pop
 @pre: Stack is not empty
 @post: Removes the top data item from the stack and
 returns the value of the deleted item*/
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
    if (isEmpty()) {
        throw logic_error("Stack is empty");
    }
    else {
        top--;
        return dataItems[top + 1];
    }
}

/*clear
 @Precondition: None
 @Postcondition: Removes all the data items in the stack*/
template <typename DataType>
void StackArray<DataType>::clear(){
    top = -1;
}

/*isEmpty
 @Prec: None
 @post: Returns true if the stack is empty. Otherwise
 // return false*/
template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
    if (top == -1)
        return true;
    else
        return false;
}

/*isFull
 @pre: none
 @Post: Returns true if the stack is full. Otherwise
 return false*/
template <typename DataType>
bool StackArray<DataType>::isFull() const {
    if (top == maxSize - 1)
        return true;
    else
        return false;
}

/* showStructure. This operation is intended
 // for testing and debugging purposes only.
@Pre:None
@Post:Output the data items in a stack. Output "Empty stack"
if the stack is empty*/
template <typename DataType>
void StackArray<DataType>::showStructure() const

{
    if( isEmpty() ) {
        cout << "Empty stack." << endl;
    }
    else {
        int j;
        cout << "Top = " << top << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        for ( j = 0 ; j <= top  ; j++ )
        {
            if( j == top )
            {
                cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
            }
            else
            {
                cout << dataItems[j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}


#endif        //#ifndef STACKARRAY_H
