#include <iostream>
using namespace std;

int main(){
	int times;
	cin >> times;
	int vertex, weightNum, total=0;		//���I�A��ơA�`�Z�� 
	
	for(int k=0; k<times; k++){
		cin >> vertex;
		cin >> weightNum;
		int adjanceny[vertex][vertex] = {0};
		for(int i=0; i<vertex; i++){		//��l�� 
			for(int j=0; j<vertex; j++){
				adjanceny[i][j] = 1000;
			}
		}
		
		int from, to, distance;		
		for(int i=0; i<weightNum; i++){		//��l�إ߶Z�����}�C 
			cin >> from;
			cin >> to;
			cin >> distance;
			
			adjanceny[from][to] = distance;
			adjanceny[to][from] = distance;
		}
		
		int arrived[vertex] = {0};		//�ΨӰO�����I�O�_�w�Q��F
		int start = 0;		//�_�I�A���q0���I�X�o
		arrived[0] = 1;
		int min = 1000;
		for(int h=0; h<vertex-1; h++){		//�إ�n-1������tree�N�إߧ����A�H�U�}�l���X�}�C 
			for(int i=0; i<vertex; i++){		//from 
				for(int j=0; j<vertex; j++){		//to
					if(arrived[i] == 1 && arrived[j] == 0){		//�q�w��F�쥼�Q��F�~�i�s�u 
						if(min > adjanceny[i][j]){
							min = adjanceny[i][j];
							from = i;		//from�ΨӰO���q�����I���~�s 
							to = j;		//to�ΨӰO�������I�N�Q�s�u 
						}
					}
				}
			}
			arrived[to] = 1;
			total += adjanceny[from][to];
			min = 1000;
		} 
		
		cout << total << endl;
		total = 0;
	}
	
	return 0;
} 
