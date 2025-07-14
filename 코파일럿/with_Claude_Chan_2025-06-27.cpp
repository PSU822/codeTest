/*
로봇 청소기 문제
nxm 방 범위 체크 함수, check 벡터, dx,dy 벡터가 필요해보임
반시계방향으로 회전 = 북-> 서-> 남-> 동
d의 방향은 북 동 남 서

즉, dx {-1,0,1,0} | dy {0,1,0,-1}
회전 로직은 0 3 2 1 순서로 돌아야 하므로 d = (d + 3) % 4

놓인 위치 예외 체크는 할 필요 없어보임

현재 위치 체크 -> 현재 위치에서 주위 네칸 체크 함수 -> true시 회전 로직 -> 회전방향 확인, 다음 루프 진입
체크시 모두 청소되었거나 범위 밖이면 -> 현재 x,y에서 dx[d] dy[d] 를 빼기 시도 -> 벽이면 break

#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> dx = {-1,0,1,0}, dy = {0,1,0,-1};

bool inArray(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m; 
}

bool haveVoid(int x, int y, vector<vector<bool>> &check){

    for(int i = 0; i < 4; ++ i){
        int gx = x, gy = y;
        gx += dx[i]; gy += dy[i];
        if(inArray(gx,gy) && check[gx][gy] == false){   // 범위 안이며, 청소가 안된 곳을 찾으면 
            return true;
        }    
    }

    return false;                                       // 그 외
}


int main(){
    int ans = 0;
    int x,y,d;
    cin >> n >> m;
    cin >> x >> y >> d;
    vector<vector<bool>> array(n, vector<bool>(m,false)); // false 로 초기화

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int input;
            cin >> input;
            if(input == 1)  array[i][j] = true;
        }
    }       // 입력 초기화

    while(1){
        int gx = x, gy = y;
        if(inArray(gx,gy)&& array[gx][gy] == false){ // 범위 안이며 현재 위치에서 청소가 가능하면
            array[gx][gy] = true;
            ans++;                  // 청소 횟수 증가
        }

        if(haveVoid(gx,gy,array)){  // 범위 안에 주변이 빈 곳이 있다면
            d = (d + 3) % 4;
            x += dx[d]; y += dy[d]; // 범위 밖이든 안이든 반시계 회전 후 전진 -> 다음 루프로
        }
        else{                       // 범위 밖이거나, 청소가 불가능하다면
            gx -= dx[d]; gy -= dy[d];

            if(!inArray(gx,gy)){    // 후진했을 때 벽이라면 종료
                break;
            }
            x = gx; y = gy;         // 벽이 아니라면 후퇴 후 다음 루프
        }
    }

    cout << ans;
    return 0;
}

*/