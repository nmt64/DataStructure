//
//  Text.cpp
//  CS120_LAB3_TamNguyen
//
//  Created by Nguyen Tam on 1/30/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include "Text.h"
#include <iomanip>

Text:: Text ( const char *charSeq )
{
    bufferSize = (int)strlen(charSeq) + 1;
    buffer = new char [ bufferSize ];
    strcpy(buffer,charSeq);
}

Text:: Text ( const Text&valueText) : bufferSize(valueText.bufferSize)
{
    buffer = new char [bufferSize];
    strcpy(buffer,valueText.buffer);
}

/* Assigns other to a Text object.
 Precondition:none
 Postcondition: left side of = right
 side*/
 
 void Text:: operator = ( const Text&other )
{
     if(this != &other) {
     int rlen = other.getLength();
     
     if ( rlen >= bufferSize ) // If other will not fit
     
     delete [] buffer;         // Release buffer and
     bufferSize = rlen + 1;     // allocate a new larger buffer
     buffer = new char[ bufferSize ];
     }
 
     strcpy(buffer,other.buffer);    //Copy other's buffer
     bufferSize = other.bufferSize;  //Copy other's bufferSize
}

Text:: ~Text()
//Frees the memory used by the Text object buffer
{
    delete [] buffer;
    bufferSize = 0;
}

int Text:: getLength () const
{
    return bufferSize -1;
}

char Text:: operator[](int n) const
{
    if(bufferSize>n)
        return buffer[n];
    else
        return '\0';
}

void Text:: clear(){
    delete [] buffer;
    bufferSize = 1;
    buffer = new char [bufferSize];
    buffer[0]='\0';
}

void Text:: showStructure() const
// Outputs the charaters in a string. This operation is intended for
// testing/debugging purposes only.

{
    int j; //Loop counter
    
    for (j = 0; j < bufferSize ; j++)
        cout << j << "\t";
    cout << endl;
    for ( j = 0; buffer[j] != '\0';j++)
        cout << buffer[j] << "\t";
    cout << "\\0" << endl;
}

//--------------------------------------------------------------------

istream & operator >> ( istream &input, Text &inputText )

// Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.

{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer
    
    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.
    
    input >> setw(textBufferSize) >> textBuffer;
    
    // Apply the Text(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputText using the
    // assignment operator.
    
    inputText = textBuffer;
    
    // Return the state of the input stream.
    
    return input;
}

//--------------------------------------------------------------------

ostream & operator << ( ostream &output, const Text &outputText )

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
    output << outputText.buffer;
    return output;
}

// Relational operations (Programming Exercise 3)
bool Text:: operator == ( const Text& other ) const{
    return(strcmp(buffer, other.buffer)==0);
}
bool Text:: operator <  ( const Text& other ) const{
    return(strcmp(buffer, other.buffer)<0);
}
bool Text:: operator >  ( const Text& other ) const{
    return(strcmp(buffer, other.buffer)>0);
}



