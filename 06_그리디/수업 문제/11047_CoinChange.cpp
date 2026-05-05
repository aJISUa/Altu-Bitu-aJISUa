#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int cnt = 0; // int n, k, cnt = 0; 으로 선언 가능
    cin >> n >> k;
    vector<int> A(n,0);

    // 입력받은 동전의 가치 저장
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 가장 큰 동전(끝)부터 k를 나누면서 필요한 동전의 개수 계산
    while(n--) {
        cnt += k / A[n]; // 필요한 동전의 개수 계산
        k %= A[n]; // 남은 금액 계산
    }

    cout << cnt << "\n";
    return 0;
}