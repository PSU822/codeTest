/*

DFS 탐색의 베이스를 따르되, 내부 로직을 추가하는 느낌
의사코드

n,m
ans = 0
vector<vector<int>> 그래프(n)
vector<bool> 방문(n,false)

for(정점개수)
    그래프[u].pushback(v)
    그래프[v].pushback(u)

DFS(이전 번호, 현재 번호, 그래프, 방문)
    방문[현재번호] = true
    for(다음번호 : 그래프[현재번호])
        if(다음번호 == 부모) 스킵
        if(방문[다음노드]) return true
        DFS(현재 번호, 다음번호, 그래프, 방문)
    return false

for(노드개수)
    if(DFS) ans++

ans 출력
*/

#include<iostream>
#include<vector>

using namespace std;

int n,m;
int ans = 0;

bool DFS(int prev, int curr, vector<vector<int>>& graph, vector<bool>& visited){
    visited[curr] = true;
    for(auto next : graph[curr]){
        if(next == prev) continue;
        if(visited[next]) return true;
        if(DFS(curr, next, graph, visited)) return true;
    }
    return false;
}
int main(){
    
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 0; i < m; ++i){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool hasCycle = false;

    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            if(DFS(-1, i, graph, visited)){
                hasCycle = true;
                break;
            }
        }
    }
    cout << (hasCycle ? 1 : 0);
    return 0;
}