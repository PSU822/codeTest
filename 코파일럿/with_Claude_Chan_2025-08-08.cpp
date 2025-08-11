/*
📝 문제: 로프로 최대 중량 들기

N개의 로프가 있고, 각각 견딜 수 있는 중량이 다릅니다.
k개의 로프를 선택해서 들 수 있는 최대 중량을 구하세요.

조건: k개 로프를 함께 사용하면, 중량이 k개로 분산됩니다.
     가장 약한 로프의 한계 × k = 최대 중량

입력:
3
10    // 10kg까지 견딤
15    // 15kg까지 견딤  
20    // 20kg까지 견딤

출력:
30

설명:
- 1개 사용: max(10, 15, 20) = 20
- 2개 사용: min(15, 20) × 2 = 30  ← 최대!
- 3개 사용: min(10, 15, 20) × 3 = 30

그리디 전략: 정렬 후 각 경우의 수 계산하여 최댓값!
*/

/*
고른 로프 중 제일 약한 로프 x 고른 개수 -> 최대 중량, 정렬 후 가능 한 개수를 곱하면 최적된 값이 나오지 않을까 라는 예측.
ex ) 10 20 50 30 -> 10 20 30 50, 10을 고를경우, 최대 5개까지(n개 까지) 
20 을 고를 경우, 최대 4개까지 (N-1)
...
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int max_val = 0;

int main(){
    cin >> n;
    vector<int> ropes(n);

    for(int i = 0; i < n; ++i){
        cin >> ropes[i];
    }

    sort(ropes.begin(),ropes.end());

    for(int i = 0; i < n; ++i){
        max_val = max(max_val, ropes[i] * (n - i));
    }

    cout << max_val;
    return 0;
}