//============================================================================
// Name        : GenericAlgorithmExample.cpp
// Author      : Adam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//common function implement
const int*
find1(const int* array, int n, int x)
{
	const int* p = array;

	for(int i = 0; i < n; ++i) {

		if(*p == x)
			return p;

		++p;
	}

	return NULL;
}

//generic(template) function implement
template<class T>
T* find1(T* array, int n, const T& x)
{
	T* p = array;

	for(int i = 0; i < n; ++i) {

		if(*p == x)
			return p;

		++p;
	}

	return NULL;
}

template<class T>
T* find3(T* array, T* beyond, const T& x)
{
	T* p = array;

	while(p != beyond) {

		if(*p == x) {
			return p;
		}

		++p;
	}

	return NULL;
}

template<class T>
T* find4(T* array, T* beyond, const T& x)
{
	T* p = array;

	while(p != beyond) {

		if(*p == x) {
			return p;
		}

		++p;
	}

	return beyond;
}

template<class T>
T* find5(T* array, T* beyond, const T& x)
{
	T* p = array;

	while(p != beyond && *p != x ) {
		++p;
	}

	return p;
}

template<class P, class T>
P find6(P start, P beyond, const T& x)
{
	while(start != beyond && *start != x) {
		++start;
	}

	return start;
}

struct Node {
	string value;
	Node* next;
};

class Nodep {
public:
	Nodep(Node* p):pt(p) {}
	string& operator*() {return pt->value;}
	void operator++() {pt = pt->next;}
	friend int operator==(const Nodep&, const Nodep&);
	friend int operator!=(const Nodep&, const Nodep&);
	operator Node*() {return pt;}

private:
	Node* pt;
};

int operator==(const Nodep& p, const Nodep& q)
{
	return p.pt == q.pt;
}

int operator!=(const Nodep& p, const Nodep& q)
{
	return p.pt != q.pt;
}

//common function implement
Node* listfind(Node* p, const string& x)
{
	return find6(Nodep(p), Nodep(0), x);

//	while(p && p->value != x)
//		p = p->next;
//
//	return p;
}


template<class In, class Out>
Out Custcopy(In start, In end, Out dest)
{
	while(start != end ) {
		*dest++ = *start++;
	}

	return dest;
}



int main() {

	char* hello = const_cast<char *>("Hello ");
	char* world = const_cast<char *>("World");
	char message[15] = {0};
	char* p = message;

	p = Custcopy(hello, hello+6, p);
	p = Custcopy(world, world+5, p);

	*p = '\0';

	cout << message << endl;

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
