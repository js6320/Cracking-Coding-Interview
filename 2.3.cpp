#include <iostream>
#include <cstdlib>
using namespace std;

#include "2.3.h"

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

void LinkedList::deleteGivenNode(Node *deleted_node){
	if(deleted_node == NULL || deleted_node->next == NULL){
		cout << "It can't be deleted this way" << endl;
	} else {
		Node *next_to_deleted_node_copy = deleted_node->next;
		deleted_node->data = next_to_deleted_node_copy->data;
		deleted_node->next = next_to_deleted_node_copy->next;
	}
}

void LinkedList::Delete(int position){
	Node *tmp = head;
	while(position != 1){
		tmp = tmp->next;
		position--;
	}
	deleteGivenNode(tmp);
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

int main(){
	LinkedList linked_list;
	for(int i=3; i<11; i++){
		linked_list.add(i);
	}
	linked_list.display();
	linked_list.Delete(6);//delete 6th element
	linked_list.display();

	return 0;
}