#include <iostream>
using namespace std;

const int row = 8;
const int column = 6;

void setToZero(int (*matrix)[row][column]){
	bool r[row], c[column];//store which row and column should set to be zero
	for(int i=0; i<row; i++){//initialize to false
		r[i] = false;
	}
	for(int j=0; j<column; j++){
		c[j] = false;
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			if((*matrix)[i][j] == 0){
				r[i] = true;
				c[j] = true;
			}
		}
	}
	for(int k=0; k<row; k++){
		for(int h=0; h<column; h++){
			if(r[k] || c[h]){
				(*matrix)[k][h] = 0;
			}
		}
	}
}

int main(){
	//create matrix
	int matrix[row][column];
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			matrix[i][j] = i+j;
			if(matrix[i][j] == 9){
				matrix[i][j] = 0;
			}
		}
	}

	//test output
	cout << "BEFORE: " << endl;
	for(int k=0; k<row; k++){
		for(int h=0; h<column; h++){
			cout << matrix[k][h] << "  ";
		}
		cout << endl;
	}
	//set row and column to zero when the value is zero
	setToZero(&matrix);

	//test output
	cout << "AFTER: " << endl;
	for(int k=0; k<row; k++){
		for(int h=0; h<column; h++){
			cout << matrix[k][h] << "  ";
		}
		cout << endl;
	}

	return 0;
}