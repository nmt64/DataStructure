#include <fstream>
#include <string>
#include <iostream>

using namespace std;
#include "Text.h"

/* A command-line user interface that allows the user to read in a file
 * containing a program consisting of words or tokens separated by whitespace.
 * Requirements: none
 * Results: For each word in the file specified by the user (including any 
 * blank lines), each word is printed out on a new line in the form 1: [word1], where 1 
 * is a counter indicating the current number of the word and wordi is the ith
 * token in the file.
 * Author: Denise Byrnes, 9/15/2011
 *
 *NOTE: Copy your input file into the XCode project folder where your executable
 *resides - Look in the DEBUG folder.
 */
int main() {
    int count = 1;
    Text object;
	//set up counter and Text object
	
	string fileName; 
	cout << "Enter a file name: "; 
	cin >> fileName; 

	ifstream in;				// Object representing input from a file.
	in.open(fileName.c_str());		// Open the file for reading.
	if (in.is_open()) {
		
		while (!in.eof()) {		// While we haven't reached the end of file... 

            in >> object; // Read the next word as a Text object.
				
				if(in.eof()) break;  //if word read is eof char. then exit loop
							   // without printing the word
            cout << count << ": ["<< object << "]" << endl;
				// Print word as specified in requirements
				
            count += 1;
				
		}
		in.close();		// Close the file.
		
	} else {
		cout << "Error: Couldn't read " << fileName << endl;
		
	}
}
