//��¦�D
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	queue<char> operands;
	queue<string> operators;
	
	//�N�r������B�⤸��B��l 
	string s;
	string temp;
	int k=0;
	cin >> s;
	while(k<s.length()){
		while(s[k] != '+' && s[k] != '*' && k<s.length()){
			temp += s[k];
			k++;
		}
		if(temp.length() > 0){
			operators.push(temp);
			temp = "";
		}else{
			operands.push(s[k]);
			k++;
		}
	}
	
	//�[�A�� 
	string result;
	while(!operands.empty()){
	    if(operands.front() == '+'){
	    	result += "(";
	        result += operators.front();
	        result += operands.front();
	        operators.pop();
	        operands.pop();
	        while(operands.front() == '+'){
	        	result += operators.front();
		        result += operands.front();
		        operators.pop();
		        operands.pop();
	        }
	        result += operators.front();
	        operators.pop();
	        result += ")";
	    }else{
	    	result += operands.front();
	   		operands.pop();
	       	if(operands.front() == '*'){
	       		result += operators.front();
	        	operators.pop();
			}
		}
	}
	if(!operators.empty()){
		result += operators.front();
		operators.pop();
	}
	
	cout << result;
	
	
	return 0;
}
