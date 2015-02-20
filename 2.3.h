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
  	void add(int data);//add new element in the list
  	void deleteGivenNode(Node *deleted_node);//delete a node only given access to that node
  	void Delete(int position);
  	void display();
};