//Hirschberg's algorithm
//�]�w���Y���ŦXscore��+0�A�Y�ŦX�h+1 
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void LastLine(int result[], char X[], char Y[], int lengthX, int lengthY);
string Hirschberg(char* X, char* Y, int m, int n);

int main(){
	//��l��Ū�J��Ӧr��ñN���ର�}�C 
	string X1, Y1;
	int m, n;
	cin >> X1;
	cin >> Y1;
	m = X1.length();
	n = Y1.length();
	char X[m];
	char Y[n];
	copy(X1.begin(), X1.end(), X);
	copy(Y1.begin(), Y1.end(), Y);
	
	clock_t start, end; // �x�s�ɶ��Ϊ��ܼ�
    start = clock(); // �p��}�l�ɶ�
	
	string s = Hirschberg(X, Y, m, n);
	
	end = clock(); // �p�⵲���ɶ�
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // �p���ڪ�O�ɶ�
	
	cout << endl;
	cout << "LCS���G " << s << endl; 
	cout << "��O�ɶ��G" << end << endl; 
	
	return 0;
}

//LCS�p��æ^�ǳ̫�@�椧���� 
void LastLine(int result[], char X[], char Y[], int lengthX, int lengthY){
	int score[2][lengthY+1];
	for(int i=0; i<=lengthY; i++){
		score[0][i] = 0;
		score[1][i] = 0;
	}
	for(int i=1; i<=lengthX; i++){
		for(int j=1; j<=lengthY; j++){
			//�p�G��Ӧr���ۦP
			if(X[i-1] == Y[j-1]){ 
				score[1][j] = score[0][j-1]+1;
			//�p�G���P
			}else{								 
				if(score[0][j] > score[1][j-1])
					score[1][j] = score[0][j];
				else
					score[1][j] = score[1][j-1];
			}
		}
		//�N�r��1�\��r��0�M���~��
		for(int k=0; k<=lengthY; k++){
			score[0][k] = score[1][k];
		}
	}
	
	for(int k=0; k<=lengthY; k++){
		result[k] = score[0][k];
	}
} 

//Hirschberg
string Hirschberg(char* X, char* Y, int xlen, int ylen){
	string result = "";
	if(xlen == 0 || ylen ==0){
		return result;
	}else if(xlen == 1 || ylen == 1){
		if(xlen == 1){
			for(int i=0; i<ylen; i++){
				if(X[0] == Y[i]){
					result += X[0];
					return result;
				}
			}
		}else{
			for(int i=0; i<xlen; i++){
				if(Y[0] == X[i]){
					result += Y[0];
					return result;
				}
			}
		}
	}else{
		int xmid = xlen/2;
		
		//����
		char revY[ylen], revX[xlen-xmid];
		for(int i=0; i<ylen; i++)
			revY[i] = Y[ylen-i-1];
		for(int j=0; j<xlen-xmid; j++){
			revX[j] = X[xlen-j-1];
		}

		//�p���A��̤j�ȡA��줤���u 
		int scoreL[ylen+1], scoreR[ylen+1], max=-1, cut;
		LastLine(scoreL, X, Y, xmid, ylen);
		LastLine(scoreR, revX, revY, xlen-xmid, ylen);
		for(int i=0; i<=ylen; i++){
			if(scoreL[i]+scoreR[ylen-i] > max){
				max = scoreL[i]+scoreR[ylen-i];
				cut = i;
			}
		}
		
		//���W�϶��Υk�U�϶����s�r�� 
		char newRX[xmid], newRY[cut], newLX[xlen-xmid], newLY[ylen-cut];
		for(int i=0; i<xmid; i++)
			newRX[i] = X[i];
		for(int i=xmid; i<xlen; i++)
			newLX[i-xmid] = X[i];
		for(int i=0; i<cut; i++)
			newRY[i] = Y[i];
		for(int i=cut; i<ylen; i++)
			newLY[i-cut] = Y[i];
		
		//���j 
		result = Hirschberg(newRX, newRY, xmid, cut) + Hirschberg(newLX, newLY, xlen-xmid, ylen-cut);
	}
	return result;
}
