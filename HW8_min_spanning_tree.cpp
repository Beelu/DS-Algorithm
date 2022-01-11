#include <iostream>
using namespace std;

int main(){
	int times;
	cin >> times;
	int vertex, weightNum, total=0;		//頂點，邊數，總距離 
	
	for(int k=0; k<times; k++){
		cin >> vertex;
		cin >> weightNum;
		int adjanceny[vertex][vertex] = {0};
		for(int i=0; i<vertex; i++){		//初始化 
			for(int j=0; j<vertex; j++){
				adjanceny[i][j] = 1000;
			}
		}
		
		int from, to, distance;		
		for(int i=0; i<weightNum; i++){		//初始建立距離的陣列 
			cin >> from;
			cin >> to;
			cin >> distance;
			
			adjanceny[from][to] = distance;
			adjanceny[to][from] = distance;
		}
		
		int arrived[vertex] = {0};		//用來記錄該點是否已被抵達
		int start = 0;		//起點，都從0頂點出發
		arrived[0] = 1;
		int min = 1000;
		for(int h=0; h<vertex-1; h++){		//建立n-1條路時tree就建立完成，以下開始走訪陣列 
			for(int i=0; i<vertex; i++){		//from 
				for(int j=0; j<vertex; j++){		//to
					if(arrived[i] == 1 && arrived[j] == 0){		//從已抵達到未被抵達才可連線 
						if(min > adjanceny[i][j]){
							min = adjanceny[i][j];
							from = i;		//from用來記錄從哪個點往外連 
							to = j;		//to用來記錄哪個點將被連線 
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
