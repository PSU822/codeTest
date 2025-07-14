/*
미로 n,m
1은 길, 0은 벽
미로 정보 받는 2차원 벡터 하나
백트래킹용 큐 하나
DFS 함수, 상하좌우 움직임용 dx,dy 벡터

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<pair<int,int>> path;
vector<int> dx = {-1,1,0,0}, dy = {0,0,1,-1};   // 상 하 좌 우

bool inRange(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool DFS(int x, int y, vector<vector<bool>>& visited, vector<string>& maze){
    if(x == n - 1 && y == m - 1){                       // 목표 도달시
        path.push_back({x,y});                          // path에 현재 마지막 경로 집어넣고
        for(int i = 0; i < path.size(); ++i){           // 출력
            cout << '(' << path[i].first + 1 << ',' << path[i].second + 1<< ')';
            if(i < path.size() - 1) cout << " -> ";     // 다음 항목이 없을 때 까지
            }
            cout << '\n';
            return true;
    }

    path.push_back({x,y});                              // 현재 위치 스택에 저장
    visited[x][y] = true;                               // 방문
    
    for(int i = 0; i < 4; ++i){                         // 4방향 탐색
        int cx = x, cy = y;
        cx += dx[i]; cy += dy[i];
        if(inRange(cx,cy) && maze[cx][cy] == '1' && !visited[cx][cy]){      // 유효한 이동
            if(DFS(cx,cy,visited,maze)) return true;                        // DFS -> (만일 깊게 들어가서 true 반환시 재귀 구조이므로 true 연쇄 발생)
        }
    }
    path.pop_back();                                                             // 현재의 경로에서 찾지 못 했을 경우
    visited[x][y] = false;                                                  // 백트래킹
    return false;                                                           // 첫 함수로 돌아와서도 경로를 찾지 못 했을 경우에 도달
}

int main(){
    cin >> n >> m;
    vector<string> maze(n);
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    for(int i = 0; i < n; ++i){
        cin >> maze[i];
    }

    if(maze[0][0] == '0' || !DFS(0,0,visited,maze)) cout << "No Path" << '\n';

    return 0;
}
