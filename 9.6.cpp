#include <iostream>
using namespace std;

void findParentheses(int left_paren_num, int right_paren_num, char each_pattern[], int count){
	//no more left paren to use left OR #right parens left to use >= #left parens left to use(always!)
    if(left_paren_num < 0 || right_paren_num < left_paren_num){
    	return;
    }
    //Neither left nor right parentheses left to use
    if(left_paren_num == 0 && right_paren_num == 0){
        for(int i=0; i<count; i++){
            cout << each_pattern[i];
        }
        cout<<" | ";
    } else {
    	if(left_paren_num > 0){
            each_pattern[count] = '(';
            findParentheses(left_paren_num-1, right_paren_num, each_pattern, count+1);
        }
    	if(right_paren_num > left_paren_num){
            each_pattern[count] = ')';
            findParentheses(left_paren_num, right_paren_num-1, each_pattern, count+1);
        }
    }
}
int main(){
    int number_of_parentheses = 4;
    char each_pattern[2*number_of_parentheses];//there are a pair of parentheses
    findParentheses(number_of_parentheses, number_of_parentheses, each_pattern, 0);
    cout << endl;

    return 0;
}