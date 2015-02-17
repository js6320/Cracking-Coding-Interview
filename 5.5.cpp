#include <iostream>
using namespace std;


int countCoversion(int num1, int num2){
	int count = 0;
	//brute force way 
	/*for(int _xor = num1^num2; _xor!=0; _xor = _xor >> 1){
		count += _xor & 1;
	}*/

	//better way
	for(int _xor = num1^num2; _xor!=0; _xor = _xor & (_xor-1)){
		count++;
	}
	return count;
}

int main() {
	cout << countCoversion(31, 14) << endl;//011111 => 001110, so answer is 2
	
	return 0;
}