#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;
    vector<pair<int, int>> arr;
    cin >> n;
    arr.assign(n,{0,0});

    // 시간 입력: 끝나는 시간 기준으로 문제를 푸므로 편의성을 위패 끝나는 시간을 first로
    for(int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first; // 회의 시작시간, 끝시간
    }
    // 끝나는 시간을 오름차순으로 정렬
    sort(arr.begin(), arr.end());
    
    // 이전 회의가 끝나는 시간
    int finish_conference = 0;
    for(int i = 0; i < n; i++) {
        // 회의 시작시간이 이전 회의가 끝나는 시간보다 크거나 같으면
        if (arr[i].second >= finish_conference) {
            cnt++; // 회의 개수 증가
            finish_conference = arr[i].first; // 이전 회의가 끝나는 시간 갱신
        }
    }

    cout << cnt << "\n";

    return 0;
}