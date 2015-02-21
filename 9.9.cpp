#include <iostream>
using namespace std;

const int CHESS_SIZE = 8;

bool checkValidation(int cols_for_each_row[], int cur_row, int cur_col){
	for(int prev_row=0; prev_row<cur_row; prev_row++){
		//when the current column is same as any of columns in previous row
		if(cur_col == cols_for_each_row[prev_row]){
			return false;
		}
		//when the current queen placement is in digonal to any of queens from previous
		int row_distance = cur_row - prev_row;
		int col_distance = (cur_col-cols_for_each_row[prev_row]);
		col_distance = (col_distance<0)? (-1)*col_distance: col_distance;
		if(col_distance == row_distance){
			return false;
		}
	}
	return true;
}

void place8Queens(int cols_for_each_row[], int row){
	static int num = 0;
	if(row == CHESS_SIZE){//display
		num++;
		cout << "CHESS " << num << " :" << endl;
		for(int i=0; i<CHESS_SIZE; i++){
			for(int j=0; j<CHESS_SIZE; j++){
				if(cols_for_each_row[i] == j){
					cout << " x ";
				} else {
					cout << " o ";
				}
			}
			cout << endl;
		}
		cout << endl << endl;
		return;//done with making a way to arrange
	} else {
		for(int col=0; col<CHESS_SIZE; col++){
			if(checkValidation(cols_for_each_row, row, col)){
				cols_for_each_row[row] = col;
				place8Queens(cols_for_each_row, row+1);
			}
		}
	}
}

int main(){
	int cols_for_each_row[CHESS_SIZE];
	place8Queens(cols_for_each_row, 0);

	return 0;
}