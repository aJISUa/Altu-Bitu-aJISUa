#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

ci solution(int n, int x, const vector<int>& vistor){
    int cnt_visit = 0;
    int cnt_period = 1;

    // 초기 윈도우 설정
    for(int i=0; i<x; i++){
        cnt_visit += vistor[i];
    }
    
    int max_visit = cnt_visit;

    // 슬라이딩 윈도우로 최대 방문자 수 계산
    for(int i=x; i<n; i++){
        // 윈도우 갱신
        cnt_visit -= vistor[i-x];
        cnt_visit += vistor[i];

        if(cnt_visit > max_visit){
            cnt_period = 1;
            max_visit = cnt_visit;
        } else if(cnt_visit == max_visit){
            cnt_period++;
        }
    }

    return {max_visit, cnt_period};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> vistor(n, 0);
    for(int i=0; i<n; i++){
        cin >> vistor[i];
    }

    ci answer = solution(n, x, vistor);

    if(answer.first == 0){
        cout << "SAD";
        return 0;
    }
    
    cout << answer.first << "\n" << answer.second;

    return 0;
}