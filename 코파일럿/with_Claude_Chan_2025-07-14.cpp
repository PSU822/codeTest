/*
Dp 입문
잘 알고 있는 피보나치를 이용해서 연습
원래의 재귀 피보나치는 매번 실행 때 마다 0까지의 값을 다시 구해야했지만, 메모를 이용한 기법을 활용하여 재 계산하지 않는 방식으로 구현

의사 코드
memo[100] = {-1}

피보나치(int x)
    if x <= 1 return x
    if memo[x] != -1 return memo[x]

    memo[n] = 피보나치(x-1) + 피보나치(x-2)
    return memo[n]
*/

#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> memo(100,0);
vector<int> dp(100);

int fibo_dp_top(int x){
    if(x <= 1) return x;
    if(memo[x] != 0) return memo[x];
    memo[x] = fibo_dp_top(x - 1) + fibo_dp_top(x - 2);

    return memo[x];
}

int fibo_dp_down(int x){
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= x; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[x];
}

int main(){
    cin >> n;
    if(n > 99){
        cout << "range error, program end.";
        return 0;
    }

    int top = fibo_dp_top(n);
    int down = fibo_dp_down(n);

    cout << top << " " << down << '\n';

    for(int i = 0; i <= n; ++i){
        cout << memo[i] << " ";
    }
    return 0;
}