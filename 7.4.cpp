#include <iostream>
using namespace std;

int negation(int n){
	int answer = 0;
	int pos_or_neg = (n>0)? -1: 1;
	while(n!=0){
		n += pos_or_neg;
		answer += pos_or_neg;
	}
	return answer;
}

int absolute(int n){
	if(n<0){
		return negation(n);
	}
	return n;
}

int N2SubtracttoN1(int n1, int n2){
	return n1 + negation(n2);
}

int N1MultiplyByN2(int n1, int n2){
	if(n2>n1){//it's faster in this way
		return N1MultiplyByN2(n2, n1);
	}
	int answer = 0;
	int absolute_n1 = absolute(n1);
	int absolute_n2 = absolute(n2);
	for(int i=0; i<absolute_n2; i++){
		answer += absolute_n1;
	}
	if((n1>0&&n2>0)||(n1<0&&n2<0)){
		return answer;
	}
	return negation(answer);
}

int N1DividedByN2(int n1, int n2){
	if(n2 == 0){
		cout << "n2 can't be zero" << endl;
		return -1;
	}
	int sum = 0, answer = 0;
	int absolute_n1 = absolute(n1);
	int absolute_n2 = absolute(n2);
	while(sum+absolute_n2 <= absolute_n1){
		sum += absolute_n2;
		answer++;
	}
	if((n1>0&&n2>0)||(n1<0&&n2<0)){
		return answer;
	} else {
		return negation(answer);
	}
}

int main(){
	cout << N2SubtracttoN1(8,1) << " ";
	cout << N2SubtracttoN1(-8,1) << " ";
	cout << N2SubtracttoN1(8,-1) << " ";
	cout << N2SubtracttoN1(-8,-1) << endl;
	cout << N1MultiplyByN2(6,3) << " ";
	cout << N1MultiplyByN2(-6,3) << " ";
	cout << N1MultiplyByN2(6,-3) << " ";
	cout << N1MultiplyByN2(-6,-3) << endl;
	cout << N1DividedByN2(4,0) << endl;//error checking
	cout << N1DividedByN2(5,2) << " ";
	cout << N1DividedByN2(-6,2) << " ";
	cout << N1DividedByN2(7,-2) << " ";
	cout << N1DividedByN2(-2,-3) << endl;

	return 0;
}