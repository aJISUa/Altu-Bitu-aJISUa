// 추월 - 실버1
// 차 번호 부여해 간단하게

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int calcCar(const vector<int> &car_after)
{
    int len = car_after.size();
    int ans = 0;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (car_after[i] > car_after[j]) // 앞 차 번호가 뒤 차 번호보다 클 때 => 추월
            {
                ans++;
                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    string input;
    map<string, int> car_num; // 차 이름 - 번호 저장

    vector<int> car_after;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        car_num[input] = i; // 번호 부여
    }

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        car_after.push_back(car_num[input]); // 번호로 바꿔서 저장
    }

    cout << calcCar(car_after);

    return 0;
}
