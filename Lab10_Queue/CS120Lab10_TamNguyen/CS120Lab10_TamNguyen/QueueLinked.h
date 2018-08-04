// QueueLinked.h

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueLinked : public Queue<DataType> {
  public:
    
    /*Constructure
     @pre: none
     @post: constructor. create an empty queue. Allocates enough memory for the queue containing maxNumber data items*/
    QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    
    /*Copy constructor
     @pre: none
     @post: copy constructor. Initializes the queue to be equivalent to the other Queue object*/
    QueueLinked(const QueueLinked& other);
    
    /* Overloaded Assigment
     @pre: None
     @post: over loaded assignment operator. Sets the queue to be equivalent to the other Queue object parameters and returns a reference to the modified queue?*/
    QueueLinked& operator=(const QueueLinked& other);
    
    /*destructor
     @pre: none
     @post: destructor. Deallocated (Frees) the memory used to store the queue*/
    ~QueueLinked();

    /* insert new item
     @pre: queue is not full
     @post: insert newDataItem at the rear of the queue*/
    void enqueue(const DataType& newDataItem) throw (logic_error);
    
    /* remove item
     @pre: queue is not empy
     @post:emove the least recently added data from the queue and return it */
    DataType dequeue() throw (logic_error);

    /* clear
     @pre: none
     @post: removes all the data items in the queue*/
    void clear();

    /* checking queue is empty
     @pre: none
     @post: return true if the queue is empty. Otherwise, return true.*/
    bool isEmpty() const;
    
    /* checking queue is full
     @pre: none
     @post: return full if the queue is full. Otherwise, return false*/
    bool isFull() const;

    // Programming Exercise 2
    void putFront(const DataType& newDataItem) throw (logic_error);
    DataType getRear() throw (logic_error);
    // Programming Exercise 3
    int getLength() const;

    /* showStrucure
     @pre: none
     @post: outputs the data items in the queue. If the queue is empty, output "empty". */
    void showStructure() const;

  private:
    class QueueNode {
      public:
      // Default constructor of QueueNode
      // Create an initialized QueueNode by setting the QueueNode's data
      // item to the value nodeData and its next pointer to value of nextPtr
      QueueNode(const DataType& nodeData, QueueNode* nextPtr);

	DataType dataItem; // Queue data item
    QueueNode* next;   // Pointer to next node
    };

    QueueNode* front;  // Pointer to the node contain the front data item of the queue
    QueueNode* back;   // Pointer to the node contain the rear data item of the queue
};




/* Default constructor of QueueNode
 @pre:None
 @post: Create an initialized QueueNode by setting the QueueNode's data
        item to the value nodeData and its next pointer to value of nextPtr*/
template <typename DataType>
QueueLinked<DataType>:: QueueNode:: QueueNode (const DataType& nodeData, QueueNode* nextPtr) : dataItem(nodeData), next(nextPtr) {
    //
}

/*Constructure
 @pre: none
 @post: constructor. create an empty queue. Allocates enough memory for the queue containing maxNumber data items*/
template <typename DataType>
QueueLinked<DataType>:: QueueLinked(int maxNumber) : front(nullptr), back(nullptr) {
    //
}

/*Copy constructor
 @pre: none
 @post: copy constructor. Initializes the queue to be equivalent to the other Queue object*/
template <typename DataType>
QueueLinked<DataType>:: QueueLinked(const QueueLinked& other){
    
    QueueNode* currentPointer = other.front;
    
    if (currentPointer == nullptr) {
        front = nullptr;
        back = nullptr;
    }
    
    else {
        front = new QueueNode(currentPointer -> dataItem, currentPointer->next);
        QueueNode* chainPointer = front;
        while(currentPointer-> next != nullptr)
        {
            currentPointer = currentPointer ->next;
            chainPointer->next = new QueueNode(currentPointer -> dataiTEM, nullptr);
            chainPointer = chainPointer->next;
        }
        back = chainPointer;
    }
}

/* Overloaded Assigment
 @pre: None
 @post: over loaded assignment operator. Sets the queue to be equivalent to the other Queue object parameters and returns a reference to the modified queue?*/
template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other) {
    if ( this != &other) {
        clear();
        QueueNode* currentPointer = other.front;
        if (currentPointer == nullptr) {
            front = nullptr;
            back = nullptr;
        }
        else {
            front = new QueueNode(currentPointer->dataItem, currentPointer->next);
            QueueNode* chainPointer = front;
            while(currentPointer->next != nullptr)
            {
                currentPointer = currentPointer-> next;
                chainPointer->next = new QueueNode(currentPointer->dataItem, nullptr);
                chainPointer = chainPointer->next;
            }
            back = chainPointer;
        }
    }
    return *this;
}

/*destructor
 @pre: none
 @post: destructor. Deallocated (Frees) the memory used to store the queue*/
template <typename DataType>
QueueLinked<DataType>::~QueueLinked() {
    //
}

/* insert new item
 @pre: queue is not full
 @post: insert newDataItem at the rear of the queue*/
template <typename DataType>
void QueueLinked<DataType>:: enqueue(const DataType& newDataItem) throw (logic_error) {
    if (isFull()) {
        throw logic_error("Queue is Full");
    }
    else {
        if (front == nullptr) {
            front = new QueueNode(newDataItem, nullptr);
            back = front;
        }
        else {
            back->next = new QueueNode(newDataItem, nullptr);
            back = back->next;
        }
    }
}

/* remove item
 @pre: queue is not empy
 @post:emove the least recently added data from the queue and return it */
template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error) {
    if (isEmpty()) {
        throw logic_error("Queue is Empty");
    }
    else {
        DataType popNode = front ->dataItem;
        QueueNode* popNodePointer = front;
        front = front->next;
        delete popNodePointer;
        return popNode;
    }
}

/* clear
 @pre: none
 @post: removes all the data items in the queue*/
template <typename DataType>
void QueueLinked<DataType>::clear() {
    QueueNode* currentPointer = front;
        if (front != nullptr){
            while(currentPointer!= nullptr)
            {
                currentPointer = currentPointer-> next;
                delete front;
                front = currentPointer;
            }
                back = nullptr;
        }
    }

/* checking queue is empty
 @pre: none
 @post: return true if the queue is empty. Otherwise, return true.*/
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const {
    return (front == nullptr);
}

/* checking queue is full
 @pre: none
 @post: return full if the queue is full. Otherwise, return false*/
template <typename DataType>
bool QueueLinked<DataType>::isFull() const {
    return false;
}

//// Programming Exercise 2
//void putFront(const DataType& newDataItem) throw (logic_error);
//DataType getRear() throw (logic_error);
//// Programming Exercise 3
//int getLength() const;

/* showStrucure
 @pre: none
 @post: outputs the data items in the queue. If the queue is empty, output "empty".
        For testing/debugging only*/
template <typename DataType>
void QueueLinked<DataType>:: showStructure () const
{
        QueueNode *p;   // Iterates through the queue
        
        if ( isEmpty() )
            cout << "Empty queue" << endl;
        else
        {
            cout << "Front\t";
            for ( p = front ; p != 0 ; p = p->next )
            {
                if( p == front )
                {
                    cout << '[' << p->dataItem << "] ";
                }
                else
                {
                    cout << p->dataItem << " ";
                }
            }
            cout << "\trear" << endl;
        }
}
        
 