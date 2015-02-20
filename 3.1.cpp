#include <iostream>
using namespace std;

const int STACK_SIZE = 10;
int *stack_array = new int[STACK_SIZE*3];
int stack_ptr[] = {-1, -1, -1};//points to where top of the stack element is

class Stack_in_Array {
  public:
  	void push(int stack_number, int data){
  		//check if stack is full
  		if(stack_ptr[stack_number] +1 >= STACK_SIZE){
  			cout << "Stack " << stack_number << " is full" << endl;
  			return;
  		}
  		stack_ptr[stack_number]++;
  		stack_array[current_stack_element_index(stack_number)] = data;
  	}
  	int pop(int stack_number){
  		//check if stack is already empty
  		if(stack_ptr[stack_number] == -1){
  			cout << "Stack " << stack_number << " is already empty" << endl;
  			return -1;
  		}
  		int data = stack_array[current_stack_element_index(stack_number)];
  		stack_array[current_stack_element_index(stack_number)] = 0;
  		stack_ptr[stack_number]--;
  		return data;
  	}
  	int peek(int stack_number){
  		int current_element_index = current_stack_element_index(stack_number);
  		return stack_array[current_element_index];
  	}
  	bool isEmpty(int stack_number){
  		return (stack_ptr[stack_number] == -1);
  	}
  	int current_stack_element_index(int stack_number){
  		return (stack_number*STACK_SIZE + stack_ptr[stack_number]);
  	}
  	void display(){
  		for(int i=0; i<(STACK_SIZE*3); i++){
  			cout << stack_array[i] << " ";
  		}
  		cout << endl;
  	}
};

/*************************************************************************
		Assume that we need same amount of memory for all stacks. 
		Stack number is started from 0
**************************************************************************/
int main(){
	Stack_in_Array stack;
	for(int i=0; i<3; i++){
		for(int j=0; j<10; j++){
			stack.push(i, j);
		}
	}
	//test general cases
	stack.display();
	stack.push(0, 3);//should print error "stack is full"
	stack.pop(0);//first stack
	cout << "Pop stack 1 :" << endl;
	stack.display();
	cout << "Top stack 1's element is : " << stack.peek(0) << endl;

	for(int j=0; j<10; j++){
		stack.pop(0);//should print error "stack is already empty"
	}	

	return 0;
}

