#include <iostream>
using namespace std;

//each node which includes data
struct Node {
	int data;
	Node *next;	
};

class Stack {
	Node *head;
 public:
 	//constructor 
 	Stack () {
		head = 0;
	} 
	//destructor
	~Stack () {
		delete head;
	}
	//create a node with data
 	Node* create_node(int data){
 		Node *node = new Node;
 		node->data = data;
 		node->next = 0; //null
 		return node;
 	}
 	//Function that inserts elements into the stack
    void push(int data){
        Node *node = create_node(data);
        if(isEmpty()){ 
            head = node;
        } else {
            Node *tmp = head;
            head = node;
            head->next = tmp;
        }
    }
    //Function to test whether the stack is empty     
	bool isEmpty(){
		return (head == 0);
	}
	//Returns top element of stack     
  	int peek(){
  		if(isEmpty()){
  			cout << "There is no item in stack" << endl;
  			return -1;
  		} else {
    		return head->data;
        }
  	}
  	//Removes element at the top of the stack          
  	int pop(){
  		int item;
  		if(isEmpty()){
  			cout << "Stack is empty" << endl;
  			return -1;
  		} else if (head->next == 0) {
  			item = head->data;
            head = 0;
        } else {
        	item = head->data;
            head = head->next;
        }
        return item;
  	}  
};

class MyQueue {
	Stack *newstack, *oldstack;
  public: 
  	MyQueue(){//create two stack to use as a queue
  		newstack = new Stack;
  		oldstack = new Stack;
  	}
  	~MyQueue(){
  		delete newstack;
  		delete oldstack;
  	}
  	void shiftstacks(){
  		if(oldstack->isEmpty()){
  			while(!newstack->isEmpty()){
  				oldstack->push(newstack->pop());
  			}
  		}
  	}
  	void enqueue(int data){
  		newstack->push(data);
  	}
  	int dequeue(){
  		shiftstacks();
  		return oldstack->pop();
  	}
  	int peek(){
  		shiftstacks();
  		return oldstack->peek();
  	}

};

int main(){
	MyQueue *q = new MyQueue;
	q->enqueue(5);
	q->enqueue(7);
	q->enqueue(8);
	cout << q->peek();
	cout << q->dequeue() << endl;
	cout << q->peek();
	cout << q->dequeue() << endl;
	q->enqueue(9);
	q->enqueue(10);
	cout << q->peek();
	cout << q->dequeue() << endl;
	cout << q->peek();
	cout << q->dequeue() << endl;
	cout << q->peek();
	cout << q->dequeue() << endl;
	cout << q->peek();//should generate error
	cout << q->dequeue() << endl;//should generate error
	
	return 0;
}