#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main(){
	srand(time(NULL));
	//創建adjacency matrix 
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
		
		int remain[v+1] = {0};		//紀錄收縮後還存在的點
		int total_remain = v; 	//紀錄還剩下幾個點，剩下兩個點就結束 
		for(int i=1; i<=total_remain; i++){
			remain[i] = i;
		}
		
		while(total_remain > 2){
			//創造不一樣的兩個random數字在1~剩下點的總數之間，將點r2併到r1 
		  	int r2, r1 = rand()%total_remain+1;
		  	do{
		  		r2 = rand()%total_remain+1;	
			}while(r1 == r2);
			
			//開始合併 
			for(int i=1; i<=v; i++){
				if(i != remain[r1]){
					edge_num[remain[r1]][i] += edge_num[remain[r2]][i];
					edge_num[i][remain[r1]] += edge_num[i][remain[r2]];
				}
				edge_num[remain[r2]][i] = 0;
				edge_num[i][remain[r2]] = 0;
			}
			remain[r2] = remain[total_remain];		//r2消失，用陣列最後一個去補，然後少一個點 
			total_remain -= 1;
		}
		
		if(min > edge_num[remain[1]][remain[2]])
			min = edge_num[remain[1]][remain[2]];
	}
	
	cout << "做完50次randomized min-cut猜測最低值為：" << min;
	return 0;
} 
