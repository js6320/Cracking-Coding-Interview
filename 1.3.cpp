#include <iostream>
#include <string>
#include <cctype> //to use tolower or islower
using namespace std;

//Assume character set is ASCII
bool checkPerm(string s1, string s2){
	int charsum1 = 0, charsum2 = 0;
	int s1_len = s1.length();
	int s2_len = s2.length();
	if(s1_len != s2_len){
		return false;
	} else{
		for(int i=0; i<s1_len; i++){
			charsum1 += s1[i];
			charsum2 += s2[i];
		}
		if(charsum1 == charsum2){
			return true;
		} else {
			return false;
		}
	}
}

//when uppercase and lowercase character don't matter
bool checkPermwo(string s1, string s2){
	int charsum1 = 0, charsum2 = 0;
	int s1_len = s1.length();
	int s2_len = s2.length();
	if(s1_len != s2_len){
		return false;
	} else{
		for(int i=0; i<s1_len; i++){
			charsum1 += tolower(s1[i]);
			charsum2 += tolower(s2[i]);
		}
		if(charsum1 == charsum2){
			return true;
		} else {
			return false;
		}
	}
}

int main(){
	cout << checkPerm("Car", "car") << endl;//print false(0)
	cout << checkPermwo("Car", "car")<< endl;//print true(1)
	return 0;
}