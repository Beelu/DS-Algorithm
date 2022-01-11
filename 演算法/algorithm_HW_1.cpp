#include <iostream>
using namespace std;

int *merge(int *a, int *b, int len1, int len2);
int search(int *c, int goal, int len);

int main(){
	//��l�ȳ]�w 
	int len1, len2;
	cin >> len1;
	cin >> len2;
	int totalLen = len1 + len2;
	int a[len1] = {0};
	int b[len2] = {0};
	for(int i=0; i<len1; i++){
		cin >> a[i];
	}
	for(int j=0; j<len2; j++){
		cin >> b[j];
	}
	
	//�X�ְ}�C 
	int *c = merge(a, b, len1, len2);
	
	//�j�M�ؼ� 
	int target;
	cin >> target;
	int find = search(c, target, totalLen);
	
	//�L�X���G 
	for(int i=0; i<totalLen-1; i++){
		cout << c[i] << " ";
	}
	cout << c[totalLen-1] << endl;
	if(find > -1){
		cout << find;
	}else{
		cout << "not found" << endl;
	}
	
	return 0;
}

int *merge(int *a, int *b, int lenA, int lenB){
	int ai=0;
	int bi=0;
	int ci=0;
	int *c = new int[lenA+lenB]; 
	while(ai<lenA && bi<lenB){
		if(a[ai] < b[bi]){
			c[ci++] = a[ai++];
		}else{
			c[ci++] = b[bi++];
		}
	}
	
	while(ai<lenA){
		c[ci++] = a[ai++];
	}
	while(bi<lenB){
		c[ci++] = b[bi++];
	}
	
	return c;
}

int search(int *c, int goal, int len){
	int left = 0;
	int right = len - 1;
	while(left <= right){
		int mid = (left+right) / 2;
		if(c[mid] == goal){
			return mid;
		}else if(c[mid] > goal){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return -1;
}
