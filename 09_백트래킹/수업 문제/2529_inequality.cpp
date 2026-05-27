// 부등호
#include <iostream>

using namespace std;

const int DIGIT_SIZE = 10;
string answer[2] = {"0000000000", "9999999999"}; // 최대, 최소

// idx: 현재 채워야 할 칸의 인덱스
void backtracking(int idx, int k, vector<bool> is_ascending, vector<int>& sequence, vector<bool>& is_used) {
    if (idx == k + 2) {
        string tmp ="";
        for (int i = 1; i <= k + 1; i++) { // 맨 앞은 -1로 생각하기, idx-1과 비교할 때 편하게 하기 위해
             tmp += to_string(sequence[i]);
        }
        /*for (auto x : sequence) {
            tmp += to_string(x);
        }*/
        answer[0] = max(answer[1], tmp);
        answer[1] = min(answer[0], tmp);
        return;
    }

    int curr_num = sequence[idx - 1]; // 이전에 채운 수
    while(true) {
        if (is_ascending[idx]) { // '<'면
            curr_num++;
        } else { // '>'면
            curr_num--;
        }

        if (curr_num < 0 || curr_num >= DIGIT_SIZE) { // 0-9 범위 벗어나면 종료
            break;
        }
        if (is_used[curr_num]) { // 이미 사용된 수면 패스
            continue;
        }
        sequence[idx] = curr_num;
        is_used[curr_num] = true;
        backtracking(idx + 1, k, is_ascending, sequence, is_used);
        is_used[curr_num] = false; // 다시 돌려놓기
    }

    /*
    // idx에 수를 채울 차례 - 뭘 넣을지 모르니 다 넣어봐야 함
    //for (int i = 1; i < n; i++) { // 1-n X, 조건에 맞는 수를 검사
    for (int i = 0; i <= 9; i++) { // 0-9 O, 조건에 맞는 수를 검사
        // i가 이미 사용된 수인지 체크
        if (is_used[i]) {
            continue;
        }
        
        sequence[idx] = i;
        is_used[i] = true;
        backtracking(idx + 1, n, m, sequence, is_used);
        is_used[i] = false;
    }
*/
}

int main() {
    int k;
    cin >> k;

    char x; // 부등호 입력받을 때 사용할 변수
    //vector<bool> is_ascending(k); // 오름차순
    vector<bool> is_ascending(k+1); // 맨 앞을 -1로 생각해서, idx-1과 비교할 때 편하게 하기 위해
    is_ascending[0] = true; // 맨 앞은 항상 '<'로 생각하기
    for (int i = 0; i < k; i++) {
        cin >> x;
        is_ascending[i] = (x == '<'); // '<'면 true, '>'면 false
    }


    vector<int> sequence(k + 2);
    sequence[0] = -1; // 맨 앞을 -1로 생각하기, 0-9보다 작은 수이므로 항상 '<' 조건 만족
    vector<bool> is_used(DIGIT_SIZE, false); // 0-9

    for (int i = 0; i< DIGIT_SIZE; i++) { // 0-9 O, 조건에 맞는 수를 검사
        sequence[0] = i;
        is_used[i] = true;
        backtracking(1, k, is_ascending, sequence, is_used); // idx 1부터 시작, 맨 앞은 이미 채웠으므로
        is_used[i] = false;
    }
}