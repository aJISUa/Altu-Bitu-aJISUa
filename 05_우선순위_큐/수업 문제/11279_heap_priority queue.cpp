/*#include <iostream>
#include <vector>

using namespace std;

// const로 크기 정해서 사용하면 더 효율적일 수 있지만, 인덱스 저장 필요해서

bool isEmpty(const vector<int> &heap) {
    return heap.size() == 1; // 인덱스 1부터 시작하기 때문에 size가 1이면 비어있는 것
}


void push(int x, vector<int> &heap) {
    int idx = heap.size();

    // 삽입
    heap.push_back(x);

    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        idx /= 2;
    }

    return;
}

int pop(vector<int> &heap) {
    // 마지막 원소를 루트 원소로
    int item = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back(); // pop 계속 하는 경우 보통 stack 사용, 여기서는 인덱스 접근 필요해서

    int parent = 1, child = 2; // 자식 인덱스 = 부모 인덱스 * 2
    int size = heap.size();

    
    while (child < size) { // 왼쪽은 확실히 존재
        // 1. 왼/오 비교
        if (child + 1 < size && heap[child] < heap[child + 1]) { // 오른쪽 자식이 존재하고, 오른쪽 자식이 왼쪽 자식보다 크면
            child++;
        }
        // 2. 둘 중 더 큰 자식이 나보다 클 때 바꿈
        if (heap[child] > heap[parent]) {
            swap(heap[child], heap[parent]);
            parent = child;
            child *= 2; // child = parent * 2;
        }
        else {
            break;
        }

    }

    return item;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> heap(1, 0); // 인덱스 1부터 시작하기 위해 0을 넣어줌
    
    while (n--) {
        cin >> x;

        switch (x) {
            case 0: // 삭제
                // 삭제할 때 주의) 힙이 비어있는 경우 판별한 뒤 계산
                if (isEmpty(heap)){
                    cout << pop(heap) << "\n";
                }
                else {
                    cout << "0\n";
                }
                
                break;
            default: // 삽입
                push(x, heap);
                break;
        }
    }

    return 0;
}*/

// 라이브러리 사용
#include <iostream>
#include <queue> // 우선순위 큐

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int> pq; // 우선순위 큐 사용 - 최대 힙이 기본
    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> min_pq; // 내림차순

    while (n--) {
        cin >> x;

        switch (x) {
            case 0: // 삭제
                // 삭제할 때 주의) 힙이 비어있는 경우 판별한 뒤 계산
                if (!pq.empty()){
                    cout << pq.top() << "\n";
                    // 최소 힙
                    cout << -pq.top() << "\n";
                    pq.pop();
                }
                else {
                    cout << "0\n";
                }
                
                break;
            default: // 삽입
                pq.push(x);
                // 최소 힙
                pq.push(-x); // 최대 힙으로 구현된 우선순위 큐에 음수로 삽입하여 최소 힙처럼 사용
                break;
        }
    }

    return 0;
}