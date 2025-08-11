/*
2차원 dp 알고리즘

N개의 물건과 최대 무게 W인 배낭이 있습니다.
각 물건은 무게(weight)와 가치(value)를 가지고 있고,
배낭에 넣을 수 있는 물건들의 가치 합의 최댓값을 구하세요.

조건: 각 물건은 0개 또는 1개만 선택 가능 (0/1 배낭)

입력:
4 7        // N=4개 물건, W=7 최대무게
6 13       // 1번 물건: 무게6, 가치13
4 8        // 2번 물건: 무게4, 가치8  
3 6        // 3번 물건: 무게3, 가치6
5 12       // 4번 물건: 무게5, 가치12

출력:
14

핵심 구현 : dp[i][w] 가 있다고 고려했을 때, i 번째 물건까지 고려했을 때, 무게 w 이하에서 얻을 수 있는 가치를 dp 벡터에 저장한다.
dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])

불가능한 값 = 이전 물건의 값
가능한 값(조합이 바뀔 수 있는 값) = 이전의 테이블 최대치와 현재무게를 계산하여 최대치 재설정

다만, i-1 의 기준이 되어야하는 [0][0] 이 있어야 이 구현이 돌아가므로 물건의 정보를 0번부터 집어넣는게 아닌, 1번부터 집어넣는다.
그리고 w-weight[i] 가 벡터 범위를 벗어나면 안되므로 점화식에 조건을 추가한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int max_weight;

int main(){
cin >> n >> max_weight;

vector<int> weight(n + 1, 0);
vector<int> value(n + 1, 0);
vector<vector<int>> DP(n + 1, vector<int>(max_weight + 1,0));  // 최대 무게 이하의 경우까지 계산해야하므로 max + 1

for(int i = 1; i <= n; ++i){
    cin >> weight[i] >> value[i];
}

for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= max_weight; ++j){
        DP[i][j] = DP[i-1][j];

        if(j >= weight[i]){ 
            DP[i][j] = max(DP[i-1][j],          // i번째 물건 스킵
            DP[i-1][j-weight[i]] + value[i]);   // i번째 물건을 선택
        }  
    }
}

cout << DP[n][max_weight];

return 0;

}