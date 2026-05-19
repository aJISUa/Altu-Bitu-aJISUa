// 게임 맵 최단거리 - Lv.2
/*
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임
따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리

- 제한사항
maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.
*/
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();        // 행 개수
    int m = maps[0].size();     // 열 개수
    
    // 거리 저장 배열 (방문 여부도 같이 체크)
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    // 상하좌우 방향
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // BFS 시작
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;  // 시작점은 1칸으로 카운트
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // 도착점에 도달하면 종료 가능 (BFS이므로 최단거리 보장)
        if (x == n - 1 && y == m - 1) {
            return dist[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽이거나 이미 방문한 곳이면 스킵
            if (maps[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    // 도달 못한 경우
    return -1;
}