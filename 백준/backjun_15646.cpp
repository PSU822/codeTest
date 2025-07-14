// 백트래킹
#include <iostream>

using namespace std;

static int N, M;
static int ans[9];
static bool isVisit[9] = {false};

void BackTrack(int depth){
    if(depth == M){
        for(int i = 0; i < M; ++i) cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; ++i){
        if(!isVisit[i]){
            isVisit[i] = true;
            ans[depth] = i;
            BackTrack(depth + 1);
            isVisit[i] = false;
        }
    }
}

int main(){

    cin >> N >> M;

    BackTrack(0);

    return 0;

}
