#include <iostream>

/* 입력 조건 : 10^18 = 약 2^60

n은 int로 표현해도 괜찮지만
m은 long long으로 표현해야 함

*/

using namespace std;

typedef long long ll;
const int MAX = 60;

// x, y 반환할 거니까 pair로 묶기
pair<int,int> getXY(ll m) {
    int x, y;

    // m = 2^i
    // m = 2^(i-1) + 2^(i-1)
    // => x = y = i-1
    for (int i = 1; i < MAX; i++) { // MAX가 한계 지수를 의미
        if (m == ((ll)1 << i)) { // left shift
            return {i-1, i-1};
        }
    }


    // 문제조건에 항상 경우가 존재한다고 했으므로 로직 이렇게 작성한 것. 아니라면 안 됨.
    for (x = 0; x < MAX; x++) {
        if (m & ((ll)1 << x)) { // and 연산으로 비트가 1인지 확인 => 하나라도 1 나오면 >0 : if문 true
            m -= (ll)1 << x; // m에서 2^x 빼기
            break;
        }
    }
    for(y = x + 1; y < MAX; y++) { // 똑같은 작업 피하기 위해 x보다 크도록 설정
        if (m & ((ll)1 << y)) {
            break;
        }
    }
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while(n--) {
        ll m;
        cin >> m;

        pair<int,int> ans = getXY(m);
        cout << ans.first << " " << ans.second << "\n"; // pair로 묶어서 반환한 x, y 출력
    }

    return 0;
}