// 여행 경로 - Lv.3
/*
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const string& current, 
         vector<vector<string>>& tickets, 
         vector<bool>& used, 
         vector<string>& path, 
         int n) {
    // 모든 항공권을 다 사용했으면 성공
    if (path.size() == n + 1) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        // 이미 사용한 항공권이거나, 출발지가 현재 위치가 아니면 스킵
        if (used[i] || tickets[i][0] != current) continue;
        
        used[i] = true;
        path.push_back(tickets[i][1]);
        
        if (dfs(tickets[i][1], tickets, used, path, n)) {
            return true;  // 경로를 찾았으면 즉시 종료
        }
        
        // 백트래킹
        used[i] = false;
        path.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳 순서 보장을 위해 정렬
    sort(tickets.begin(), tickets.end());
    
    int n = tickets.size();
    vector<bool> used(n, false);
    vector<string> path = {"ICN"};
    
    dfs("ICN", tickets, used, path, n);
    
    return path;
}