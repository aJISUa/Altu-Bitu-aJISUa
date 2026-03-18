// 수 정렬하기 2 - 실버5
// int 범위 1억

#include <iostream>
#include <vector>

using namespace std;

vector<int> merged;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int pl = left, pr = mid + 1, idx = left; // 포인터

    while (pl <= mid && pr <= right) // 양쪽 모두 남은 원소 있을 때
    {
        if (arr[pl] < arr[pr]) // 왼쪽 원소가 더 작거나 같을 때
        {
            merged[idx++] = arr[pl++]; // 병합 결과 배열에 왼쪽 원소 추가, 왼쪽 포인터 이동
        }
        else // 오른쪽 원소가 더 작을 때
        {
            merged[idx++] = arr[pr++]; // 병합 결과 배열에 오른쪽 원소 추가, 오른쪽 포인터 이동
        }
    }

    while (pl <= mid) // 왼쪽 마지막 원소 남은 경우
    {
        merged[idx++] = arr[pl++];
    }
    while (pr <= right) // 오른쪽 마지막 원소 남은 경우
    {
        merged[idx++] = arr[pr++];
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = merged[i]; // 병합 결과 배열을 원본 배열로 복사
    }
}

void mergeSort(vector<int> &arr, int left, int right) // 재귀 사용
{                                                     // 가장 왼쪽, 오른쪽 인덱스
    if (left < right)                                 // 순서 변화 X => 원소가 2개 이상일 때
    {
        int mid = (left + right) / 2; // 중간 지점(c++ 정수 결과)

        mergeSort(arr, left, mid);      // 왼쪽 절반 정렬
        mergeSort(arr, mid + 1, right); // 오른쪽 절반 정렬

        merge(arr, left, mid, right); // 병합
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    merged.assign(n, 0); // 병합 결과 배열에 공간 할당(n개 칸 0으로 초기화)

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
