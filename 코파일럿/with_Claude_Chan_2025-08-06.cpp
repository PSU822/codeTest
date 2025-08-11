/*
문제: 회의실 배정
하나의 회의실에 여러 회의가 신청되었습니다.
겹치지 않게 최대한 많은 회의를 배정하세요.

입력:
4
1 4    // 1시~4시
3 5    // 3시~5시
0 6    // 0시~6시  
5 7    // 5시~7시

출력:
2

그리디 전략: 종료 시간 빠른 순으로 정렬 후 선택
(활동 선택 문제와 유사하지만 조금 다른 접근)

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> t, pair<int,int> f){
    return t.second < f.second;
}

int n;
int main(){
    cin >> n;
    vector<pair<int,int>> schedule(n);

    for(int i = 0; i < n; ++i){
        cin >> schedule[i].first >> schedule[i].second;
    }

    sort(schedule.begin(),schedule.end(),cmp);
    int ans = 1;
    /*
    for(int i = 1; i < n; ++i){
        if(schedule[0].second <= schedule[i].first) ans++; 
    }
    */
    
    // 현재 방식은 정렬해둔 상태에서 첫 번째 벡터를 요소로 판단하지만, '최대한' 을 따진다면 DP 처럼 각 시간을 골랐을 때의 최대치를 구해야 하기 때문에
    // 모든 시간대를 한번 고르고 거기서 가능한 시간을 골라서 max 로 비교하여 제일 많은 시간을 고를 수 있는 방법을 찾아야한다?
    // 하지만 이전 그리디 문제를 생각하면 최적해 보다는 현재에서 최선이므로 이게 옳은지는 모르겠음.

    // 엣지케이스를 고려하여 수정
    int last_end = schedule[0].second;
    for(int i = 1; i < n; ++i){
        if(last_end <= schedule[i].first){ 
            last_end = schedule[i].second;
            ans++;
        } 
    } 
    cout << ans;
    return 0;
}