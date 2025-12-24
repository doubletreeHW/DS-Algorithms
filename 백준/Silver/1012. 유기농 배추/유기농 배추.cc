#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        // 초기화
        for(int i = 0; i < 51; i++) {
            fill(board[i], board[i] + 51, 0);
            fill(vis[i], vis[i] + 51, 0);
        }
        // 양배추 위치 입력받기
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        int cabbage = 0;
        // 시작위치 정하기
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 0 || vis[i][j]) continue;
                //지렁이 마리 수 
                cabbage++;
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cabbage << '\n';
    }
}
