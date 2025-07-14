/*
n,m의 미로, 미로에서 1은 길, 0은 벽
상,하,좌,우로 이동 (dx,dy)
범위 내부인지, 길인지 벽인지 구분해야함

나아갈 수 있는 방향 + 방문했던 곳은 가지않음

의사코드
input n,m
matrix[n][m]
input matrix
visited[n][m] = {false}

int curr_x = 0, curr_y = 0
dx{ -1, 0, 1, 0 }, dy{ 0, 1, 0, -1 } 
queue<pair<int,int>> prev

bool isRange(int x, int y)
    return x >= 0 && y >= 0 && x < n && y && m

ans = 0
while(1)
    if(matrix[curr_x][curr_y] == 1 && !visited[curr_x][curr_y])
        ans++
        visited[curr_x][curr_y] = true
    
    bool dead_end = true

    for(i = 0, < 4 ++i)
        int gx = curr_x, gy = curr+y
        gx += dx[i], gy += dy[i]
        if(isRange(gx,gy) && !visited[gx][gy] && matrix[gx][gy] == 1)
            prev.push(curr_x,curr_y)
            curr_x = gx, curr_y = gy
            dead_end = false
            break;

    if(curr_x == n - 1 && curr_y == m - 1)
        ans++
        break

    if(dead_end && !prev.empty())
        curr_x = prev.front().first
        curr_y = prev.front().second
        ans--
    else if(dead_end && prev.empty())
        break

        
print ans // DFS 백트래킹

queue<pair<int,int>> pos
vector<vector<int>> dist(n(m,0))

pos.push({0,0})
dist[0][0] = 1
int x,y

while(!pos.empty())
    x = pos.front().first, y = pos.front().second
    pos.pop 

    for(i = 0, < 4 ++i)
        int gx = x + dx[i], gy = y + dy[i]
        if(inRange(gx,gy) && matrix[gx][gy] == 1 && dist[gx][gy] == 0)
            dist[gx][gy] = dist[x][y] + 1
            pos.push({gx,gy})    

print dist[n-1][m-1]
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m;
int x, y;

bool inRange(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
vector<int> dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };

int main(){
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    vector<vector<int>> dist(n,vector<int>(m));
    queue<pair<int,int>> pos;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
        }
    }

    pos.push({0,0});
    dist[0][0] = 1;
    while(!pos.empty()){
        x = pos.front().first, y = pos.front().second;
        pos.pop();

        for(int i = 0; i < 4; ++i){
            int gx = x + dx[i], gy = y + dy[i];
            if(inRange(gx,gy) && matrix[gx][gy] == 1 && dist[gx][gy] == 0){
                dist[gx][gy] = dist[x][y] + 1;
                pos.push({gx,gy});
            }
        }
    }

    cout << dist[n - 1][m - 1];
}