/*
문제: 거스름돈 만들기
N원을 거슬러줄 때, 최소 동전 개수로 거슬러주세요.
동전 종류: 500원, 100원, 50원, 10원

입력: 1260
출력: 6 (500*2 + 100*2 + 50*1 + 10*1)

그리디 전략: 큰 동전부터 욕심쟁이로!
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int total_cost;
    int coins = 0;
    cin >> total_cost;

    /*if(total_cost < 10){    // 입력값이 10 미만이면 바로 0 반환
        cout << coins;
        return 0;
    }

    if(total_cost >= 500){
        coins += total_cost / 500;
        total_cost %= 500;
    }

    if(total_cost >= 100){
        coins += total_cost / 100;
        total_cost %= 100;
    }

    
    if(total_cost >= 50){
        coins += total_cost / 50;
        total_cost %= 50;
    }

    
    if(total_cost >= 10){
        coins += total_cost / 10;
        total_cost %= 10;
    }*/

    vector<int> coin = {500,100,50,10};

    for(auto& iter : coin){
        coins += total_cost / iter;
        total_cost %= iter;
    }

    cout << coins;
    return 0;
}