#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define X first
#define Y second
string board[101];
int vis[101][101];
int visCB[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int cnt = 0;
	int cntCB = 0;
	queue<pair<int, int>> Q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(vis[i][j]) continue;
			cnt++;
			Q.push({i, j});
			vis[i][j] = 1;
			while(!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(visCB[i][j]) continue;
			cntCB++;
			Q.push({i, j});
			visCB[i][j] = 1;
			while(!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(board[cur.X][cur.Y] == 'B') {
						if(visCB[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
					}
					else {
						if(visCB[nx][ny] || board[nx][ny] == 'B') continue;
					}
					visCB[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	cout << cnt << ' ' << cntCB;
}