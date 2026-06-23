// 숫자 카드2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(int left, int right, int target, vector<int> &arr) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) {
            right = mid - 1; // 중간값이 타겟보다 크거나 같을 때
        } else {
            left = mid + 1; // 중간값이 타겟보다 작을 때
        }
    }
    return left;
}

int upperBound(int left, int right, int target, vector<int> &arr) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, input;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // 이분탐색 전제조건: 정렬된 배열

    cin >> m;
    while (m--) {
        cin >> input;
        cout << upperBound(0, n-1, input, arr) - lowerBound(0, n-1, input, arr) << " ";
    }

    return 0;
}