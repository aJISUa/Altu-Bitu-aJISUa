// 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int> &arr) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
            mid = (left + right) / 2; // 중앙값
            if (arr[mid] == key) return 1; // key값이 배열의 중앙값과 같을 때
            else if (arr[mid] > key) right = mid - 1;//왼쪽 절반
            else left = mid + 1;//오른쪽 절반
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, key;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    while (m--) {
        cin >> key;
        cout << binarySearch(n, key, arr) << "\n";
    }

    return 0;
}