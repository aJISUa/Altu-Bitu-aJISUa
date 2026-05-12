// 가장 긴 증가하는 부분 수열4 - 골드4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n, 0);

    int len = 0; // 지금까지 계산한 부분 수열의 최대 길이
    int tmp = 0; // 현재 부분 수열의 길이
    int max_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) { // 문제 조건 충족시
                len = max(len, dp[j]);
            }
        }

        dp[i] = len + 1; // i번째 요소 포함

        if (tmp < dp[i]) { // 최대 길이 갱신
            max_idx = i;
            tmp = dp[i];
        }
    }
    // --- 메인 dp 완성 ---

    vector<int> answer; // 가장 긴 증가하는 부분 수열 저장할 벡터

    for (int i = max_idx; i >= 0; i--) {
        if (dp[i] == tmp) { // 최대 길이인 요소들만 출력
            answer.push_back(a[i]);
            tmp--; // 다음 최대 길이로 갱신
            // tmp 하나씩 줄여가면서 추적
        }
    }

    return 0;
}