#include <iostream>
#include <cstdlib>
using namespace std;

#include "2.2.h"

Node* LinkedList::create(int data){
	Node *node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

void LinkedList::add(int data){
	Node *node = create(data);
	if(head == NULL){
		head = node;
	} else {
		Node *tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}

void LinkedList::display(){
	Node *tmp = head;
	if(tmp == NULL){ 
		cout << "There is no element in linked list";
	}
	while(tmp != NULL){
		cout << tmp->data; 
		if(tmp->next != NULL) cout << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

int LinkedList::kToLastElement(int k){
	Node *pointer1 = head;
	Node *pointer2 = head;//make 2 pointers k positions apart
	//move pointer2 for kth positions
	for(int p2_position = 1; p2_position<k; p2_position++){
		pointer2 = pointer2->next;
	}

	while(pointer2->next != NULL){
		pointer1 = pointer1->next;
		pointer2 = pointer2->next;
	}
	return pointer1->data;
}

int main(){
	LinkedList singly_linked_list;
	for(int i=3; i<20; i++){
		singly_linked_list.add(i);
	}
	singly_linked_list.display();//for debugging
	cout << singly_linked_list.kToLastElement(5) << endl;
	
	return 0;
}