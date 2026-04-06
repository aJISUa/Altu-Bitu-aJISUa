#include <iostream>
#include <vector> // 난쟁이 키 하나씩 저장할 벡터
#include <algorithm> // sort() 함수(오름차순) 사용하기 위해

using namespace std;

const int CNT = 9; // 총 난쟁이 수

// 코드 작성할 때 입력 - 연산 - 출력 순서로 작성하는 것이 좋음

void select(vector<int> &arr) { // 주소를 넘겨주므로 반환 필요 X
    int sum = 0;
    for (int i = 0; i < CNT; i++) { // 전체 난쟁이 키 합
        sum += arr[i];
    }

    for (int i = 0; i < CNT - 1; i++) { // 첫 번째 고르기
        for (int k = i + 1; k < CNT; k++) { // 두 번째 고르기
            if (sum - arr[i] - arr[k] == 100) { // 고른 난쟁이 키 합이 100이면 정답
                // 원소 자체를 지우는 것이므로 큰 인덱스부터 지워야 함(작은 것부터 지우면 인덱스 밀려서 오류 발생)
                arr.erase(arr.begin() + k);
                arr.erase(arr.begin() + i);
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(CNT);
    for(int i = 0; i < CNT; i++) {
        cin >> arr[i];
    }

    select(arr); // 일곱 난쟁이 다 고름
    sort(arr.begin(), arr.end()); // 오름차순 정렬

    for (auto it : arr) {
        cout << it << "\n";
    }

    return 0;
}