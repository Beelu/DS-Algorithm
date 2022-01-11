#include <iostream>
#include <stdlib.h>
using namespace std;

struct offsets{
	short int vert;
	short int horiz;
};

int main(){
	offsets move[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	int row, col, alone;//point���Ȧs�ثe���쪺�I�Aposition�Ψӭp����I���X��X�C�Aalone�����S�H�s�쪺�IQQ
	int link;
	
	while(true){
		//==============================�D�n�t��k===========================//
		cin >> row;
		cin >> col;
		if(row == 0 && col == 0)
			break;
			
		char map[row+2][col+2] = {0};
		for(int i=0; i<row+2; i++){		//Ū�J 
			for(int j=0; j<col+2; j++){
				if(i == 0 || j == 0 || i == row+1 || j == col+1){
					map[i][j] = '.';
				}else{
					cin >> map[i][j];	
				}
			}
		}
		
		alone=0;
		for(int i=1; i<row+1; i++){		//�P�_ 
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
