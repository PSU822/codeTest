/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 클쨩이 낸 워밍업.


📝 문제1: 두 정수 A, B를 입력받아 A+B를 출력하는 프로그램을 작성하세요.

입력:
3 5

출력:
8

풀이과정 : 그냥 cin으로 입력받고 더하는 cout 끝! 변수 늘면 별로야~

int main(){
    int a,b;
    cin >> a >> b;

    cout << a+b;
    
    return 0;
}
*/

/* 
📝 문제2: N개의 정수가 주어질 때, 이 중에서 최댓값과 최솟값을 구하는 프로그램을 작성하세요.

입력:
5
1 3 5 2 4

출력:
5 1

설명:
- 첫 번째 줄: 정수의 개수 N
- 두 번째 줄: N개의 정수
- 출력: 최댓값 최솟값 (공백으로 구분)

풀이 과정 : 테스트 케이스 N, 그리고 N개의 입력을 받을 벡터 하나.(배열로 해도 되지만, 있는 컨테이너 쓰자구)
범위 계산 로직은 필요없어 보이니 생략!
sort 연산으로 맨 앞값과 뒷 값을 써도 되지만.. elementMax Min을 써볼까?

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;

    vector<int> inputs(n);
    for(int i = 0; i < n; ++i){
        cin >> inputs[i];
    }

    sort(inputs.begin(),inputs.end(), cmp);
    auto max_val = inputs.front();
    auto min_val = inputs.end();
    연습겸 cmp 내림차순으로 만들기.
    

    auto max_val = *max_element(inputs.begin(),inputs.end());
    auto min_val = *min_element(inputs.begin(),inputs.end()); 

    cout << max_val << " " << min_val;        

    system("pause");
    return 0;
}

*/