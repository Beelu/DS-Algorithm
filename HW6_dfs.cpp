#include <iostream>
#include <stdlib.h>
using namespace std;

struct offsets{
	short int vert;
	short int horiz;
};

int main(){
	offsets move[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	int row, col, alone;//point為暫存目前走到的點，position用來計算該點為幾行幾列，alone紀錄沒人連到的點QQ
	int link;
	
	while(true){
		//==============================主要演算法===========================//
		cin >> row;
		cin >> col;
		if(row == 0 && col == 0)
			break;
			
		char map[row+2][col+2] = {0};
		for(int i=0; i<row+2; i++){		//讀入 
			for(int j=0; j<col+2; j++){
				if(i == 0 || j == 0 || i == row+1 || j == col+1){
					map[i][j] = '.';
				}else{
					cin >> map[i][j];	
				}
			}
		}
		
		alone=0;
		for(int i=1; i<row+1; i++){		//判斷 
			for(int j=1; j<col+1; j++){
				if(map[i][j] == '*'){
					link = 0;
					for(int k=0; k<8; k++){
						if(map[i+move[k].vert][j+move[k].horiz] == '*'){
							link++;
						}
					}
					if(link == 0){
						alone++;
					}
				}
			}
		}
		
		cout << alone << endl;
	}//===========================================================================//
	
	return 0;
}
