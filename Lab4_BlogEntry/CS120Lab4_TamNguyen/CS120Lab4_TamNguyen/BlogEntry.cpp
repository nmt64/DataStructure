//
//  BlogEntry.cpp
//  CS120Lab4_TamNguyen
//
//  Created by Nguyen Tam on 2/5/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <iostream>
#include "BlogEntry.h"
#include <stdexcept>

BlogEntry :: BlogEntry() {
    
}
// end default constructor

BlogEntry :: BlogEntry ( const Text& iniAuthor, const Text& iniContents ) : author(iniAuthor), contents(iniContents)
{
    //
}
// Constructor

Text BlogEntry::getAuthor() const{
    return author;
} //end getAuthor
Text BlogEntry::getContents() const{
    return contents;
} //end getContents
Date BlogEntry::getCreateDate() const{
    return created;
} //end getCreateDate
Date BlogEntry::getModifyDate() const{
    return modified;
} //end getModifyDate

void BlogEntry:: setAuthor(const Text &newAuthor)
{
    modified = Date();
    author = newAuthor;
} //end setAuthor

void BlogEntry:: setContents(const Text &newContents)
{
    modified = Date();
    contents = newContents;
} //end setContents

void BlogEntry::showStructure() const {
    cout << "Author: " << author << endl;
    cout << "Created: " << created << endl;
    cout << "Modified: " << modified << endl;
    cout << "Content: " << contents << endl;
} //end ShowStructure

void BlogEntry:: printHTML(ostream &out) const {
    cout << "<html>" << endl << "<body>" << endl;
    cout << "<h1>" << author << "</h1>" << "<p>" << endl;
    cout << contents << endl;
    cout << "</p>" << endl << "<p>" << endl;
    cout << "Created: " << created << endl;
    cout << "</p>" << endl << "<p>" << endl;
    cout << "Last modified: " << modified << endl;
    cout << "</p>" << endl;
    cout << "</body>" << endl << "</html>" << endl;
} //end generate output in HTML

//end main


