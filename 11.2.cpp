#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

const int SIZE = 10;

//use two variables to remember right positions in string without spaces
string removeSpaceAndUppercase(string s){
	//remove spaces from a string and change all characters to lowercase
    int length = s.length();
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == ' '){
            continue;
        }
        s[j++] = tolower(s[i]);
    }
    s.resize(j);//resize string s to j characters after removing spaces
	return s;
}

bool checkS2GreaterThanS1(string s1, string s2){
	s1 = removeSpaceAndUppercase(s1);
	s2 = removeSpaceAndUppercase(s2);
	if(s1.length() <= s2.length()){
		return true;
	}
	return false;
}

void merge(string *arr, int low, int middle, int high) {
    string *helper = new string[high+1];
    //copy both halves into helper array
    for(int i=low; i<=high; i++){
        helper[i] = arr[i];
    }

    int helper_left = low;
    int helper_right = middle+1;
    int current = low;
    //compare values between two halves of array and sort them
    while(helper_left <= middle && helper_right <=high){
        if(checkS2GreaterThanS1(helper[helper_left], helper[helper_right])){
            arr[current] = helper[helper_left];
            helper_left++;
        } else {
            arr[current] = helper[helper_right];
            helper_right++;
        }
        current++;
    }

    //In case that there was larger values on the left half than values on the right half,
    //we need to finish copying values from helper array to original array.
    int remaining = middle - helper_left;
    for(int j=0; j<=remaining; j++){
        arr[current+j] = helper[helper_left+j];
    }
}

void sortArrayWithAnagramsNextToEachother(string *arr, int low, int high) {
    if(low < high){
        int middle = (low+high)/2;
        sortArrayWithAnagramsNextToEachother(arr, low, middle);//first half of arr
        sortArrayWithAnagramsNextToEachother(arr, middle+1, high);//second half of arr
        merge(arr, low, middle, high);//merging those halves to one
    }
}

int main(){
	string *array = new string[SIZE];
	array[0] = "mother in law";
	array[1] = "Dormitory";
	array[2] = "Punishment";
	array[3] = "The public art galleries";
	array[4] = "The Hurricanes";
	array[5] = "These churn air";
	array[6] = "Nine Thumps";
	array[7] = "Woman Hitler";
	array[8] = "Large picture halls I bet";
	array[9] = "Dirty room";

	//sort by length of strings
	//sortArrayWithAnagramsNextToEachother(array, 0, SIZE-1);
    cout << removeSpaceAndUppercase(array[8]) << endl;
/*
	for(int i=0; i<SIZE; i++){
		cout << array[i] << endl;
	}
*/
	return 0;
}