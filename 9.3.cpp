#include <iostream>
using namespace std;

//return index where array[index] == index
int findMagicIndex(int array[], int start, int end){
	if(end < start){
		return -1;
	} else {
		int mid = (start+end)/2;
		if(array[mid] == mid){
			return mid;
		} else if(array[mid] > mid){
			return findMagicIndex(array, start, mid-1);
		} else {
			return findMagicIndex(array, mid+1, end);
		}
	}
}

int findMagicIndexNotDistinct(int array_not_distinct[], int start, int end){
	if(end < start){
		return -1;
	} else {
		int mid = (start+end)/2;
		if(mid == array_not_distinct[mid]){
			return mid;
		} 
		//search left side
		int left_magic_index = (mid-1 > array_not_distinct[mid])? array_not_distinct[mid]: mid-1;
		int left = findMagicIndexNotDistinct(array_not_distinct, start, left_magic_index);
		if(left >= 0){//need to give a chance to look at right side
			return left;
		}
		//search right side
		int right_magic_index = (mid+1 > array_not_distinct[mid])? mid+1: array_not_distinct[mid];
		int right = findMagicIndexNotDistinct(array_not_distinct, right_magic_index, end);
		return right;
	}
}

int main(){
	int array[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
	int array_not_distinct[] = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
	cout << findMagicIndex(array, 0, 10) << endl;//should print 7
	cout << findMagicIndexNotDistinct(array_not_distinct, 0, 10) << endl;

	return 0;
}