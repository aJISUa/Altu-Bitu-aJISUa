// 퇴사 - 실버3
 /*
방법1) 완전 탐색 - 시간초과 
방법2) dp(Bottom-up)
 */
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

void dpBottomUp(vector<int> dp, vector<ii> li, int n) { // 1일차부터 시작
    // 모든 일자에 대해 반복
    for (int i = 0; i < n; i++) {
        // 만약 해당 일자에 상담한다고 가정할 때, 가장 빠른 다음 상담일자부터 반복
        for (int j = i + li[i].first; j <= n; j++) {
            dp[j] = max(dp[j], dp[i] + li[i].second);
            // dp[j] : j일에 얻을 수 있는 최대 이익
            // dp[i] + li[i].second : i일에 상담을 했을 때의 이익
        }
    }
    cout << dp[n] << "\n"; // n일에 얻을 수 있는 최대 이익 출력
}

// 역순
void dpTopDown(vector<int> dp, vector<ii> li, int n) { // N일차부터 시작
    if (n == 0) return; // 종료 조건

    for (int i = n - 1; i >= 0; i--) {
        // 퇴사일 넘어가면 상담 불가능
        if (i + li[i].first > n) {
            dp[i] = max(dp[i], dp[i + 1]); // 상담 불가능
        }

        // 상담을 하지 않았을 경우와 했을 경우의 최댓값
        dp[i] = max(dp[i+1], li[i].second + dp[i + li[i].first]);
    }

    cout << dp[0] << "\n"; // 0일에 얻을 수 있는 최대 이익 출력
}



int main() {
    int n, a, b;
    cin >> n;

    vector<ii> li;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        li.push_back(make_pair(a, b));
    }
    /*
    vector<ii> li(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> li[i].first >> li[i].second;
    }   
    */

    vector<int> dp(n+1, 0);
    dpBottomUp(dp, li, n);

    return 0;
}