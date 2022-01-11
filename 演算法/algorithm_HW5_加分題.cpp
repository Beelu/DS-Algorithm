#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main(){
	srand(time(NULL));
	//�Ы�adjacency matrix 
	int v, e;
	cin >> v >> e;
	int copy_edge_num[v+1][v+1] = {0};
	int a, b;
	for(int i=0; i<e; i++){
		cin >> a >> b;
		copy_edge_num[a][b] = 1;
		copy_edge_num[b][a] = 1;
	}
	
	
	int min = 10000;
	for(int k=0; k<50; k++){
		int edge_num[v+1][v+1] = {0};
		for(int i=0; i<=v; i++){
			for(int j=0; j<=v; j++)
				edge_num[i][j] = copy_edge_num[i][j];
		}
		
		int remain[v+1] = {0};		//�������Y���٦s�b���I
		int total_remain = v; 	//�����ٳѤU�X���I�A�ѤU����I�N���� 
		for(int i=1; i<=total_remain; i++){
			remain[i] = i;
		}
		
		while(total_remain > 2){
			//�гy���@�˪����random�Ʀr�b1~�ѤU�I���`�Ƥ����A�N�Ir2�֨�r1 
		  	int r2, r1 = rand()%total_remain+1;
		  	do{
		  		r2 = rand()%total_remain+1;	
			}while(r1 == r2);
			
			//�}�l�X�� 
			for(int i=1; i<=v; i++){
				if(i != remain[r1]){
					edge_num[remain[r1]][i] += edge_num[remain[r2]][i];
					edge_num[i][remain[r1]] += edge_num[i][remain[r2]];
				}
				edge_num[remain[r2]][i] = 0;
				edge_num[i][remain[r2]] = 0;
			}
			remain[r2] = remain[total_remain];		//r2�����A�ΰ}�C�̫�@�ӥh�ɡA�M��֤@���I 
			total_remain -= 1;
		}
		
		if(min > edge_num[remain[1]][remain[2]])
			min = edge_num[remain[1]][remain[2]];
	}
	
	cout << "����50��randomized min-cut�q���̧C�Ȭ��G" << min;
	return 0;
} 
