#include <iostream>
using namespace std;

int insertMintoN(int M, int N, int j, int i){
	int clear_right = (~0) << (j+1);//clearbit j through 0
	int clear_left = (1<<i) - 1;//clearbit MSB through i
	int clear_mask = clear_left | clear_right;
	//clearbit partial N for replacing to M
	int clear_N = clear_mask & N;//x&1=x, x&0=0
	return clear_N | (M<<i);
}

int main(){
	cout << insertMintoN(5, 36, 3, 1) << endl; //print 42(100100=>101010); 

	return 0;
}