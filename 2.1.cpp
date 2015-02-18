#include <iostream>
#include <cstdlib>
using namespace std;

#include "2.1.h"

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

void LinkedList::deleteDuplicateWithBuffer(){
	Node *tmp = head;
	HashMap *lookup_table = new HashMap();
	bool isThereDuplicate = false;//check if there was ever any duplicate in the list
	if(tmp == NULL){
		cout << "Linked List is empty" << endl;
		return;
	}
	while(tmp != NULL){
		lookup_table->insert(tmp->data, true);
		if(tmp->next == NULL){
			break;
		} else if(lookup_table->get(tmp->next->data)){
			Node *copy_next = tmp->next;
			tmp->next = copy_next->next;
			isThereDuplicate = true;
			continue;
		} else {
			tmp = tmp->next;
		}
	}
	if(!isThereDuplicate){
		cout << "there is no duplicate in the list" << endl;
	}
}

/********************************************************
FOLLOW UP 
********************************************************/
bool LinkedList::checkDuplicateWithoutBuffer(int data, int count){
	Node *tmp = head;
	for(int i=0; i<count; i++){
		if(tmp->data == data){
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

/********************************************************
FOLLOW UP 
********************************************************/
void LinkedList::deleteDuplicateWithoutBuffer(){
	Node *tmp = head;
	int count = 1;//count number of elements got checked so far
	bool isThereDuplicate = false;//check if there was ever any duplicate in the list
	if(tmp == NULL){
		cout << "Linked list is empty" << endl;
		return;
	}
	while(tmp != NULL){
		if(tmp->next == NULL){
			break;
		} else if(checkDuplicateWithoutBuffer(tmp->next->data, count)){
			Node *copy_next = tmp->next;
			tmp->next = copy_next->next;
			isThereDuplicate = true;
			continue;
		} else {
			tmp = tmp->next;
			count++;
		}
	}
	if(!isThereDuplicate){
		cout << "there is no duplicate in the list" << endl;
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

int main(){
	LinkedList linked_list;
	for(int i=11; i>0; i--){
		if(i == 5 || i == 8){
			linked_list.add(3);
			continue;
		}
		linked_list.add(i);
	}
	linked_list.display();
	linked_list.deleteDuplicateWithBuffer();
	//linked_list.deleteDuplicateWithoutBuffer();
	linked_list.display();

	return 0;
}