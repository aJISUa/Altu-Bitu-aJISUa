// 회사에 있는 사람 - 실버5
// set에 넣으면 자동으로 사전순 정렬

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    set<string> workers;

    string name, input;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> input; // 뛰어쓰기 기준으로 cin 사용 주의

        if (input == "enter")
        {
            workers.insert(name);
        }
        else
        {
            workers.erase(name);
        }
    }

    // 역순 출력
    // rbegin(), rend() : 역방향 반복자 => 거꾸로 순회와 동일
    for (auto iter = workers.rbegin(); iter != workers.rend(); iter++)
    {
        cout << *iter << '\n';
    }

    // workers에 있는 원소 하나씩 s에 저장 => 사전순으로 출력
    /*
    for (string s : workers)
    {
        cout << s << '\n';
    }
    */

    return 0;
}
