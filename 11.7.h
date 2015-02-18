#include <iostream>
#include <vector>
using namespace std;

class Person {
  public:
    float weight;
    float height;
    Person(float weight, float height){ //constructor
        this->weight = weight;
        this->height = height;
    } 
    Person(const Person *obj){ //copy constructor
        this->weight = obj->weight;
        this->height = obj->height;
    } 
    static Person* make_person(float w, float h); //create new person
    void display(){ //display each person's weight and height
        cout << "(" << this->weight << "), (" << this->height << ")" << endl;
    }
};

Person* Person::make_person(float w, float h){
    return new Person(w, h);
}