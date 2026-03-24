#include <iostream>
// #include <vector>
#include <stack> // STL 사용하기 위해

// #define MAX_SIZE 10000 // 문제 제한 사항 - STL 사용시 필요 없음(자기가 알아서 조정함)

using namespace std;

// pop 시도할 때 스택이 비어있으면 오류 가능성 있으므로
// 사용 전에 스택 상태를 확인
// 빈 상태 아닐 경우에만 pop 가능하도록

int main()
{
    // 빠른 input 위해서
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*

    vector<int> stack(MAX_SIZE); // 스택 구현을 위한 벡터
    int top = -1;

    int n, x;
    string cmd;
    cin >> n;

    while (n--) {
        cin >> cmd; // 명령 입력

        if (cmd == "push") {
            cin >> x;
            stack[++top] = x;
        } else if (cmd == "pop") {
            if(top == -1) { // 스택 비어있는지 확인
                cout << "-1\n";
            } else {
                cout << stack[top--] << "\n";
            }
        } else if (cmd == "size") {
            cout << top + 1 << "\n";
        } else if (cmd == "empty") {
            if (top == -1) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (cmd == "top") {
            cout << stack[top] << "\n";
        }
    }*/

    // STL 사용

    stack<int> s;
    int top = -1;

    int n, x;
    string cmd;
    cin >> n;

    while (n--)
    {
        cin >> cmd; // 명령 입력

        if (cmd == "push")
        {
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop")
        {
            if (s.empty())
            { // 스택 비어있는지 확인
                cout << "-1\n";
            }
            else
            {
                cout << s.top() << "\n"; // pop은 반환해주지 않으므로 top으로 출력 후
                s.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << s.size() << "\n";
        }
        else if (cmd == "empty")
        {
            if (s.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (cmd == "top")
        {
            cout << s.top() << "\n";
        }
    }

    return 0;
}
