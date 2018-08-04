/**Header file for BlogEntry ADT*/
#include <stdexcept>
#include <iostream>

using namespace std;

#include "Text.h"
#include "Date.h"

class BlogEntry {
  public:
    /* Default constructor.
     @pre: none
     @post: creates an entry with unnamed author and empty contents*/
    BlogEntry();
    
    /* Constructor
     @pre: none
     @post: creates an entry initialized to the specified author and contents*/
    BlogEntry(const Text& initAuthor, const Text& initContents);
    
    /* Getter for Author
     @pre: none
     @post: getter for author
     @return value of author object */
    Text getAuthor() const;
    
    /* Getter for Contents
     @pre: none
     @post: getter for contents
     @return value of contents object */
    Text getContents() const;
    
    /* Getter for Create Date
     @pre: none
     @post: getter for Creation Date
     @return value of created object */
    Date getCreateDate() const;
    
    /* Getter for Modify date
     @pre: none
     @post: getter for modification date
     @return value of modified object */
    Date getModifyDate() const;
    
    /* Setter for Author
     @pre: none
     @post: setter for author
     @return: sets value of author object */
    void setAuthor(const Text& newAuthor);
    
    /* Setter for contents
     @pre: none
     @post: setter for contents
     @return: sets value of contents object */
    void setContents(const Text& newContents);

    /* Show contents of the Blog Entry - for testing/debugging only
     @pre: none
     @post: Contents of the BlogEntry*/
    void showStructure() const;

    // Programming Exercise 1
    /* Generate output in HTML
     @pre: none
     @post: sends output to the steam out */
    void printHTML( ostream& out ) const;

  private:
    Text author;
    Date created;
    Date modified;
    Text contents;
}; // end Blog Entry
