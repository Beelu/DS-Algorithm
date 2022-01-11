#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
 
const int maxn=1005;
string s1, s2;
int dp[maxn][maxn];
 
int main() {
    cin >> s1;
    cin >> s2;
    
    clock_t start, end; // �x�s�ɶ��Ϊ��ܼ�
    start = clock(); // �p��}�l�ɶ�
    
    int l1 = (int)s1.length();
    int l2 = (int)s2.length();
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=l1; i++) {
        for (int j=1; j<=l2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    end = clock(); // �p�⵲���ɶ�
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // �p���ڪ�O�ɶ�
    
    cout << "���׬��G" << dp[l1][l2] << endl;
    cout << "��O�ɶ��G" << end << endl; 
    
    return 0;
}
