// 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 인접한 두 공유기 사이의 거리가 dist가 되도록 공유기를 설치했을 때, 공유기의 개수
int cntRouters(const vector<int> &house, int dist) {
    int count = 1; // 첫 번째 집에는 무조건 공유기를 설치
    int cur = house[0]; // 현재 공유기가 설치된 집의 위치

    for (int i = 1; i < house.size(); i++) {
        if (house[i] - cur >= dist) { // 현재 집과 이전 집 사이의 거리가 dist 이상일 때
            count++; // 공유기 설치
            cur = house[i]; // 현재 공유기 위치 업데이트
        }
    }
    return count;
}
// target 개의 공유기를 설치 가능한 최소 인접 거리의 최댓값(upper bound 탐색)
int binarySearch(const vector<int> &house, int target) {
    int left = 1; // 최소 거리
    int right = house[house.size() - 1] - house[0]; // 최대 거리

    while (left <= right) {
        int mid = (left + right) / 2; // 공유기 사이의 간격
        int cnt = cntRouters(house, mid); // mid 간격으로 설치할 수 있는 공유기 수

        if (cnt >= target) { // 필요한 공유기 수를 만족하면 간격을 늘려봄
            left = mid + 1;
        } else { // 그렇지 않으면 간격을 줄여봄
            right = mid - 1;
        }
    }

    return left - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> house(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    cout << binarySearch(house, c) << "\n";

    return 0;
}