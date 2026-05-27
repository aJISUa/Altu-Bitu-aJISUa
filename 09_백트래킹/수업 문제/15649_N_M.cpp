// N과 M
#include <iostream>

using namespace std;

// idx: 현재 채워야 할 칸의 인덱스
void backtracking(int idx, int n, int m, vector<int>& sequence, vector<bool>& is_used) {
    if (idx == m) {
        for (auto x : sequence) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    // idx에 수를 채울 차례 - 뭘 넣을지 모르니 다 넣어봐야 함
    for (int i = 1; i < n; i++) {
        // i가 이미 사용된 수인지 체크
        if (is_used[i]) {
            continue;
        }
        
        sequence[idx] = i;
        is_used[i] = true;
        backtracking(idx + 1, n, m, sequence, is_used);
        is_used[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> sequence(m);
    vector<bool> is_used(n + 1, false);

    backtracking(0, n, m, sequence, is_used);
}