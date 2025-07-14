/*
#include <iostream>
#include <algorithm>


2D 배열 회전 문제
array로 푸는게 더 직관적이겠지만, 2차원 벡터는 벡터에 벡터를 집어넣는 방식이라 구현이 까다로울 것으로 예측
테스트 케이스로 받을 n* n array를 이용.
1 2         3 1                 
3 4 일때,   4 2 이 되어야함.

1 2 3           7 4 1
4 5 6           8 5 2
7 8 9 일때,     9 6 3 이 되어야함.

0,0 -> 0,2
0,1 -> 1,2
0,2 -> 2,2

1,0 -> 0,1
1,1 -> 1,1
1,2 -> 2,1

2,0 -> 0,0
2,1 -> 1,0
2,2 -> 2,0

각 배열의 인덱스 자리에서 [원래 뒷자리][점점 작아지는 N-1 값부터 시작하는 값] 으로 바뀜.
2중 for 문을 쓴다고 하면.
i = 0, j = 0 스타트
0,0 0,1 0,2
0,2 1,2 2,2 가 되어야 하므로,
[j][i루프에서 쓰이는 체크변수] 를 쓰는게 제일 쉬워보임
 
using namespace std;

int main(){
    int N;
    cin >> N;

    int input[N][N];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int V;
            cin >> V;
            input[i][j] = V;
        }
    }

    int cnt = N;

    for(int i = 0; i < N; ++i){
        cnt--;
        for(int j = 0; j < N; ++j){
            cout << input[N-1-j][i] << " ";
        }
        cout << '\n';
    }
    
}
*/

/*
달팽이 배열 만들기
N을 받고 시작.
반복문 내부에서 '만' 처리하는건 아닌 것으로 보임.
dx, dy로 방향 제어
우->하->좌->상 이므로, dx dy의 배치는
dx{0,1,0,-1}, dy{1,0,-1,0}
경계 체크 함수도 필요

while, 탈출 조건은 i값이 N * N 보다 커질때
현재 x,y 좌표를 임시 x,y에 담음->
현재 dx,dy 진행방향 값을 넣고 방문한 배열 + 배열 안인지 검사->
비어있으며 배열 내부라면 arr[x][y]에 i 값을 넣고 i값 증가
배열 내부지만 비어있지 않다면 방향전환 후 현재 반복 넘어감


#include<iostream>

using namespace std;
int N;

bool inArray(int x, int y){
    return x <= N - 1 && y <= N - 1 && x >= 0 && y >= 0;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    cin >> N;
    int arr[N][N];
    bool check[N][N] = {false};

    int x = 0, y = 0;
    int p = 1;

    arr[x][y] = p;
    check[x][y] = true;
    p++;

    int pos = 0;

    while(p <= N * N){
        int gx = x, gy = y;
        gx += dx[pos]; gy += dy[pos];

        if(inArray(gx,gy) && !check[gx][gy]){ 
            arr[gx][gy] = p;
            check[gx][gy] = true;
            p++;
            x = gx; y = gy;
        }
        else{   // 배열 안이 아니거나 방문한 칸이면 방향 바꿈
            pos = (pos + 1) % 4;
        }
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
*/