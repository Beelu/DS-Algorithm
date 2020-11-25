#include <iostream>
#include <string>
using namespace std;

int main(){
	struct node{
		int value;
		node* next;
	};
	node* front = new node{0, NULL};		//當作起始點 
	node* rear = NULL;
	int size = 0;
	
	string s;
	int temp1;
	int temp2;
	node* pos; 
	node* before;		//以下用來reverse 
	node* middle;
	node* after;
	while(cin >> s){
		if(s == "ADD"){					//=====================增加============================= 
			cin >> temp1;
			node* newnode = new node{temp1, NULL};
			pos = front;
			while(pos->next){
				pos = pos->next;
			}
			pos->next = newnode;
			rear = newnode;
			size += 1;
			
			pos = front->next;			//印出 
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}else if(s == "INSERT"){		//======================插入==========================	
			cin >> temp1;		//第一個數字 要插入的值 
			cin >> s;		//這個不要(BEHIND字串)
			cin >> temp2;		//第二個數字 插在哪
			
			if(temp2 > size || temp2 < 0){
				cout << "Index is out of range!!" << endl;
			}else{
				node* newnode = new node{temp1, NULL};
				pos = front;
				for(int i = 0; i<temp2; i++){
					pos = pos->next;
				}
				newnode->next = pos->next;
				pos->next = newnode;
				size += 1;
			}
			
			pos = front->next;			//印出
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}else if(s == "DELETE"){		//==========================刪除====================== 
			cin >> temp1;
			if(temp1 > size || temp1 < 1){
				cout << "Index is out of range!!" << endl;
			}else{
				pos = front;
				for(int i = 1; i<temp1; i++){
					pos = pos->next;
				}
				node* del = pos->next;		//用來暫時紀錄要刪除的node
				pos->next = pos->next->next;
				delete del;
				size -= 1;
			}
			
			if(size == 0){
				cout << endl;
			}else{
				pos = front->next;			//印出
				while(pos->next){
					cout << pos->value << " ";
					pos = pos->next;
				}
				cout << pos->value << endl;
			}
		}else if(s == "REVERSE"){		//===========================倒轉======================== 
			if(size > 1){
				before = front->next;
				middle = before->next;
				after = middle->next;
				before->next = NULL;
				
				while(after){
					middle->next = before;
					before = middle;
					middle = after;
					after = after->next;
				}
				middle->next = before;
				front->next = middle;
			}
			
			pos = front->next;			//印出
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}
		
//		if (cin.get() == '\n'){		//讀到底就跳出 
//			break;
//		}
	}
	
	return 0;
} 
