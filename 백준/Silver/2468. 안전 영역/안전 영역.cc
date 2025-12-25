#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int n, maxcnt, maxlimit;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j, int limit) {
	queue<pair<int, int>> Q;
	vis[i][j] = 1;
	Q.push({i, j});
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(vis[nx][ny] == 0 && board[nx][ny] > limit) {
				vis[nx][ny] = 1;
				Q.push({nx, ny});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
			maxlimit = max(maxlimit, board[i][j]);
		}
	}

	for(int limit = 0; limit < maxlimit; limit++) {
		for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
		
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] > limit && vis[i][j] == 0) {
					bfs(i, j, limit);
					cnt++;
				} 
			}
		}
		maxcnt = max(maxcnt, cnt);
	}
	cout << maxcnt;

	return 0;
}