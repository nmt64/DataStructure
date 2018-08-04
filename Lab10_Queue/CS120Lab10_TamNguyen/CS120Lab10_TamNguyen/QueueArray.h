// QueueArray.h

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueArray : public Queue<DataType> {
  public:
    /* Default constructor
     @pre: none
     @post: Creates an empty array-based queue. Allocates enough memory for the queue containing          maxNumber data items */
    QueueArray(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    
    /* Copy structor
     @pre: None
     @post:  Initializes the queue to be equivalent to the other Queue object parameter*/
    QueueArray(const QueueArray& other);
    
    /* Overload Assignment operator
     @pre: none
     @post: Set the queue to be equivalent to the other and returns a reference to the modified queue*/
    QueueArray& operator=(const QueueArray& other);
    
    /* Destructor
     @pre: none
     @post: Deallocates (free) the memory used to store the queue */
    ~QueueArray();

    /* Enqueue
     @pre: List is not full
     @post: Inserts newDataItem at the rear of the queue */
    void enqueue(const DataType& newDataItem) throw (logic_error);
    
    /*Dequeue
     @pre: List is not empty
     @post:  Removes the least recently added (front) data item from the queue and returns it*/
    DataType dequeue() throw (logic_error);

    /* Clear list
     @pre: None
     @post: Returns true if the queue is empty. Otherwis return false*/
    void clear();

    /* Checking if the list is empty
     @pre: None
     @post:  Returns true if the queue is empty. Otherwise return false*/
    bool isEmpty() const;
    
    /* Checking if the list is full
     @pre: none
     @postL returns true if the queue is full. Otherwise, return false*/
    bool isFull() const;

//    void putFront(const DataType& newDataItem) throw (logic_error);
//    DataType getRear() throw (logic_error);
//    int getLength() const;

    /* Show structure
     @pre: none
     @post : Output the data items in queue. Output "Empty queue" if the queue is empty*/
    void showStructure() const;

  private:
    int maxSize; // maximum number of data items the queue can hold
    int front;  // the array index of the front data item
    int back;   // the array index of the rear data item
    DataType* dataItems;   // queue data items
};

#endif


/* Default constructor
 @pre: none
 @post: Creates an empty array-based queue. Allocates enough memory for the queue containing          maxNumber data items */
template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber): maxSize(maxNumber), front(-1), back(-1) {
    dataItems = new DataType[maxSize];
}

/* Copy structor
 @pre: None
 @post:  Initializes the queue to be equivalent to the other Queue object parameter*/
template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other): maxSize(other.maxSize), front(other.front), back(other.back) {
    dataItems = new DataType[maxSize];
    for (int i = 0; i < maxSize; i++){
        dataItems[i] = other.dataItems[i];
    }
}

/* Overload Assignment operator
 @pre: none
 @post: Set the queue to be equivalent to the other and returns a reference to the modified queue*/
template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other) {
    if (this != &other){
        if (other.maxSize > maxSize){
            delete [] dataItems;
            maxSize = other.maxSize;
            dataItems = new DataType(maxSize);
        }
        
        front = other.front;
        back = other.back;
        for (int i = 0; i < maxSize; i++){
            dataItems[i] = other.dataItems[i];
        }
        
    }
    return *this;
}

/* Destructor
 @pre: none
 @post: Deallocates (free) the memory used to store the queue */
template <typename DataType>
QueueArray<DataType>::~QueueArray() {
    delete [] dataItems;
}

/* Enqueue
 @pre: List is not full
 @post: Inserts newDataItem at the rear of the queue */
template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error) {
    if (isFull()) {
        throw logic_error("Queue is full");
    }
    else if (isEmpty()) {
        front = (front + 1)%maxSize;
        back = (back+1)%maxSize;
        dataItems[back] = newDataItem;
    }
    else {
        back = (back+1)%maxSize;
        dataItems[back] = newDataItem;
    }
}

/*Dequeue
 @pre: List is not empty
 @post:  Removes the least recently added (front) data item from the queue and returns it*/
template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error) {
    if (isEmpty()) {
        throw logic_error("Queue is empty");
    }
    
    DataType item = dataItems[front];
    
    if (front == back) {
        front = -1;
        back = -1;
    }
    
    else {
        front = (front + 1)%maxSize;
    }
    return item;
}


/* Clear list
 @pre: None
 @post: Returns true if the queue is empty. Otherwis return false*/
template <typename DataType>
void QueueArray<DataType>::clear() {
    front = -1;
    back = -1;
}

/* Checking if the list is empty
 @pre: None
 @post:  Returns true if the queue is empty. Otherwise return false*/
template <typename DataType>
bool QueueArray<DataType>::isEmpty() const {
    return (front == -1);
}

/* Checking if the list is full
 @pre: none
 @postL returns true if the queue is full. Otherwise, return false*/
template <typename DataType>
bool QueueArray<DataType>::isFull() const {
    return ((back+1)%maxSize == front);
}
//
//void putFront(const DataType& newDataItem) throw (logic_error);
//DataType getRear() throw (logic_error);
//int getLength() const;

/* Show structure
 @pre: none
 @post : Output the data items in queue. Output "Empty queue" if the queue is empty*/
template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter
    
    if ( front == -1 )
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front = " << front << "  Back = " << back << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        if ( back >= front )
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) && ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
                else
                    for ( j = 0 ; j < maxSize ; j++ )
                        if ( ( j >= front ) || ( j <= back ) )
                            cout << dataItems[j] << "\t";
                        else
                            cout << " \t";
        cout << endl;
    }
}




