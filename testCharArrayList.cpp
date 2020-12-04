/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  testCharArrayList.cpp
 *
 *  PURPOSE
 *
 *  Written by: Sam Lacet-Brown
 *          on: 9/17/2020
 */

#include <iostream>
#include "CharArrayList.h"
using namespace std;

int main()
{
    CharArrayList test;
    cout << "Created empty list test" << endl;
    cout << "Empty?: " << test.isEmpty() <<endl; //1
    char testing[] = "tests lettersx";
    test.insertAt(&testing[1], 0);
    cout << "Inserted 'e'" << endl;
    test.print(); //e
    cout << "Empty?: " << test.isEmpty() <<endl; //0
    test.concatenate(test);
    cout << "Concatenated test with test" << endl;
    test.print(); //ee
    cout << "Size: " << test.size() <<endl; //2
    test.replaceAt(&testing[2], 1);
    cout << "Replaced 1st index with 's'" << endl;
    test.print(); //es
    test.removeAt(0);
    cout << "Removed 0th index" << endl;
    test.print(); //s
    test.clear();
    cout << "Empty?: " << test.isEmpty() <<endl; //1
    test.pushAtFront(&testing[0]);
    cout << "Inserted 't' at the  start" << endl;
    test.print(); // t

    cout << endl;
    CharArrayList test2(testing, 14);
    cout << "Created list test2 from the 14 elements 'tests lettersx'" << endl;
    test2.insertAt(&testing[2], 6);
    test2.insertAt(&testing[2], 6);
    test2.insertAt(&testing[2], 6);
    cout << "Inserted three 's' elements at the 6th index" << endl;
    test2.print(); //tests sssletters.
    cout << "First: " << test2.first() << endl; //t
    cout << "Last: " << test2.last() << endl; //x
    test2 = test;
    cout << "Set test2 equal to test" << endl;
    test2.print(); //t

    test2.pushAtBack(&testing[7]);
    cout << "Added 'e' to the back" << endl;
    test2.popFromFront();
    cout << "Removed 0th element" << endl;
    test2.print(); //e
    CharArrayList test3(test2);
    cout << endl;
    cout << "Created copy of test2 as test3" << endl;
    test3.print(); //e

    cout << endl;
    CharArrayList test4(&testing[3]);
    cout << "Created list test4 from 't'" << endl;
    test4.concatenate(test2);
    cout << "Concatenated test4 with test2" << endl;
    //test4.replaceAt(&testing[6], 3);
    //throws "index 3 not in range [0..2)"
    test4.print(); //te
    test4.insertInOrder(&testing[1]);
    cout << "Inserted 'e' at first alphabetical index" << endl;
    test4.print(); //ete
    cout << "Element[0]: " << test4.elementAt(0) << endl; //e
    return 0;
}

