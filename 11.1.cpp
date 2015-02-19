#include <iostream>
using namespace std;

const int SIZE_A = 20;
const int SIZE_B = 10;

void mergeBintoA(int *array_A, int array_B[], int A_length, int B_length){
	int strat_merging_index = A_length + B_length + 1;
	for(int i=strat_merging_index; i>=0; i--){
		if(array_A[A_length] >= array_B[B_length]){
			array_A[i] = array_A[A_length];
			A_length--;
		} else {
			array_A[i] = array_B[B_length];
			B_length--;
		}
	}
}

int main(){
	int array_B[SIZE_B];
	int *array_A = new int[SIZE_A]; 
	for(int i=0; i<SIZE_B; i++){//initialization
		array_A[i] = i+8;
		array_B[i] = i;
	}

	mergeBintoA(array_A, array_B, 9, 9);

	for(int i=0; i<SIZE_A; i++){
		cout << array_A[i] << " ";
	}
	cout << endl;
	for(int i=0; i<SIZE_B; i++){
		cout << array_B[i] << " ";
	}
	cout << endl;

	return 0;
}