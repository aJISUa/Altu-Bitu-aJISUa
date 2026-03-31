#include <iostream>
#include <vector>

using namespace std;

int findPrime(int n, int k) {
    int cnt = 0;
    vector<bool> is_prime(n+1, true); // 소수 여부 저장할 벡터

    /* depth 너무 깊음 - break, continue 사용해 줄여보자
    // 제곱근 n으로 가능하지만 문제에서 n까지 언급해서
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {// true : 아직 지우지 않은 수
            for(int j = i; j<= n; j+=i ) { // i 배수들 탐색
                if (is_prime[i]) {
                    is_prime[i] = false;

                    if(++cnt==k) {
                        return j;
                    }
                }
            }
        }
    }
    */
   for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) {// 이미 지워진 수이면 탐색 X
            continue;
        }


        for(int j = i; j<= n; j+=i ) { // i 배수들 탐색
            if (!is_prime[j]) { // 이미 지워진 수이면 탐색 X
                continue;
            }
            
            is_prime[j] = false;

            if(++cnt==k) {
                return j;
            }
        }
    }

    return -1;
}



int main() {
    int n, k;
    cin >> n >> k;

    cout << findPrime(n,k) << "\n";
}