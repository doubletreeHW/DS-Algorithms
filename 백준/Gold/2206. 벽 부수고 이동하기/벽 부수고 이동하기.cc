#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
char board[1001][1001];
int dist[1001][1001][2];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	queue<tuple<int, int, int>> Q;
	Q.push({0, 0, 0});
	dist[0][0][0] = 1;
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int curX, curY, broken;
		tie(curX, curY, broken) = cur;
		if(curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][broken];
			return 0;
		}
		for(int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
				Q.push({nx,ny,broken});
			}
			if(board[nx][ny] == '1' && broken == 0 && dist[nx][ny][broken] == -1) {
				dist[nx][ny][1] = dist[curX][curY][0] + 1;
				Q.push({nx, ny, 1});
			}
		}
	}
	cout << -1;

	return 0;
}