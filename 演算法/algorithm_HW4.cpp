#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

struct alpha{
	int location;			//�o���ܼ��x�s�r���bY�r�ꤤ����m 
	int place;				//�o���ܼ��x�s�r���bLIS�ĤG�hvector������m 
	char letter;
};
vector<alpha> scoreStr;
vector< vector<alpha> > LIS;
stack<char> result;
int BinarySearch(vector< vector<alpha> > data, int size, int target);

int main(){
	//��l��Ū�J��Ӧr��ñN���ର�}�C 
	string X1, Y1;
	cin >> X1;
	cin >> Y1;
	int m = X1.length();
	int n = Y1.length();
	char X[m];
	char Y[n];
	copy(X1.begin(), X1.end(), X);
	copy(Y1.begin(), Y1.end(), Y);
	
	//�P�P(�O����Ӧ�m���ۦP)
	for(int i=0; i<m; i++){
		for(int j=n-1; j>=0; j--){
			if(X[i] == Y[j]){
				struct alpha newalpha = {
					.location = j,
					.place = -1,
					.letter = X[i]
				};
				scoreStr.push_back(newalpha);
			}
		}
	} 
	
	clock_t start, end; // �x�s�ɶ��Ϊ��ܼ�
    start = clock(); // �p��}�l�ɶ�
    
	//LIS�p�� 
	vector<alpha> newvec;
	newvec.push_back(scoreStr[0]);
	LIS.push_back(newvec);
	for(int i=1; i<scoreStr.size(); i++){
		//�p�G�O�̤p
		if(scoreStr[i].location < LIS[0][LIS[0].size()-1].location){ 
			LIS[0].push_back(scoreStr[i]);
		}else if(scoreStr[i].location > LIS[LIS.size()-1][LIS[LIS.size()-1].size()-1].location){		//�p�G�O�̤j
			vector<alpha> newv;
			scoreStr[i].place = LIS[LIS.size()-1].size()-1;
			newv.push_back(scoreStr[i]);
			LIS.push_back(newv);
		}else{
			int temp = BinarySearch(LIS, LIS.size(), scoreStr[i].location);
			scoreStr[i].place = LIS[temp-1].size()-1;
			LIS[temp].push_back(scoreStr[i]);
		}
	}
	
	//LIS���G 
	int nextplace = LIS[LIS.size()-1][LIS[LIS.size()-1].size()-1].place;
	result.push(LIS[LIS.size()-1][LIS[LIS.size()-1].size()-1].letter);
	for(int i=LIS.size()-2; i>=0; i--){
		result.push(LIS[i][nextplace].letter);
		nextplace = LIS[i][LIS[i].size()-1].place;
	}
	
	end = clock(); // �p�⵲���ɶ�
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // �p���ڪ�O�ɶ�
	
	cout << endl;
	cout << "��O�ɶ�: " <<  end << endl;
	cout << "LCS: "; 
	while(!result.empty()){
		cout << result.top();
		result.pop();
	}
	cout << endl;
	
	return 0;
} 

int BinarySearch(vector< vector<alpha> > data, int size, int target){
    int lo = 0;
    int hi = size - 1;

    while (lo <= hi) { 
        int mid = (lo + hi) / 2; 
        if (data[mid][data[mid].size()-1].location > target){
            hi = mid - 1;
        }
        else if (data[mid][data[mid].size()-1].location < target){
            lo = mid + 1;
        }
        else{
            return mid;
        }
    }

	if(lo>hi)
    	return lo;
    else
    	return hi;
}
