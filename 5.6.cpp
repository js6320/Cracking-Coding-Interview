#include <iostream>
using namespace std;

int swapOddandEven(int num){
	//for 32bit integers
	int cleared_oddbit = num & 0xaaaaaaaa; 
	int cleared_evenbit = num & 0x55555555;
	return (cleared_evenbit<<1) | (cleared_oddbit>>1);//swap odd bit and even bit
}

int main(){
	cout << swapOddandEven(42) << endl;//print 21(101010=>010101)

	return 0;
}