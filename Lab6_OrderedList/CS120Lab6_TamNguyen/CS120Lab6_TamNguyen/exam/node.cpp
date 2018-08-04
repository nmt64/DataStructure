
//
//  mainNode.cpp
//
//
//  Created by Denise Byrnes on 2/7/17.
//  Simple template Node struct - next we do this as a class
//

#include <iostream>
using namespace std;

template <class ItemType>
struct node{
    ItemType item;
    node* next;
};

int main(){
    //create a node and set its fields
    node<int> *nodePointer = new node<int>;
    nodePointer->item = 80;
    nodePointer->next = nullptr;
    
    //create a head pointer to list
    node<int> *headPointer = nodePointer;
    
    //insert a new node at head of list
    node<int> *tempPointer = new node<int>;
    tempPointer->item = 40;
    tempPointer->next = headPointer;
    headPointer = tempPointer;
    
    node<int> *currentPointer = headPointer;
    tempPointer = new node<int>;
    tempPointer->item = 20;
    tempPointer->next = headPointer;
    headPointer = tempPointer;
    
    //add a node at end of list
    currentPointer = headPointer;
    tempPointer = new node<int>;
    tempPointer->item = 10;
    tempPointer->next = headPointer;
    headPointer = tempPointer;
    
    //add a node between 7 and 5
    currentPointer = headPointer;
    while(currentPointer->next->item != 40)
    {
        currentPointer = currentPointer-> next;
    }

    tempPointer = new node<int>;
    tempPointer->item = 30;
    tempPointer->next = currentPointer->next;
    currentPointer->next = tempPointer;

    //traverse the list
    cout << "Traversing the list, after insert of 77 between 7 and 5" << endl;
    currentPointer = headPointer;
    while(currentPointer != nullptr)
    {
        cout << currentPointer->item << endl;
        currentPointer = currentPointer-> next;
    }

    
}
