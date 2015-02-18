#include <iostream>
#include <vector>
using namespace std;

#include "11.7.h" //create an object(person) 

void merge(vector<Person*> &people, int low, int middle, int high) {
    vector<Person*> people_copy; //copy people arraylists to people_copy arraylists
    for(int i=0; i<=high; i++){
        people_copy.push_back(people[i]);
    }

    int weight_left = low;
    int weight_right = middle+1;
    int current = low;

    while(weight_left <= middle && weight_right <=high){//overwrite people in sorted order
        if(people_copy[weight_left]->weight <= people_copy[weight_right]->weight){
            people[current] = new Person(people_copy[weight_left]);
            weight_left++;
        } else {
            people[current] = new Person(people_copy[weight_right]);
            weight_right++;
        }
        current++;
    }

    int remaining = middle - weight_left;
    for(int j=0; j<=remaining; j++){
        people[current+j] = new Person(people_copy[weight_left+j]);
    }
}

void sort_weight(vector<Person*> *people, int low, int high) {
    if(low < high){
        int middle = (low+high)/2;
        sort_weight(people, low, middle);
        sort_weight(people, middle+1, high);
        merge(*people, low, middle, high);
    }
}

int get_index_of_max_length_less_than_height(int length[], int size, float *height){
    int longest = 1;
    int index = size+1;//set to current index
    for(int i=0; i<=size; i++){
        if((length[i]>=longest) && (height[i]<height[size+1])){
            longest = length[i];
            index = i;
        }
    }
    return index;
}

vector<Person*> longest_increasing_height(vector<Person*> people, int sort_start, int num_of_people){
    float *height = new float[num_of_people];//store people's height information
    int max_length[num_of_people];//stores the length of the maximum increasing subarray ending with each index
    int *index = new int[num_of_people];//index[i] points to the predecessor of person i in a longest increasing
                                        //subarray
    for(int i=sort_start; i<num_of_people; i++){//initialization
        height[i] = people[i]->height;
    }

    max_length[0] = 1; // number of largest subarray ending with index 0
    index[0] = 0; //first element of array is always the longest subarray ending with itself
    int max; //index where longest subarray is
    for(int j=sort_start+1; j<num_of_people; j++){
        max = get_index_of_max_length_less_than_height(max_length, j-1, height);
        index[j] = max;
        if(index[j] == j){
            max_length[j] = 1;
        } else {
            max_length[j] = max_length[max] + 1;
            max = j;
        }
    }
    
    int subarray_size = max_length[max];//length of longest increasing subarray
    int subarray_index_size = subarray_size;//store indexes of longest increasing subarray
    int *subarray_index = new int[subarray_index_size];
    while(max != index[max]) {
        subarray_index[--subarray_index_size] = max;
        max = index[max];
    }
    subarray_index[subarray_index_size-1] = max;
    max = index[max];

    vector<Person*> sorted_people;
    for(int i=0; i<subarray_size; i++){
        float sorted_weight = people[subarray_index[i]]->weight;
        float sorted_height = height[subarray_index[i]];
        sorted_people.push_back(Person::make_person(sorted_weight, sorted_height)); 
    }
    return sorted_people;
}

int main(){
	vector<Person*> people, sorted_people;
    people.push_back(Person::make_person(100.6, 54.3));
    people.push_back(Person::make_person(122.3, 57.1));
    people.push_back(Person::make_person(109.7, 55.9));
    people.push_back(Person::make_person(133.4, 66.6));
    people.push_back(Person::make_person(121.3, 60.8));
    people.push_back(Person::make_person(150.2, 68.4));
    people.push_back(Person::make_person(141.9, 62.2));
    people.push_back(Person::make_person(160.8, 59.8));
    people.push_back(Person::make_person(180.5, 75.7));

    int size = people.size();
	cout << "BEFORE: " << endl;
	for(int k=0; k<size; k++){
		people[k]->display();
	}
	cout << endl;

    sort_weight(&people, 0, size-1); //sort by weight first using merge sort
	sorted_people = longest_increasing_height(people, 0, size);//sort by height using longest increasing subarray

    int sorted_size = sorted_people.size();
    cout << "AFTER: " << endl;
	for(int k=0; k<sorted_size; k++){
		sorted_people[k]->display();
	}
	cout << endl;

    //clean up 
    for(int i=0; i<size; i++){
        if(i<sorted_size){
            delete sorted_people[i];
        }
        delete people[i];
    }

	return 0;
}