#include <iostream>
#include <vector>

using namespace std;

// 누적합 만드는 함수
bool calSum(int n, vector<int>& sum){
    for(int i=1; i<=n; i++){
        sum[i] += sum[i-1];
    }
    return true;
}

int getSum(int i, int j, const vector<int>& sum){
    return sum[j] - sum[i-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, i, j;
    cin >> n >> m;
    vector<int> sum(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> sum[i];
    }
    calSum(n, sum);

    while(m--){
        cin >> i >> j;
        cout << getSum(i, j, sum) << "\n";
    }

    return 0;
    
}