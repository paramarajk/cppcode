/*
The Iterator Design Pattern allows you abstract out the details of traversing collections. 
For example, you may different types of collections in your applications, such as an array, 
a linked list, or a generic dictionary. For whichever the types of collections you have, you will need to traverse,
or iterate through the items in the collections.  The actual implementation on how to traverse 
different types of collections will be different, yet the client code(calling code) should not be 
concerned about the details of the implementations. The iterator pattern helps you to hide 
such details and provide a generic interface for the client to traverse different types of collections.
*/

#include <iostream>
using namespace std;

template<typename T>
class IIterator {

};

template<typename T>
class Iaggrecate {
	virtual IIterator<T> create_Iterator() = 0;
	virtual 
};