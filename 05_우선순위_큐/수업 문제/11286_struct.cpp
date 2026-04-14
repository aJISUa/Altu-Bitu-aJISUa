// 우선순위 직접 구현
// 정렬 때처럼 비교구조체 - 직접 작성

#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    /*bool operator()(const int &x1, const int &x2) { // 오름차순
        return x1 < x2;
        // heap 만들 때 최대가 기본이므로
        // less를 구현해야 함 => 조건에 걸려야 swap

        // 헷갈리면 만족하는 조건 사용하기
        // const int &child, const int &parent
        // 최대힙) parent > child
        // 최소힙) parent < child

    }*/
    bool operator()(const int &child, const int &parent) {
        if (abs(child) != abs(parent)) {
            return abs(parent) < abs(child); // 절댓값 작은 걸 root
        }
        //else 대신 return
        return parent < child;
    }
    /*bool operator()(const int &parent, const int &child) {
        // swap될 때 반환하는 걸 적기
        if (abs(child) != abs(parent)) {
            return abs(parent) > abs(child);
        }
        //else 대신 return
        return parent > child;
    }*/


   // 배열의 경우 left/right
   /*bool operator()(const int &left, const int &right) {
    }*/
};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;

    while (n--) {
        cin >> x;
        switch (x) {
            case 0: // 삭제
                // 삭제할 때 주의) 힙이 비어있는 경우 판별한 뒤 계산
                if (!pq.empty()){
                    cout << pq.top() << "\n";
                    // 최소 힙
                    // cout << -pq.top() << "\n";
                    pq.pop();
                }
                else {
                    cout << "0\n";
                }
                
                break;
            default: // 삽입
                pq.push(x);
                // 최소 힙
                // pq.push(-x); // 최대 힙으로 구현된 우선순위 큐에 음수로 삽입하여 최소 힙처럼 사용
                break;
        }
    }

}