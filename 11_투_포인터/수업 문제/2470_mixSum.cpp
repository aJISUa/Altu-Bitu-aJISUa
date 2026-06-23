#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 2e9+1;

typedef pair<int, int> ci;

ci solution(int left, int right, const vector<int>& liquid){
    ci ans = {0,0};
    int sum = INF;

    while(left < right){
        int mix = liquid[left] + liquid[right];

        if(mix==0){
            return {liquid[left], liquid[right]};
        }

        if(abs(mix) < sum){
            sum = abs(mix);
            ans = {liquid[left], liquid[right]};
        }
        
        if(mix > 0){
            right--;
        } else {
            left++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> liquid(n, 0);
    for(int i=0; i<n; i++){
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end()); // 디폴트: 오름차순

    ci result = solution(0, n-1, liquid);
    cout << result.first << " " << result.second;

    return 0;
}