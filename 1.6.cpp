#include <iostream>
using namespace std;

const int N = 5;

/*********************************************************
		Rotate to left by 90 degrees.
		Start rotation from inner layer.
*********************************************************/
void rotateMatrixBy90deg(int (*matrix)[N][N]){
	for(int layer=(N/2)-1; layer>=0; layer--){
		int start_rotate = layer;
		int end_rotate = N - 1 - layer;
		for(int ptr=start_rotate; ptr<end_rotate; ptr++){
			int offset = ptr - start_rotate;
			int top = (*matrix)[start_rotate][ptr];
			//right to top
			(*matrix)[start_rotate][ptr] = (*matrix)[ptr][end_rotate];
			//bottom to right
			(*matrix)[ptr][end_rotate] = (*matrix)[end_rotate][end_rotate-offset];
			//left to bottom
			(*matrix)[end_rotate][end_rotate-offset] = (*matrix)[end_rotate-offset][start_rotate];
			//top to left
			(*matrix)[end_rotate-offset][start_rotate] = top;
		} 
	}
}

int main(){
	int matrix[N][N];
	int (*ptr_matrix)[N][N] = &matrix;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matrix[i][j] = 10*i + j;
		}
	}
	rotateMatrixBy90deg(ptr_matrix);
	//display
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << matrix[i][j] << " ";
			if(matrix[i][j] < 10){
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}