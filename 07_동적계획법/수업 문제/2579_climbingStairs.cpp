// 계단 오르기 - 실버3
/* 점화식 만들기
    : 현재 계단 위치에 오려면 이전 계단에서 오는 경우와 그 전 계단에서 오는 경우를 고려
    - 연속 3칸 금지 => 1칸 전에 온 경우는 그 전을 2칸 전에서 온 것으로 확정

DP[i] = max(DP[i-2], DP[i-3] + score[i-1]) + score[i] */
#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(const vector<int>& score, int n) {
    vector<int> dp(n+1, 0);
    // dp[i] : i번째 계단까지 왔을 때 점수의 최댓값

    //초기값
    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    // 점화식
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
        // dp[i - 3] + score[i - 1] : one step before
        // + score[i] : 현재 계단 점수 추가
    }

    return dp[n];
}


int main() {
    int n;
    cin >> n;
    vector<int> score(n+1, 0);
    // n+1로 설정하여 score[i]가 i번째 계단 금액이도록

    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }


    int answer = getMaxScore(score, n);
    cout << answer << "\n";

    return 0;
}