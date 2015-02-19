#include <iostream>
using namespace std;

const int M = 6;//row size
const int N = 7;//column size

/**************************************************************************
NAIVE WAY
**************************************************************************/
int binary_search(int arr[][N], int low, int high, int each_row, int key) {
	int index;
	if (low > high){
		index = -1;
	} else {
		int mid = (low+high)/2;
		if (key == arr[each_row][mid]){
			index = mid;
		} else if (key < arr[each_row][mid]){
			index = binary_search(arr, low, mid-1, each_row, key);
		} else {
			index = binary_search(arr, mid+1, high, each_row, key);
		}
	}
	return index;
}

/**************************************************************************
MORE EFFICIENT WAY
**************************************************************************/
int search(int sorted_array[][N], int low, int column_length, int each_row, int key){
	int col = column_length-1;
	while(col >= low){
		if(sorted_array[each_row][col] == key){
			return col;
		} else if(sorted_array[each_row][col] > key){
			col--;
		} else {
			return -3;
		}
	}
}

int main(){
	int sorted_array[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			sorted_array[i][j] = 10*i + j;
		}
	}

    /*******************NAIVE WAY USING BINARY SEARCH FOR EACH ROW************************
	for(int k=0; k<M; k++){
		int result_index = binary_search(sorted_array, 0, N, k, 22);
		if(result_index>0){//should return (2, 2)
			cout << "22 is in sorted_array[" << k << "][" << result_index << "]" << endl;
		} 
	}
	**************************************O(M logN)***************************************/

	/*************************COMPARE VALUES USING SORTED ARRAY***************************/
	for(int k=0; k<M; k++){
		int result_index = search(sorted_array, 0, N, k, 34);
		if(result_index < 0){//should return (3, 4)
			continue;
		} else {
			cout << "34 is in sorted_array[" << k << "][" << result_index << "]" << endl;
		}
	}
	/***************************************O(M+N)****************************************/
	//for debugging
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(sorted_array[i][j] < 10){
				cout << sorted_array[i][j] << "  ";
				continue;
			}
			cout << sorted_array[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}