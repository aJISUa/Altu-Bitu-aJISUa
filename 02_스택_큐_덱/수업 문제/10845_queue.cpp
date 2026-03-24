#include <iostream>
// #include <vector>
#include <queue> // STL 사용하기 위해

// #define MAX_SIZE 10000 // 문제 제한 사항

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    vector<int> queue(MAX_SIZE);
    int front = 0, rear = 0; // 굳이 0일 필요 없고 front와 rear가 같으면 상관 없음

    string cmd;
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> x;
            // rear 값이 배열 크기(MAX_SIZE)를 넘어가지 않도록 % 연산 사용
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = x;
        }
        else if (cmd == "pop")
        {
            if (front == rear) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else // pop할 원소 있을 때
            {
                // front가 1 증가시키고 배열 크기 넘지 않도록
                front = (front + 1) % MAX_SIZE;
                cout << queue[front] << "\n";
            }
        }
        else if (cmd == "size")
        {
            // 큐의 크기 계산
            cout << (rear - front) << "\n";
        }
        else if (cmd == "empty")
        {
            cout << (front == rear) << "\n"; // True/False -> 1/0으로 자동 출력
        }
        else if (cmd == "front") // front는 맨 원소 바로 앞 가리킴
        {
            if (front == rear) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else
            {
                cout << queue[(front + 1) % MAX_SIZE] << "\n";
            }
        }
        else if (cmd == "back")
        {
            if (front == rear) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else
            {
                cout << queue[rear] << "\n"; // rear이 바로 가리키므로            }
        }
    }*/

    queue<int> q;

    string cmd;
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop")
        {
            if (q.empty()) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else // pop할 원소 있을 때
            {
                // 큐에서 pop은 반환값이 없으므로 먼저 출력
                cout << q.front() << "\n"; // 큐는 항상 front에서 출력, rear에서 입력
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            // 큐의 크기 계산
            cout << q.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << q.empty() << "\n"; // True/False -> 1/0으로 자동 출력
        }
        else if (cmd == "front") // front는 맨 원소 바로 앞 가리킴
        {
            if (q.empty()) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if (cmd == "back")
        {
            if (q.empty()) // 큐가 비어있는 경우
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.back() << "\n"; // rear이 바로 가리키므로            }
            }
        }
    }

    return 0;
}