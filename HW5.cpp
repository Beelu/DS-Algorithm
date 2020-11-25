#include <iostream>
#include <string>
using namespace std;

int main(){
	struct node{
		int value;
		node* next;
	};
	node* front = new node{0, NULL};		//��@�_�l�I 
	node* rear = NULL;
	int size = 0;
	
	string s;
	int temp1;
	int temp2;
	node* pos; 
	node* before;		//�H�U�Ψ�reverse 
	node* middle;
	node* after;
	while(cin >> s){
		if(s == "ADD"){					//=====================�W�[============================= 
			cin >> temp1;
			node* newnode = new node{temp1, NULL};
			pos = front;
			while(pos->next){
				pos = pos->next;
			}
			pos->next = newnode;
			rear = newnode;
			size += 1;
			
			pos = front->next;			//�L�X 
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}else if(s == "INSERT"){		//======================���J==========================	
			cin >> temp1;		//�Ĥ@�ӼƦr �n���J���� 
			cin >> s;		//�o�Ӥ��n(BEHIND�r��)
			cin >> temp2;		//�ĤG�ӼƦr ���b��
			
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
			
			pos = front->next;			//�L�X
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}else if(s == "DELETE"){		//==========================�R��====================== 
			cin >> temp1;
			if(temp1 > size || temp1 < 1){
				cout << "Index is out of range!!" << endl;
			}else{
				pos = front;
				for(int i = 1; i<temp1; i++){
					pos = pos->next;
				}
				node* del = pos->next;		//�ΨӼȮɬ����n�R����node
				pos->next = pos->next->next;
				delete del;
				size -= 1;
			}
			
			if(size == 0){
				cout << endl;
			}else{
				pos = front->next;			//�L�X
				while(pos->next){
					cout << pos->value << " ";
					pos = pos->next;
				}
				cout << pos->value << endl;
			}
		}else if(s == "REVERSE"){		//===========================����======================== 
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
			
			pos = front->next;			//�L�X
			while(pos->next){
				cout << pos->value << " ";
				pos = pos->next;
			}
			cout << pos->value << endl;
		}
		
//		if (cin.get() == '\n'){		//Ū�쩳�N���X 
//			break;
//		}
	}
	
	return 0;
} 
