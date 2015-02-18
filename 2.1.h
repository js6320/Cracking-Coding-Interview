#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 20;

struct Node {
	int data;
	Node *next;
}*head;

class LinkedList {
  public:
  	LinkedList(){//constructor
  		head = NULL;
  	}
  	Node* create(int data);//create a node
  	void add(int data);//add new element in the list
  	void deleteDuplicateWithBuffer();//delete any duplicate in linked list using buffer
  	bool checkDuplicateWithoutBuffer(int data, int count);//check if there is duplicate in the list
  	void deleteDuplicateWithoutBuffer();//delete any duplicate without using buffer in linked list
  	void display();
};

class HashEntry {
	int key;
	bool value;
  public:
  	HashEntry(int key, bool value){
  		this->key = key;
  		this->value = value;
  	}
  	int getKey(){
  		return this->key;
  	}
  	bool getValue(){
  		return this->value;
  	}
};

class HashMap {
	HashEntry **table;
  public: 
  	HashMap(){
  		table = new HashEntry*[SIZE];
  		for(int i=0; i<SIZE; i++){
  			table[i] = new HashEntry(i, false);
  		}
  	}
  	HashMap(const HashMap &obj){//copy constructor
  		cout << "this is copy" << endl;
  		table = new HashEntry*[SIZE];
  		table = obj.table;
  	}//simplify hash function for just focusing on problem about linked list
	bool get(int key){
		int hash = key;
		return table[hash]->getValue();
	}
	// insert value into hash table using hash map
	void insert(int key, bool value){
		int hash = key;
		table[hash] = new HashEntry(hash, value);
	}
    ~HashMap(){
		for(int i=0; i<SIZE; i++){
			if(table[i]!=false) {
				delete table[i];
			}
		}
		delete[] table;
	}
};