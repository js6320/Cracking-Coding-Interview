#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Stack {
	Node *head;
  public:
	Stack(){
		head = 0;
	}
	~Stack(){
		delete head;
	}
	Node* create(int data){
		Node *node = new Node;
		node->data = data;
		node->next = 0;
		return node;
	}
	bool isEmpty(){
		return (head == 0);
	}
	void push(int data){
		Node *node = create(data);
		if(isEmpty()){ 
            head = node;
        } else {
            Node *tmp = head;
            head = node;
            head->next = tmp;
        }
	}
	int pop(){
		if(isEmpty()){
			cout << "Stack is already Empty" << endl;
			return -1;
		}
		int data = head->data;
		if(head->next == 0){
			head = 0;
		} else {
			head = head->next;
		}
		return data;
	}
	int peek(){
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return -1;
		}
		return head->data;
	}
	void display(){
		Node *tmp = head;
		while(tmp != 0){
			cout << tmp->data;
			if(tmp->next != 0){
				cout << "->";
			}
			tmp = tmp->next; 
		}
		cout << endl;
	}
};
/***********************O(N^2)time & O(N)memory***************************/
void sort_stack(Stack &original){
	Stack buffer;
	while(!original.isEmpty()){
		int current_top = original.pop();
		while((buffer.isEmpty()!= 0) && (buffer.peek() > current_top)){
			original.push(buffer.pop());
		}
		buffer.push(current_top);
	}
	buffer.display();
}
/*************************************************************************/
int main(){
	Stack s;
	for(int i=10; i>=0; i--){
		s.push(i);
	}
	s.display();
	sort_stack(s);

	return 0;
}