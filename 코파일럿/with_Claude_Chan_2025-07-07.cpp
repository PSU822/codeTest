/*

무방향 그래프

재귀 탈출 조건 -> 스택에서 뺀 것들이 모두 방문한 노드일때 ans 늘리고

벡터로 그래프 구현 vector<int> graph
예시 )  [1] = 2
        [2] = 5
        [5] = 1
        [3] = 4
        [4] = 6


수도코드

stack, visited

그래프 1번부터 탐색, 방문하지 않은 정점이면 DFS 시작
정점 스택에 넣고 정점이 가리키는 장소 재귀
dfs 진행하다가 방문한 정점을 만나면
[visited 체크, 스택 빌때까지 pop. 
만약 하나라도 visited이 아니라면 해당하는 연결요소는 문제가 있으므로 ans 증가하지 않음.] << [] 안의 내용은 굳이 필요한가 싶어서 분리
ans ++


*/

#include<iostream>
#include<vector>

using namespace std;
int n, m;
int ans = 0;

void DFS(int node, vector<bool>& check, vector<vector<int>>& graph){
    check[node] = true;
    for(auto next : graph[node]){
        if(!check[next]) DFS(next, check, graph);
    }
}

int main(){
    cin >> n >> m;
    vector<bool> visited(n+1,false);
    vector<vector<int>> graph(n+1);

    for(int i = 0; i < m; ++i){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            DFS(i, visited, graph);
            ans++;
        }
    }

    cout<< ans;

    return 0;
}