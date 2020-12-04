/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.cpp
 *
 *  PURPOSE
 *
 *  Modified by: Sam Lacet-Brown
 *           On: Sept 16th, 2020
 *
 */

//TODO
/*
Fix array constructor
Fix single char constructor
*/

#include <iostream>
#include <sstream>
#include "CharArrayList.h"

using namespace std;
//done
//Default constructor
    CharArrayList::CharArrayList() {
        numItems = 0;
        capacity = START_SIZE;
        chars = new char[capacity];
        chars[0] = NULL;
    }

//Constructor that is passed a single char
CharArrayList::CharArrayList(char *c) {
    numItems = 1;
    capacity = START_SIZE;
    chars = new char[capacity];
    chars[0] = c[0];
    chars[1] = NULL;
}

//Constructor that is passed a char array and an inital size
//Note: size should be number of chars, not 0-index based
CharArrayList::CharArrayList(char *c, int size) {
    numItems = size;
    capacity = size;
    chars = new char[capacity];
    //expand();
    for(int i = 0; i < numItems; i++) {
        chars[i] = c[i];
    }
}

//done
//Copy constructor
CharArrayList::CharArrayList(const CharArrayList &other) {
    numItems = other.numItems;
    capacity = other.capacity;
    chars = new char[capacity];
    for(int i = 0; i < numItems; i++) {
        chars[i] = other.chars[i];
    }
}

//done
//Deconstructor
    CharArrayList::~CharArrayList() {
        delete [] chars;
    }

//done
//Assignment operator
    CharArrayList &CharArrayList::operator =(const CharArrayList &other) {
        if(this != &other) {
            delete [] chars;
            chars = NULL;
            numItems = other.numItems;
            capacity = other.capacity;
            chars = new char[capacity];
            for(int i = 0; i < numItems; i++) {
                chars[i] = other.chars[i];
            }
        }
        return *this;
    }

//done
/* isEmpty
    * Purpose: To determine if this instance of the class is empty
    * Parameters: none
    * Returns: A bool that is true if the class has no characters
    */
    bool CharArrayList::isEmpty() {
        if(numItems == 0) {
            return true;
        } else {
            return false;
        }
    }

//done
/* clear
    * Purpose: To empty this instance of the class
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::clear() {
        numItems = 0;
        capacity = START_SIZE;
        char chars[capacity];
        chars[0] = NULL;
    }

//done
/* size
    * Purpose: To determine the current length of the char array list
    * Parameters: none
    * Returns: An int value equal to the number of items in the list
    */
    int CharArrayList::size() {
        return numItems;
    }

//done
/* first
    * Purpose: To determine the first element
    * Parameters: none
    * Returns: The char element in the 0th position of the list
    */
    char* CharArrayList::first() {
        if(isEmpty()) {
            throw runtime_error("cannot get first of empty ArrayList");
        }
        char *letter;
        letter = &chars[0];
        return letter;
    }

//done
/* last
    * Purpose: To determine the last element
    * Parameters: none
    * Returns: The last char element in the list
    */
    char* CharArrayList::last() {
        if(isEmpty()) {
            throw runtime_error("cannot get first of empty ArrayList");
        }
        return &chars[numItems-1];
    }

//done
/* elementAt
    * Purpose: Find a char element at a particular index
    * Parameters: none
    * Returns: A char located at the nth index
    */
    char* CharArrayList::elementAt(int index) {
        if(index > numItems-1) {
            ostringstream oerr;
            oerr << "index (" << index << ") not in range [0.." << numItems << ")";
            string err = oerr.str();
            throw range_error(err);
        }
        char *letter;
        letter = &chars[0];
        return letter;
    }

//done
/* print
    * Purpose: To print the chars in the array list
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::print() {
         cout << "[CharArrayList of size " << numItems << " <<";
         for (int i=0; i<numItems; i++) {
            if(chars[i] != NULL) {
             cout << chars[i];
            }
         }
         cout << ">" << ">]" << endl;
    }

//done
/* pushAtBack
    * Purpose: Insert a char element at the end of the list
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::pushAtBack(char* c) {
        insertAt(c, numItems);
    }

//done
/* pushAtFront
    * Purpose: Insert a char element at the start of the list
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::pushAtFront(char* c) {
        insertAt(c, 0);
    }

//done
/* insertAt
    * Purpose: Insert a char element at the given index
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::insertAt(char* c, int index) {
        if(index > numItems) {
            ostringstream oerr;
            oerr << "index " << index << " not in range [0.." << numItems << ")";
            string err = oerr.str();
            throw range_error(err);
        } else {
            numItems++;
            if(capacity == numItems) {
                expand();
            }
            //!
            transfer = new char[numItems];
            for(int i = 0; i < numItems-1; i++) {
                if (i >= index) {
                    transfer[i+1] = chars[i];
                } else {
                    transfer[i] = chars[i];
                }
            }
            transfer[index] = c[0];
            delete [] chars;
            chars = transfer;
        }
    }

/* insertInOrder
    * Purpose: Insert a char element in the first alphabetically correct location
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::insertInOrder(char* c) {
        int finalIndex = 0;
        char *letter;
        letter = &c[0];
        for(int i = 0; i < numItems; i++) {
             if(c[0] < chars[i] || numItems == 0) {
                finalIndex = i;
             }
        }
        insertAt(letter, finalIndex);
    }

//done
/* popFromFront
    * Purpose: Removes the first char element
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::popFromFront() {
        if(isEmpty()) {
            throw runtime_error("cannot pop from empty ArrayList");
        }
        removeAt(0);
    }

//done
/* popFromBack
    * Purpose: Removes the last char element
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::popFromBack() {
        if(isEmpty()) {
            throw runtime_error("cannot pop from empty ArrayList");
        }
        removeAt(numItems--);
    }

//done
/* removeAt
    * Purpose: Removes a char element from the given index
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::removeAt(int index) {
        if(index > numItems) {
            ostringstream oerr;
            oerr << "index " << index << " not in range [0.." << numItems << ")";
            string err = oerr.str();
            throw range_error(err);
        } else {
            numItems--;
            chars[index] = NULL;
        }
        shift();
    }

//done
/* replaceAt
    * Purpose: Changes the char element at the given index
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::replaceAt(char* c, int index) {
        if(index > numItems) {
            ostringstream oerr;
            oerr << "index " << index << " not in range [0.." << numItems << ")";
            string err = oerr.str();
            throw range_error(err);
        } else {
            chars[index] = c[0];
        }
    }

//done
/* concatenate
    * Purpose: Copy a given char array list to the end of this instance
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::concatenate(CharArrayList &second) {
        int newSize = numItems + second.numItems;
        char *transfer = new char[newSize];
        for(int i = 0; i < numItems; i++) {
            transfer[i] = chars[i];
        }
        for(int i = numItems; i < newSize; i++) {
            transfer[i] = second.chars[i-numItems];
        }
        delete [] chars;
        chars = transfer;
        capacity = newSize;
        numItems = newSize;
        expand();
    }

//done
/* shrink
    * Purpose: Reduces the memory allocated to the char array list to only
    * the space needed for the current number of elements
    * Parameters: none
    * Returns: nothing
    */
    void CharArrayList::shrink() {
        char *transfer = new char[numItems];
        for(int i = 0; i < numItems; i++) {
            transfer[i] = chars[i];
        }
        delete [] chars;
        chars = transfer;
        capacity = numItems;
    }

//done
/* expand
    * Purpose: Expand the  capacity of the  array to twice as large plus two
        * Parameters: none
        * Returns: nothing
        */
    void CharArrayList::expand()
    {
        int newSize = (capacity*2) + 2;
        char *transfer = new char[newSize];
        for(int i = 0; i < numItems; i++) {
            transfer[i] = chars[i];
        }
        delete [] chars;
        chars = transfer;
        capacity = newSize;
    }

//done
/* shift
    * Purpose: Find any gaps in the list and shift things to be ordered
        * Parameters: none
        * Returns: nothing
        */
    void CharArrayList::shift() {
        for (int i = 1; i <= numItems; i++) {
            if (chars[i - 1] == NULL) {
                chars[i - 1] = chars[i];
                chars[i] = NULL;
            }
        }
    }

