#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b, int lenA, int lenB);
int search(vector<int> &c, int goal, int len);

vector< vector<int> > DBSO;
vector<int> first;

int main(){
	DBSO.push_back(first);
	int input;
	cout << "輸入一組數列" << endl;
	while(cin >> input){
		//先搜尋 
		int row, col;
		
		for(int q = 0; q<DBSO.size(); q++){
			col = search(DBSO[q], input, DBSO[q].size());
			if(col >= 0){
				row = q;
				break;
			}
		}
		if(col >= 0){			//若有找到 
			cout << "****found****"<< endl;
			cout << input << ":[" << row << "][" << col << "]" << endl;
			cout << endl;
		}else{					//若找不到則insert 
			vector<int> newNum;
			newNum.push_back(input);
			
			int i = 0;
			if(DBSO[0].empty()){		//若第一層為空直接放 
				DBSO[0].push_back(newNum[0]);
			}else{
				if(!DBSO[DBSO.size() - 1].empty() && DBSO[DBSO.size() - 1][0] != 0){		//目前最底層有值，則先初始化下一層 
					vector<int> newLevel;
					DBSO.push_back(newLevel);
				}
				while(!DBSO[i].empty()){		//當層若為滿則合併並清空 
					newNum = merge(newNum, DBSO[i], newNum.size(), DBSO[i].size());
					DBSO[i].clear();
					i++;
				}
				int height = floor(log(newNum.size()) / log(2));		//高度，須放在哪層 
				for(int j =0; j < newNum.size(); j++){
					DBSO[height].push_back(newNum[j]);
				}
			}
			//print
			cout << "****not found, insert.****" << endl;
			for(int k = 0; k<DBSO.size(); k++){
				if(DBSO[k].empty()){
					if(DBSO.size()-1 == k){
						break;
					}else{
						for(int z = 0; z<pow(2, k); z++){
							cout << "0 ";
						}
						cout << endl;	
					}
				}else{
					for(int l = 0; l<DBSO[k].size(); l++){
						cout << DBSO[k][l] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
		}
	}
	
	return 0; 
}


//funciton
vector<int> merge(vector<int> &a, vector<int> &b, int lenA, int lenB){
	int ai=0;
	int bi=0;
	int ci=0;
	vector<int> c;
	while(ai<lenA && bi<lenB){
		if(a[ai] < b[bi]){
			c.push_back(a[ai++]);
		}else{
			c.push_back(b[bi++]);
		}
	}
	
	while(ai<lenA){
		c.push_back(a[ai++]);
	}
	while(bi<lenB){
		c.push_back(b[bi++]);
	}
	return c;
}


int search(vector<int> &c, int goal, int len){
	int left = 0;
	int right = len - 1;
	while(left <= right){
		int mid = (left+right) / 2;
		if(c[mid] == goal){
			return mid;
		}else if(c[mid] > goal){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return -1;
}
