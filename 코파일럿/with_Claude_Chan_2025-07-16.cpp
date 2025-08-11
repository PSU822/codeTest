/*
dp 계단오르기
한번에 1, 2칸 오를 수 있음
연속 3칸은 오를 수 없음 (1,2,3 X | 1,2,4 O)
마지막 도착 계단은 반드시 밟음
계단마다 점수가 있으며, 이 조건을 따라가며 점수의 최댓값 구하기

핵심 점화식은
dp[i] = max(dp[i - 2] + score[i], dp[i-3] + score[i-1] + score[i])
// 두 칸 전에서 온 경우(해당 칸은 건너뜀) / 3칸 전에서 온 경우 를 비교하여 최대값을 넣음
다만,dp[0] = score[0] 이고, n이 1, 2인 경우도 생각해야 하므로
안전하게 두칸 전/ 세칸 전의 경우는 직접 초기화를 해준다.

dp[3] 부터는 점화식을 쓰면 되므로, dp[n-1] 까지 dp를 구하고, 문제의 조건인 '마지막 계단' 을 밟았을 때 값인 dp[n-1] 을 구한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

int main(){
    cin >> n;
    vector<int> dp(n,0);
    vector<int> info(n,0);

    for(int i = 0; i < n;++i){
        cin >> info[i];
    }   // 계단 정보 초기화

    dp[0] = info[0];
    if(n > 1) dp[1] = info[0] + info[1];                            // 계단이 1 보다 많은 경우
    if(n > 2) dp[2] = max(info[0] + info[2], info[1] + info[2]);    // 계단이 2보다 많은 경우
    if(n > 3){
        for(int i = 3; i < n; ++i){
            dp[i] = max(dp[i-2] + info[i], dp[i-3] + info[i-1] + info[i]);
        }
    }   // 계단이 3개 이상 있을 때 부터 가능한 DP 알고리즘

    cout << dp[n-1];

    return 0;

}