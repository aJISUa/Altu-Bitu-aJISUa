#include <iostream>
#include <vector>

#define MAX_SIZE 10000 // 문제 제한 사항

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> deque(MAX_SIZE);
    int front = 0, back = 0; // rear 대신 back으로 사용(문제 함수명에 따라)

    string cmd;
    int x;

    while (n--)
    {
        cin >> cmd;

        if(cmd == "push_front")
        {
            cin >> x;
            // 큐의 구현 push와 마찬가지로
            // 벡터 내 인덱스로 보장하기 위해 나머지 연산
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            deque[front] = x;
        }
        else if (cmd == "push_back")
        {
            cin >> x;
            deque[back] = x; // 덱에서 back은 맨 뒤 원소 바로 뒤를 가리키므로
            back = (back + 1) % MAX_SIZE; // 증가시킨 back이 배열 크기 넘지 않도록 나머지 연산
        }
        else if (cmd == "pop_front") // 큐의 pop 연산과 마찬가지로
        {// 덱이 비어있는 경우 확인 필요
        // 덱은 큐의 없는 연산 추가한다는 생각으로 구현하면 됨
            if (front == back)
            {
                cout << "-1\n";
            }
            else // pop할 원소 있을 때
            {// front가 가장 앞 원소 가리키므로
                cout << deque[front] << "\n"; // front 출력 후
                front = (front - 1) % MAX_SIZE; // front 이동
                // push의 +1과 달리 -1
            }
        }
        else if (cmd == "pop_back")
        {
            if (front == back) // 덱이 비어있는 경우
            {
                cout << "-1\n";
            }
            else
            {
                back = (back - 1 + MAX_SIZE) % MAX_SIZE; // back은 맨 뒤 원소 바로 뒤 가리키므로 이동 후
                cout << deque[back] << "\n"; // back 출력
            }
        }
        else if (cmd == "size") // 덱에 든 정수 개수 반환
        {
            cout << (front + MAX_SIZE - back) << "\n"; // 배열 구조
        }
        else if (cmd == "empty")
        {
            cout << (front == back) << "\n"; // True/False bool 값 반환
        }
        else if (cmd == "front") // front는 가장 앞 원소 출력
        
        {// 원소 접근 시 배열(자료구조) 비어있는지 확인 필수
            if (front == back) // 덱이 비어있는 경우
            {
                cout << "-1\n";
            }
            else // 이미 front가 맨 앞 원소 가리킴
            {
                cout << deque[front] << "\n";
            }
        }
        else if (cmd == "back")
        {
            if (front == back) // 덱이 비어있는 경우
            {
                cout << "-1\n";
            }
            else // back은 가장 뒤 원소 바로 뒤 가리키므로
            {
                cout << deque[(back - 1) % MAX_SIZE] << "\n"; // vector 크기 내 index 범위 지키기 위해
            }
        }
    }

    return 0;
}
