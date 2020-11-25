#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct element{
	int row;
	int col;
	int value;
};
vector<element> martrix1;
vector<element> unsort2;		//未排列的矩陣2 
vector<element> martrix2;
vector<element> result;

int main(){
	int row1, col1, row2, col2, temp = 0;
	cin >> row1;
	cin >> col1;
	
	for(int i = 0; i<row1; i++){			//第一個矩陣 正常讀入 
		for(int j = 0; j<col1; j++){
			cin >> temp;
			if(temp == 0){;}
			else{
				martrix1.push_back({i, j, temp});			//不是0則push
			}
		}
	}
	
	cin >> row2;
	cin >> col2;
	for(int i = 0; i<row2; i++){			//第二個矩陣 直接轉置 
		for(int j = 0; j<col2; j++){
			cin >> temp;
			if(temp == 0){;}
			else{
				unsort2.push_back({j, i, temp});			//不是0則push 轉置 
			}
		}
	}
	
	//=============================================================================//
	int start_point1[row1] = {0};		//紀錄每個row起始點 
	int start_point2[col2] = {0};
	int sum = 0;
	
	//設定每個col的起始點1 
	for(int i = 1; i<row1; i++){		//走訪起始點 
		for(int j = 0; j<martrix1.size(); j++){			//走訪矩陣 
			if(martrix1[j].row == i-1){
				sum ++;
			}
		} 
		start_point1[i] = sum;
	}
	
	//設定每個col的起始點2 
	sum = 0;
	for(int i = 1; i<col2; i++){		//走訪起始點 
		for(int j = 0; j<unsort2.size(); j++){			//走訪矩陣 
			if(unsort2[j].row == i-1){
				sum ++;
			}
		} 
		start_point2[i] = sum;
	}
	
	//創立空vector->複製start_point2->重新走訪並將第二個矩陣排列 
	for(int i=0; i<unsort2.size(); i++){
		martrix2.push_back({0, 0, 0});
	}
	int temp_point2[col2] = {0};
	for(int i=0; i<col2; i++){
		temp_point2[i] = start_point2[i];
	}
	int pos;
	for(int i=0; i<unsort2.size(); i++){			//排列第二個矩陣 
		pos = temp_point2[unsort2[i].row]++;
		martrix2[pos] = unsort2[i]; 
	}
	
	//開始相乘 
	int total=0;		//用來記錄加乘後每項結果 
	int pos1, pos2;
	int next1, next2;		//預防找不到最後一個起始點的值 (out of array range) 
	for(int i = 0; i<row1; i++){			//紀錄矩陣一列數起始點走訪 
		for(int j = 0; j<col2; j++){			//紀錄矩陣二列數起始點走訪 
			i == row1-1 ? next1 = martrix1.size() : next1 = start_point1[i+1];
			for(int a = 0; a < next1-start_point1[i]; a++){	//陣列一第a個起始點開始走訪 
				j == col2-1 ? next2 = martrix2.size() : next2 = start_point2[j+1];
				for(int b = 0; b < next2-start_point2[j]; b++){	//陣列二第b個起始點開始走訪
					pos1 = start_point1[i]+a;		//陣列一現在所指元素 
					pos2 = start_point2[j]+b;		//陣列二現在所指元素 
					if(martrix1[pos1].col == martrix2[pos2].col){
						total += martrix1[pos1].value * martrix2[pos2].value;
					}
				}
			}
			if(total != 0){
				result.push_back({i, j, total});
				total = 0;
			}
		}
	}
	
	for(int i = 0; i<result.size(); i++){
		cout << result[i].row << " " << result[i].col << " " << result[i].value << endl;
	}
	
	return 0;
}
