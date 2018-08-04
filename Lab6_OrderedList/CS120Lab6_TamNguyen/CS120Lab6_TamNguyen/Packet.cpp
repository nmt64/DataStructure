//
//  Packet.cpp
//  CS120Lab6_TamNguyen
//
//  Created by Nguyen Tam on 2/21/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include "Packet.hpp"
//--------------------------------------------------------------------
//
//  Laboratory 4, Programming Exercise 1                    packet.cpp
//
//  "Starter kit" for the packet reassembly program
//
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

#include "OrderedList.h"

// Reads a series of packets, formats them into a message, and
// outputs the message.

class Packet {
public:
    static const int PACKET_SIZE = 6;  // Number of characters in a packet
    // including null ('\0') terminator,
    // but excluding the key (1st char in each line).
    int position;              // (Key) Packet's position w/in message
    char body[PACKET_SIZE];    // Characters in the packet
    
    int getKey () const
    { return position; }   // Returns the key field
};

//--------------------------------------------------------------------

int main()
{
    ifstream messageFile ("message.dat");   // Message file
    OrderedList<Packet,int> message;        // Message
    Packet currPacket;                      // Message packet
    int j;                                  // Loop variable
    
    // Read in the packets
    currPacket.body[Packet::PACKET_SIZE-1] = '\0';
    while ( messageFile >> currPacket.position )
    {
        // currPacket.position has just been read from the input
        
        messageFile.getline(currPacket.body,Packet::PACKET_SIZE,'\n');
        // currPacket.body has just been read from the input
        
        // I/O problem could happen during getline.
        // Check that I/O problem-free before inserting packet.
        if ( messageFile )
            message.insert(currPacket); // Insert currPacket into the OrderedList
    
    // Output the message packet-by-packet.
        if (message.isEmpty())
            cout << "File is empty" << endl;
        else
        {
            for ( j = 0; j < Packet::PACKET_SIZE; j++)
                cout << "" << message.getCursor().body[j] <<endl;
        while (message.gotoNext());
        }
        cout << endl;
    
    return 0;
    }
}
