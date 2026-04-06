#include <iostream>

using namespace std;

int bruteforce(int n) {
    for (int i = 1; i < n; i++) {
        int sum = 0; // 분해합 결과를 담는 변수
        int temp = i; // 10으로 나누면서 각 자리 수를 더하기 위한 임시 변수

        while (temp > 0) {
            sum += temp % 10; // 일의 자리부터 각 자리 수를 더함
            temp /= 10; // 하다보면 0 되는 순간 종료
        }
        sum += i;
        if (sum == n) {
            return i; // i가 n의 생성자
        }
    }
    return 0; // 생성자가 없는 경우(문제 조건)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << bruteforce(n) << "\n";
    /* 다른 방식 출력
    int ans = bruteforce(n);
    cout << ans;
    */

    return 0;

}