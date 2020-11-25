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
	priority['+'] = 1;			//�o�̥u�O���bstack���u���� �b�~�ɥ��A���B�~�P�_ ��L�ۦP 
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['('] = 0;
	cin >> input;

	int i=0;
	char c;
	int inside;			//�����u���ǼƦr�j�p 
	int outside;
	while(i < input.length()){
		c = input[i];
		if(c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')'){			//�Y�O�Ʀr 
			output += c; 
		}else{
			outside = priority[c];
			if(operators.size() != 0){			//�p�G���O�Ū��N�n��� 
				if(c == ')'){
					while(operators.top() != '('){				//���p1:�p�G�J��k�A�� pop����J�쥪�A�� 
						output += operators.top();
						operators.pop();
					}
					operators.pop();			//�⥪�A��pop�X�h ���ݭn 
				}else{
					inside = priority[operators.top()];
					if(outside > inside || c == '('){			//�Ъp2:�p�G�~������j�άO���A�� ����push 
						operators.push(c);
					}else{							//�p�G�̭�����j 
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
	
	while(!operators.empty()){				//��ѤU�����X 
		output += operators.top();
		operators.pop();
	}
	cout << output << endl;
	return 0;
}
