// 수 정렬하기 - 브론즈1
// C++ : 1초 연산 10억번 가능

#include <iostream>
#include <vector>

#include <algorithm> // swap 함수 사용 위해

using namespace std;

void bubbleSort(vector<int> &arr) // 메모리 그대로 가져오면 시간 오래 걸리므로 & 주소 사용
{                                 // 수정 불가 키워드 : const
    int len = arr.size();

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++) // 오른쪽 자동 정렬 개수 = i
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // bubbleSort(arr);
    // C++ STL sort 함수 사용
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
