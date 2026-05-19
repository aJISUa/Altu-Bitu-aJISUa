// 제한사항: 정점 개수 1 <= N <= 1000 => 인접 행렬 메모리 초과 발생하지 않음
//         간선 개수 1 <= M <= 10000
#include <iostream>
#include <queue> // BFS
#include <cstring> // memset - DFS 방문 체크 배열 초기화 위해

using namespace std;

int n, m, v;
int graph[1001][1001] = {0,}; // 인접 행렬 - 노드 번호 1부터 시작
bool visited[1001] = {false}; // 방문 체크 배열
int dfs_ans[1001] = {0,}; // DFS 방문 순서 저장 배열
int bfs_ans[1001] = {0,}; // BFS 방문 순서 저장 배열

int idx = 1; // 문제에서 시작 노드 제시 

void dfs(int from){ // 재귀함수 - stack 자료구조 이용
    visited[from] = true; // 방문 체크

    for(int i=1; i<=n; i++){
        if(graph[from][i] == 1 && !visited[i]){ // 간선 존재 && 방문하지 않은 노드
            visited[i] = true; // 방문 체크
            dfs_ans[idx++] = i; // 방문 순서 저장
            dfs(i); // 재귀 호출
        }
    }
}

void bfs(int start){ // queue 자료구조 이용 - 시작 노드부터
    queue<int> q;
    q.push(start); // 이미 함수 호출 전에 방문 체크 완료함

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[now][i] == 1 && !visited[i]){
                visited[i] = true;
                bfs_ans[idx++] = i; // 방문 순서 저장
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; // 양방향 간선
    }

    dfs_ans[0] = bfs_ans[0] = v; // 시작 노드 저장
    visited[v] = true;
    dfs(v);

    memset(visited, false, sizeof(visited)); // DFS 방문 체크 배열 초기화
    idx = 1; // BFS 방문 순서 저장 배열 인덱스 초기화
    visited[v] = true;
    bfs(v);

    for (int i=0; i<n; i++){
        if(dfs_ans[i] == 0) break;
        else cout << dfs_ans[i] << " ";
    }
    cout << "\n";
    for (int i=0; i<n; i++){
        if(bfs_ans[i] == 0) break;
        else cout << bfs_ans[i] << " ";
    }
}