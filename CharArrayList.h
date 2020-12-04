/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.h
 *
 *  The CharArrayList class is a list with 0-based indexed chars
 *  which can be added, removed, found, and printed. The array list
 *  can be shrunk to the bare minimum needed for the elements.
 *
 *  Modified by: Sam Lacet-Brown
 *           on: 9/16/2020
 *
 */

#include <ostream>

#ifndef CHARARRAYLIST_H_
#define CHARARRAYLIST_H_

class CharArrayList {
    public:
        CharArrayList();
        CharArrayList(char *c);
        CharArrayList(char *c, int size);
         //copy constructor
        CharArrayList(const CharArrayList &other);
        //deconstructor
        ~CharArrayList();
        //assignment operator
        CharArrayList &operator=(const CharArrayList &other);

        bool isEmpty();
        void clear();
        int size();

        char* first();
        char* last();

        char* elementAt(int index);

        void print();
        
        void pushAtBack(char* c);
        void pushAtFront(char* c);
        
        void insertAt(char* c, int index);
        void insertInOrder(char*);
        
        void popFromFront();
        void popFromBack();
        
        void removeAt(int index);
        void replaceAt(char* c, int index);
        
        void concatenate(CharArrayList &second);
        void shrink();

    private:
        static const int START_SIZE = 5;
        int numItems;
        int capacity;
        int num = 0;
        char *chars = NULL;
        char *transfer = NULL;
        void expand();
        void checkSize();
        void shift();
};

#endif