//Hirschberg's algorithm
//設定為若不符合score為+0，若符合則+1 
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void LastLine(int result[], char X[], char Y[], int lengthX, int lengthY);
string Hirschberg(char* X, char* Y, int m, int n);

int main(){
	//初始化讀入兩個字串並將其轉為陣列 
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
	
	clock_t start, end; // 儲存時間用的變數
    start = clock(); // 計算開始時間
	
	string s = Hirschberg(X, Y, m, n);
	
	end = clock(); // 計算結束時間
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // 計算實際花費時間
	
	cout << endl;
	cout << "LCS為： " << s << endl; 
	cout << "花費時間：" << end << endl; 
	
	return 0;
}

//LCS計算並回傳最後一行之分數 
void LastLine(int result[], char X[], char Y[], int lengthX, int lengthY){
	int score[2][lengthY+1];
	for(int i=0; i<=lengthY; i++){
		score[0][i] = 0;
		score[1][i] = 0;
	}
	for(int i=1; i<=lengthX; i++){
		for(int j=1; j<=lengthY; j++){
			//如果兩個字元相同
			if(X[i-1] == Y[j-1]){ 
				score[1][j] = score[0][j-1]+1;
			//如果不同
			}else{								 
				if(score[0][j] > score[1][j-1])
					score[1][j] = score[0][j];
				else
					score[1][j] = score[1][j-1];
			}
		}
		//將字串1蓋到字串0然後繼續做
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
		
		//反轉
		char revY[ylen], revX[xlen-xmid];
		for(int i=0; i<ylen; i++)
			revY[i] = Y[ylen-i-1];
		for(int j=0; j<xlen-xmid; j++){
			revX[j] = X[xlen-j-1];
		}

		//計分，找最大值，找到中間線 
		int scoreL[ylen+1], scoreR[ylen+1], max=-1, cut;
		LastLine(scoreL, X, Y, xmid, ylen);
		LastLine(scoreR, revX, revY, xlen-xmid, ylen);
		for(int i=0; i<=ylen; i++){
			if(scoreL[i]+scoreR[ylen-i] > max){
				max = scoreL[i]+scoreR[ylen-i];
				cut = i;
			}
		}
		
		//左上區塊及右下區塊之新字串 
		char newRX[xmid], newRY[cut], newLX[xlen-xmid], newLY[ylen-cut];
		for(int i=0; i<xmid; i++)
			newRX[i] = X[i];
		for(int i=xmid; i<xlen; i++)
			newLX[i-xmid] = X[i];
		for(int i=0; i<cut; i++)
			newRY[i] = Y[i];
		for(int i=cut; i<ylen; i++)
			newLY[i-cut] = Y[i];
		
		//遞迴 
		result = Hirschberg(newRX, newRY, xmid, cut) + Hirschberg(newLX, newLY, xlen-xmid, ylen-cut);
	}
	return result;
}
