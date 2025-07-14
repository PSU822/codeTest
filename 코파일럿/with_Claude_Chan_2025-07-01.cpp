/*

백트래킹과 재귀
순서?

힌트 분석부터 해보자.
DFS같이 사용한 벡터 위치 활용해서 해당 숫자를 썼는지 체크할 것 같다.

backtrack 매개변수
depth -> 1~n 까지의 분기를 결정하기 위한 변수, 재귀마다 1씩 올라서 들어가고 탈출 조건으로 n보다 크면 탈출
result -> 1차원 벡터이다. 1~n 까지 숫자를 고르기 위한 벡터로 추측
used -> 위의 result 벡터를 보면서 중복되는 수를 고르지 않기 위한 벡터로 추측

4 2 의 테스트 케이스라면
[true, false, false, fasle]
depth true
depth false
depth false
depth false

1 2
1 3 
1 4 
... 로 작동하겠지만


m > 2 라면
1 2 3
1 3 4
와 같은 결과도 내야하는데, 
depth false false
depth true false 와 같이 동작한다.

따라서, 실제 재귀에서 따라가는 동작은
1 2 -> 2 1 -> 3 1 -> 4 1
2 1 -> 2 3 -> 2 4... 가 더 합리적으로 보인다.

의사코드
start
input n,m
result[m], used[n]

backtrack(depth, result, used)

backtrack{
    if depth == m
        print result, return

    for i = 0, < n ++i
        if !used[i]
            result[depth] = i + 1, used[i] = true
            backtrack(depth + 1, result, used)
            used[i] = false
}


#include <iostream>
#include <vector>

using namespace std;

int n,m;
void backTrack(int depth, vector<int>& result, vector<bool>& used){
    if(depth == m){
        for(int i = 0; i < m; ++i){
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; ++i){
        if(!used[i]){
            result[depth] = i + 1;
            used[i] = true;
            backTrack(depth + 1, result, used);
            used[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    vector<int> result(m);
    vector<bool> used(n,false);

    backTrack(0, result, used);

    return 0;
}

전체적인 구조는 같으나. backTrack 함수에 start 변수를 받는다는 점이 다르다.
현재 구상한 backTrack 함수의 '시작' 숫자는 i + 1, 즉 인덱스 + 1를 따라가므로, 
재귀 탐색을 들어갈 땐 현재 반복문의 i를 넣고, 반복문 내의 if 조건에 && i > start 조건을 추가하면 될 것 같아 보인다.


#include<iostream>
#include<vector>

using namespace std;

int n,m;

void backTrack(int depth, int start, vector<int>& result){
    if(depth == m){
        for(int i = 0; i < m; ++i){
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < n; ++i){
        result[depth] = i + 1;
        backTrack(depth + 1, i + 1, result);
    }
}


int main(){
    cin >> n >> m;
    vector<int> result(m);

    backTrack(0,0,result);

    return 0; 
}

*/