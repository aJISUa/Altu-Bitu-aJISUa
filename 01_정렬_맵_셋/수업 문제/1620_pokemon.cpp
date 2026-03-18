// 나는야 포켓몬 마스터 이다솜 - 실버4
// 번호 - 이름 => map 사용
/* 어떤 자료구조 사용? 고민 중요 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // 속도 향상을 위한 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    map<string, int> name; // 이름 넣으면 value로 도감 번호 나옴
    map<int, string> num;  // 도감 번호 넣으면 이름 나옴
    string input;

    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        name[input] = i;
        num[i] = input;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (isdigit(input[0])) // 숫자로 시작하는지 확인 => 도감 번호 입력
        {
            cout << num[stoi(input)] << '\n'; // stoi: string to int
        }
        else // 이름 입력
        {
            cout << name[input] << '\n';
        }
    }
}