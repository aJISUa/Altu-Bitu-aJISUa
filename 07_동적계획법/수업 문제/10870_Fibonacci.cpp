// 피보나치 수 5 - 브론즈2
/* n 범위(20 이하) 작으므로 재귀함수 가능하지만
사용 불가 경우 존재 - 시간 초과
: 같은 함수 여러 번 호출 -> 같은 값 여러 번 계산 */
// => Menmoization - 동적계획법으로 해결
//    DP 종류 - Top-down vs Bottom-up[속도 빠름]

/* DP 배열 선언 -> 인덱스에 맞춰 계산 값 저장 */
#include <iostream>

using namespace std;

int DP[21]; // DP 배열 선언

int Fibonacci(int n) {
    if (n == 0) return 0; // 초기값
    else if (n == 1) return 1; // 초기값
    else if (DP[n] != 0) return DP[n]; // 이미 계산된 값이 있으면 반환
    else return DP[n] = Fibonacci(n - 1) + Fibonacci(n - 2); // 계산 후 저장
}