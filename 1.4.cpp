#include <iostream>
using namespace std;

const int size = 21;

void convertSpace(char *string, int length){
	int front = -1;
	int end = length;
	for(int i=length; i>=0; i--){//find first space in the array
		if(string[i]!=' '){
			front = i;
			break;
		}
	}
	while(front >= 0){
		if(string[front] == ' '){
			string[end] = '0';
			string[end-1] = '2';
			string[end-2] = '%';
			end -= 3;
			front--;
		}
		string[end] = string[front];
		end--;
		front--;
	}
}

int main(){
	char test[size] = "S e orm P rk        ";

	//convert space to %20
	convertSpace(test, size-2);

	cout << "$$$$";
	for(int i=0; i<=size-2; i++){
		cout << test[i];
	}
	cout << "$$$$" << endl;

	return 0;
}