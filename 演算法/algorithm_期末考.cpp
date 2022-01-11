#include <iostream>

using namespace std;

int main(){
	int s;
	cin >> s;		//source
	int u, v, weight;
	//martrix
	int adj[501][501] = {0};
	int find[501];		//紀錄該點有沒有在輸入的input
	for(int i=0; i<=500; i++){
		for(int j=0; j<=500; j++){
			find[i] = 0;
			adj[i][j] = 5000000;
			if(i == j)
				adj[i][j] = 0;
			
		}
	}
	while(cin >> u){
		cin >> v >> weight;
		adj[u][v] = weight;
		find[u]=1;
		find[v]=1;
	}
//	for(int i=0; i<4; i++){
//		cin >> u >> v >> weight;
//		adj[u][v] = weight;
//		find[u]=1;
//		find[v]=1;
//	}	
	
	for(int k=1; k<=500; k++){
		for(int u=1; u<=500; u++){
			for(int v=1; v<=500; v++){
				if(adj[u][k] + adj[k][v] < adj[u][v] && find[k])
					adj[u][v] = adj[u][k] + adj[k][v];
			}
		}
	}
	
	//判斷有沒有負迴圈 
	bool neg_cycle = false;
	for(int i=1; i<=500; i++){
		if(adj[i][i] < 0){
			neg_cycle = true;
		}
	}
	//印出 
	if(neg_cycle){
		cout << "There is a negative cycle!" << endl;
	}else{
		for(int i=1; i<=500; i++){
			if(find[i]){
				if(adj[s][i] > 10000)
					cout << "Shortest path from " << s << " to " << i << ": No such path" << endl;
				else
					cout << "Shortest path from " << s << " to " << i << ": " << adj[s][i] << endl;
			}
		}
	}
	
	return 0;
} 
