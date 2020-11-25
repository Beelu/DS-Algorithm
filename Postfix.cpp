#include <map>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string input;
	string output;
	map<char, int> priority;
	stack<char>  operators;
	priority['+'] = 1;			//這裡只記錄在stack的優先序 在外時左括號額外判斷 其他相同 
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['('] = 0;
	cin >> input;

	int i=0;
	char c;
	int inside;			//紀錄優先序數字大小 
	int outside;
	while(i < input.length()){
		c = input[i];
		if(c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')'){			//若是數字 
			output += c; 
		}else{
			outside = priority[c];
			if(operators.size() != 0){			//如果不是空的就要比較 
				if(c == ')'){
					while(operators.top() != '('){				//情況1:如果遇到右括號 pop直到遇到左括號 
						output += operators.top();
						operators.pop();
					}
					operators.pop();			//把左括號pop出去 不需要 
				}else{
					inside = priority[operators.top()];
					if(outside > inside || c == '('){			//請況2:如果外面比較大或是左括號 直接push 
						operators.push(c);
					}else{							//如果裡面比較大 
						while(outside <= inside){
							output += operators.top();
							operators.pop();
							if(operators.size() == 0){
								break;
							}
							inside = priority[operators.top()];
						}
						operators.push(c);
					}
				}
			}else{
				operators.push(c);
			}
		}
		i++;
	}
	
	while(!operators.empty()){				//把剩下都提出 
		output += operators.top();
		operators.pop();
	}
	cout << output << endl;
	return 0;
}
