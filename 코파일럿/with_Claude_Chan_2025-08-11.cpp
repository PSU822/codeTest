/*
문제: 최소 신장 트리 (크루스칭 알고리즘)
N개의 도시를 최소 비용으로 모든 도시가 연결되도록 도로를 건설하세요.

입력:
4 5          // N=4개 도시, M=5개 도로 후보
1 2 1        // 1번-2번 도시 연결, 비용 1
1 3 4        // 1번-3번 도시 연결, 비용 4  
2 3 2        // 2번-3번 도시 연결, 비용 2
2 4 5        // 2번-4번 도시 연결, 비용 5
3 4 3        // 3번-4번 도시 연결, 비용 3

출력:
6            // 최소 비용 (1+2+3=6)

설명:
선택된 간선: (1-2, 비용1) + (2-3, 비용2) + (3-4, 비용3)
모든 도시가 연결되고 총 비용이 최소!
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n,m;

typedef struct Edge 
{
    int u, v, cost;
    bool operator<(const Edge& another){
        return cost < another.cost;
    }
} Edge;

class UnionFind{
    private:
        vector<int> parent;
        
    public :

        void Init(int n){
            parent.resize(n);
            for(int i = 0; i < n; ++i) parent[i] = i;
        }
        
        int Find(int x){
            if(parent[x] == x) return x;
            return parent[x] = Find(parent[x]);
        }

        void Union(int x, int y){
            int rootX = Find(x);
            int rootY = Find(y);
            if(rootX != rootY) parent[rootX] = rootY;
        }
};

int main(){
    cin >> n >> m;
    UnionFind uf;
    uf.Init(n);

    vector<Edge> edges(m);

    for(int i = 0; i < m; ++i){
        int u, v, cost;
        cin >> u >> v >> cost;

        edges[i] = {u-1,v-1,cost};
    }

    sort(edges.begin(), edges.end());

    int currNode = 1, totalCost = 0;

    for(auto& sorted : edges){
        if(uf.Find(sorted.u) != uf.Find(sorted.v)){
            uf.Union(sorted.u, sorted.v);
            totalCost += sorted.cost;

            if(totalCost == n-1) break;  // 최적화
        }
    }

    cout << totalCost;
}