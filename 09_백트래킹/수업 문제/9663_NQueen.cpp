// N-Queen
#include <iostream>

using namespace std;

int answer = 0;

void backtracking(int row_idx, int n, vector<bool>& check_col, vector<bool>& check_left, vector<bool>& check_right) {
    if (row_idx == n) {
        answer++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (check_col[col] || check_left[row_idx + col] || check_right[row_idx - col + n - 1]) {
            continue;
        }
        check_col[col] = true;
        check_left[row_idx + col] = true;
        check_right[row_idx - col + n - 1] = true;

        backtracking(row_idx + 1, n, check_col, check_left, check_right);

        check_col[col] = false;
        check_left[row_idx + col] = false;
        check_right[row_idx - col + n - 1] = false;
    }
}

/* 전역변수 사용 x
int backtracking(int row_idx, int n, vector<bool>& check_col, vector<bool>& check_left, vector<bool>& check_right) {
    if (row_idx == n) {
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (check_col[col] || check_left[row_idx + col] || check_right[row_idx - col + n - 1]) {
            continue;
        }
        check_col[col] = true;
        check_left[row_idx + col] = true;
        check_right[row_idx - col + n - 1] = true;

        count += backtracking(row_idx + 1, n, check_col, check_left, check_right); // 계산 횟수 누적 <- return 1 이므로

        check_col[col] = false;
        check_left[row_idx + col] = false;
        check_right[row_idx - col + n - 1] = false;
    }
    return count;
}
*/

int main() {
    int n;
    cin >> n;

    vector<bool> check_col(n);
    vector<bool> check_left(2 * n - 1);
    vector<bool> check_right(2 * n - 1);

    backtracking(0, n, check_col, check_left, check_right);
    cout << answer;
} 