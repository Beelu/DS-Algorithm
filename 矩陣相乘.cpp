#include <string>
#include <iostream>
using namespace std;

int main(){
	int row1, col1, row2, col2, temp = 0;
	cin >> row1;
	cin >> col1;
	
	int martrix1[row1][col1] = {0};
	for(int i = 0; i<row1; i++){			//�Ĥ@�ӯx�}
		for(int j = 0; j<col1; j++){
			cin >> temp;
			if(temp == 0){
				martrix1[i][j] = 0;
			}
			else{
				martrix1[i][j] = temp;			//���O0�hpush
			}
		}
	}
	
	cin >> row2;
	cin >> col2;
	int martrix2[row2][col2] = {0};
	for(int i = 0; i<row2; i++){			//�ĤG�ӯx�} 
		for(int j = 0; j<col2; j++){
			cin >> temp;
			if(temp == 0){
				martrix2[i][j] = 0;
			}
			else{
				martrix2[i][j] = temp;			//���O0�hpush 
			}
		}
	}
	//==============================================================//
	int result[row1][col2] = {0};
	int sum;
	for(int i = 0; i<row1; i++){			//�Ĥ@�x�}��row 
		for(int j = 0; j<col2; j++){			//�ĤG�x�}��col 
		sum = 0;
			for(int k = 0; k<col1; k++){			//�Ĥ@�x�}��col 
				sum += martrix1[i][k] * martrix2[k][j];
			}
		result[i][j] = sum;
		}
	}

	for(int i = 0; i<row1; i++){			//�Ĥ@�x�}��row 
		for(int j = 0; j<col2; j++){			//�ĤG�x�}��col
			if(result[i][j] != 0 ){
				cout << i << " " << j << " " << result[i][j] << endl;	
			}
		}
	}
	
	return 0;
}
