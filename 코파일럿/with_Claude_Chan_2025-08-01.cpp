/*
그리디 알고리즘 (Greedy Algorithm)

핵심 개념:
- "매 순간 최선의 선택"을 하는 알고리즘
- DP와 달리 한 번 선택하면 되돌리지 않음
- 빠르지만 항상 최적해를 보장하지는 않음

특징:
- 직관적이고 구현이 간단
- 정렬과 함께 많이 사용됨
- "증명"이 중요 (그리디가 최적해를 보장하는지)

문제: 활동 선택 문제
N개의 활동이 있고, 각각 시작 시간과 종료 시간이 주어집니다.
겹치지 않게 최대한 많은 활동을 선택하는 문제입니다.

입력:
3
1 4    // 1시~4시
3 5    // 3시~5시  
0 6    // 0시~6시

출력:
2

설명: 1~4시, 3~5시는 겹치므로 둘 중 하나만 선택
최적: (1,4) + (3,5) 불가능, (0,6) 하나만 또는 (1,4), (3,5) 중 하나
정답: (1,4) 선택 후 다음 가능한 것 없음... 

아니다 다시: (3,5) 하나만 선택하면 2개가 최대

그리디 전략: 종료 시간 빠른 순으로 정렬 후 욕심쟁이로 선택!
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

bool cmp(pair<int,int> x, pair<int,int> y ){
    return x.second < y.second;
}
int main(){
    cin >> n;
    vector<pair<int,int>> input(n,pair(0,0));
    vector<bool> select(24,false);
    int ans = 0;

    for(auto& iter : input){
        cin >> iter.first >> iter.second;
    }

    sort(input.begin(), input.end(), cmp);
    // bool 막대로 표현하기? or 숫자로 비교하기?
    for(int i = 0; i < n; ++i){
        bool ispossable = true;
        for(int j = input[i].first; j < input[i].second; ++ j){
            if(select[j] == true){
                ispossable = false;
                break;
            }
        }

        if(ispossable){
            for(int j = input[i].first; j < input[i].second; ++j){
                select[j] = true;
            }
            ans++;
        } 
    }
    
    cout << ans;
}