//--------------------------------------------------------------------
//
//  Laboratory 6                                          StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

public:
    /* Default constructor
     @pre: none
     @post: Creates an empty linked-list stack. Allocate enough memory for
            a stack containing maxNumber data item.*/
    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    
    /* Copy constructor
     @pre: none
     @post: Initialize the linked-list stack to be equivalent to the other*/
    StackLinked(const StackLinked& other);
    
    /*Assignment operator
     @pre: none
     @post:Set the linked-list stack to be equivalent to the other*/
    StackLinked& operator=(const StackLinked& other);
    
    /* Destructor
    @pre: none
    @post: Deallocates the memory used to store the stack*/
    ~StackLinked();
    
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
    bool isFull() const;
    
    /* showStructure
    @Pre:None
    @Post:Output the data items in a stack. Output "Empty stack"
    if the stack is empty*/
    void showStructure() const;
    
private:
    
    class StackNode {
    public:
        /* Default constructor of StackNode
         @pre: Create an initialized StackNode by setting the StackNode's data
         @post:  item to the value nodeData and its next pointer to value of nextPtr*/
        StackNode(const DataType& nodeData, StackNode* nextPtr);
        
        DataType dataItem; // Stack data item
        StackNode* next; // Pointer to next node
    };
    
    StackNode* top; // Pointer to the node contain the topmost data item in the stack
};

/* Default constructor of StackNode
@pre: Create an initialized StackNode by setting the StackNode's data
@post:  item to the value nodeData and its next pointer to value of nextPtr*/
template <typename DataType>
StackLinked<DataType>:: StackNode:: StackNode (const DataType& nodeData, StackNode* nextPtr) : dataItem(nodeData), next(nextPtr) {
    //
}

/* Default constructor
 @pre: none
 @post: Creates an empty linked-list stack. Allocate enough memory for
 a stack containing maxNumber data item.*/
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) : top(nullptr) {
    //
}

/* Copy constructor
 @pre: none
 @post: Initialize the linked-list stack to be equivalent to the other*/
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
    StackNode* currentPointer = other.top;
    
    if (currentPointer == nullptr) {
        top = nullptr;
    }
    
    else
    {
        top = new StackNode(currentPointer->dataItem, nullptr);
        StackNode* chainPointer = top;
        while(currentPointer->next != nullptr)
        {
            currentPointer = currentPointer-> next;
            chainPointer->next = new StackNode(currentPointer->dataItem, currentPointer->next);
            chainPointer = chainPointer->next;
        }
    }
}

/*Assignment operator
 @pre: none
 @post:Set the linked-list stack to be equivalent to the other*/
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
    if ( this != &other) {
        clear();
        StackNode* currentPointer = other.top;
        if (currentPointer == nullptr) {
            top = nullptr;
        }
        else {
            top = new StackNode(currentPointer->dataItem, currentPointer->next);
            StackNode* chainPointer = top;
            while(currentPointer->next != nullptr)
            {
                currentPointer = currentPointer-> next;
                chainPointer->next = new StackNode(currentPointer->dataItem, currentPointer->next);
                chainPointer = chainPointer->next;
            }
        }
    }
    return *this;
}

/* Destructor
 @pre: none
 @post: Deallocates the memory used to store the stack*/
template <typename DataType>
StackLinked<DataType>::~StackLinked(){
}

/*push:
 @pre: Stack is not full
 @post: inserts newDataItem into the top of the stack*/
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
    if (isFull()){
        throw logic_error("List is Full");
    }
    else {
        if (top == nullptr) {
            top = new StackNode(newDataItem, nullptr);
        }
        else {
            StackNode* newNode = new StackNode(newDataItem, top);
            top = newNode;
        }
    }
}

/*pop
 @pre: Stack is not empty
 @post: Removes the top data item from the stack and
 returns the value of the deleted item*/
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
    if (isEmpty()){
        throw logic_error("List is Empty");
    }
    else {
        DataType popNode = top->dataItem;
        StackNode* popNodePointer = top;
        top = top->next;
        delete popNodePointer;
        return popNode;
    }
}

template <typename DataType>
void StackLinked<DataType>::clear(){
    StackNode* currentPointer = top;
    if (top != nullptr){
        while(currentPointer!= nullptr)
        {
            currentPointer = currentPointer-> next;
            delete top;
            top = currentPointer;
        }
    }
}

/*isEmpty
 @Prec: None
 @post: Returns true if the stack is empty. Otherwise
 return false*/
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{
    if (top == nullptr)
        return true;
    return false;
}

/*isFull
 @pre: none
 @Post: Returns true if the stack is full. Otherwise
 return false*/
template <typename DataType>
bool StackLinked<DataType>::isFull() const {
    return false;
}





/* showStructure - This operation is
 // intended for testing and debugging purposes only.
 @Pre:None
 @Post:Output the data items in a stack. Output "Empty stack"
 if the stack is empty*/
template <typename DataType>
void StackLinked<DataType>::showStructure() const

{
    if( isEmpty() )
    {
        cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
        for (StackNode* temp = top; temp != 0; temp = temp->next) {
            if( temp == top ) {
                cout << "[" << temp->dataItem << "]\t";
            }
            else {
                cout << temp->dataItem << "\t";
            }
        }
        cout << "Bottom" << endl;
    }
    
}


#endif        //#ifndef STACKARRAY_H

