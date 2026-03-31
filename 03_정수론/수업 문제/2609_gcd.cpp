#include <iostream>

using namespace std;

// 두 수가 주어졌을 때 가장 작은 수 기준으로 최대공약수 구하기(시간복잡도 O(n))
int getGcd(int a, int b) {
    // 최대공약수이므로 거꾸로 가는 로직(i 작아지는 방향) 사용
    for (int i = min(a,b); i > 0 ; i--) { 
    // i > 0 : 1일 때 까지
        if (a%i==0 && b%i == 0) {
            return i;
        }
    }
    // 우리는 결국 1로 return할 것을 알지만 컴퓨터는 모르므로
    return 1;
}

// 유클리드 호제법
int getGcdIter(int a, int b) {
    while(b!=0) { // while(b) 와 같음
        a%=b;
        swap(a,b);
    }
    return a;
}

// 재귀함수 이용
int getGcdRecur(int a, int b) {
    // 재귀함수에서 가장 중요한 것 : 종료 조건 - 무한루프 주의
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b,a%b); // swap

}


int main() {
    int a, b;
    cin >> a >> b;
    // 최대공약수
    //int gcd = getGcd(a,b);
    //int gcd = getGcdIter(a,b);
    int gcd = getGcdRecur(a,b);

    // 최소공배수
    int lcm = a * b / gcd;
    

    cout << gcd << "\n" << lcm;
}
