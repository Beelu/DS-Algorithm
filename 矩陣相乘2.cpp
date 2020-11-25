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
vector<element> unsort2;		//���ƦC���x�}2 
vector<element> martrix2;
vector<element> result;

int main(){
	int row1, col1, row2, col2, temp = 0;
	cin >> row1;
	cin >> col1;
	
	for(int i = 0; i<row1; i++){			//�Ĥ@�ӯx�} ���`Ū�J 
		for(int j = 0; j<col1; j++){
			cin >> temp;
			if(temp == 0){;}
			else{
				martrix1.push_back({i, j, temp});			//���O0�hpush
			}
		}
	}
	
	cin >> row2;
	cin >> col2;
	for(int i = 0; i<row2; i++){			//�ĤG�ӯx�} ������m 
		for(int j = 0; j<col2; j++){
			cin >> temp;
			if(temp == 0){;}
			else{
				unsort2.push_back({j, i, temp});			//���O0�hpush ��m 
			}
		}
	}
	
	//=============================================================================//
	int start_point1[row1] = {0};		//�����C��row�_�l�I 
	int start_point2[col2] = {0};
	int sum = 0;
	
	//�]�w�C��col���_�l�I1 
	for(int i = 1; i<row1; i++){		//���X�_�l�I 
		for(int j = 0; j<martrix1.size(); j++){			//���X�x�} 
			if(martrix1[j].row == i-1){
				sum ++;
			}
		} 
		start_point1[i] = sum;
	}
	
	//�]�w�C��col���_�l�I2 
	sum = 0;
	for(int i = 1; i<col2; i++){		//���X�_�l�I 
		for(int j = 0; j<unsort2.size(); j++){			//���X�x�} 
			if(unsort2[j].row == i-1){
				sum ++;
			}
		} 
		start_point2[i] = sum;
	}
	
	//�Хߪ�vector->�ƻsstart_point2->���s���X�ñN�ĤG�ӯx�}�ƦC 
	for(int i=0; i<unsort2.size(); i++){
		martrix2.push_back({0, 0, 0});
	}
	int temp_point2[col2] = {0};
	for(int i=0; i<col2; i++){
		temp_point2[i] = start_point2[i];
	}
	int pos;
	for(int i=0; i<unsort2.size(); i++){			//�ƦC�ĤG�ӯx�} 
		pos = temp_point2[unsort2[i].row]++;
		martrix2[pos] = unsort2[i]; 
	}
	
	//�}�l�ۭ� 
	int total=0;		//�ΨӰO���[����C�����G 
	int pos1, pos2;
	int next1, next2;		//�w���䤣��̫�@�Ӱ_�l�I���� (out of array range) 
	for(int i = 0; i<row1; i++){			//�����x�}�@�C�ư_�l�I���X 
		for(int j = 0; j<col2; j++){			//�����x�}�G�C�ư_�l�I���X 
			i == row1-1 ? next1 = martrix1.size() : next1 = start_point1[i+1];
			for(int a = 0; a < next1-start_point1[i]; a++){	//�}�C�@��a�Ӱ_�l�I�}�l���X 
				j == col2-1 ? next2 = martrix2.size() : next2 = start_point2[j+1];
				for(int b = 0; b < next2-start_point2[j]; b++){	//�}�C�G��b�Ӱ_�l�I�}�l���X
					pos1 = start_point1[i]+a;		//�}�C�@�{�b�ҫ����� 
					pos2 = start_point2[j]+b;		//�}�C�G�{�b�ҫ����� 
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
