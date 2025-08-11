/*
📝 문제: LCS (Longest Common Subsequence)

두 문자열에서 공통으로 나타나는 부분 수열 중 가장 긴 것의 길이를 구하세요.
(부분 수열: 연속되지 않아도 순서만 같으면 됨)

입력:
ABCDGH
AEDFHR

출력:
3

설명: 
ADH가 최장 공통 부분 수열 (길이 3)
A_B_C_D_G_H
A_E_D_F_H_R
↑   ↑   ↑

예시:
     ""  A  E  D  F  H  R
""    0  0  0  0  0  0  0
A     0  1  1  1  1  1  1
B     0  1  1  1  1  1  1  
C     0  1  1  1  1  1  1
D     0  1  1  2  2  2  2
G     0  1  1  2  2  2  2
H     0  1  1  2  2  3  3

두 문자 열을 비교하며, 같은 개수를 dp 배열에 입력하는 간단한..알고리즘?
겹치는 문자 개수를 계속 가져가기 때문에 순서상관을 하지 않는 문자열이라면 이렇게 구현이 가능
if str1[i - 1] == str[j - 1]  
    dp[i][j] = dp[i - 1][j - 1] + 1
else
    dp[i][j] = max(dp[i-i][j], dp[i][j-1]) // 이전 결과를 챙겨야 하기에, 최대로 겹치는 문자열을 가져가야함
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> DP(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for(int i = 1; i <= str1.size(); ++i){
        for(int j = 1; j <= str2.size(); ++j){
            if(str1[i-1] == str2[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    cout << DP[str1.size()][str2.size()];
}