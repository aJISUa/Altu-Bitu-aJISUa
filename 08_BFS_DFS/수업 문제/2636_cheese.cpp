// 인접 행렬 이용 - bfs 직접적 풀이, dfs로도 가능
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int row, col;
int graph[100][100]; // 인접 행렬 - 문제에 노드 정보 없으므로
bool visited[100][100]; // 방문 체크 배열
int ti, result = 0; // 치즈가 모두 녹는데 걸리는 시간, 녹는 치즈 개수

// 상하좌우 탐색 - if문 대신 for문으로 간결하게 표현 가능
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool bfs() {
    int cnt = 0; // 이번 턴 녹는 치즈 개수
    // 시작점 - 치즈 가장자리 치즈 없음 => (0,0)에서 시작
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // 상하좌우 탐색
        for(int i=0; i<4; ++i){
            int nr = r + dy[i];
            int nc = c + dx[i];

            // 범위 체크 + 방문 체크
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc]){
                visited[nr][nc] = true;

                if(graph[nr][nc] == 0){ // 치즈 아닌 경우(공기인 경우)
                    visited[nr][nc] = true; // 방문 체크
                    q.push({nr, nc}); // 탐색 계속하기 위해 큐에 추가
                }
                else {
                    visited[nr][nc] = true; // 방문 체크 - 중복 방지
                    graph[nr][nc] = 0; // 치즈 녹이기
                    cnt++; // 이번 턴 녹는 치즈 개수 1 증가
                }
            }
        }
    }

    if(cnt == 0){ // 이번 턴 녹는 치즈 개수 0 => 치즈 모두 녹은 상태
        return true; // 치즈 모두 녹은 상태 반환
    }
    else {
        result = cnt; // 이번 턴 녹는 치즈 개수 저장
        return false;
    }
}



int main() {
    cin >> row >> col;

    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            cin >> graph[i][j];
        }
    }

    while(true){
        if(bfs()){ // true 반환 시 치즈가 모두 녹은 상태
            break;
        }
        else {
            memset(visited, false, sizeof(visited)); // 방문 체크 배열 초기화
            ti++; // 치즈가 모두 녹는데 걸리는 시간 1 증가
        }
    }
    cout << ti << "\n" << result; // 치즈가 모두 녹는데 걸리는 시간, 녹기 직전 치즈 개수 출력
}