#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class LinkedList {
	Node *head;
  public: 
	LinkedList(){//constructor
		head = NULL;
	}
	Node* create(int data);//create a node
	void add(int data);//add an element in the list
	int kToLastElement(int k);
	void display();
};