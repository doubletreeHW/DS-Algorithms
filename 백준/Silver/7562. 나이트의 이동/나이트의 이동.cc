#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[301][301];
int dist[301][301];
int n;
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--) {
		int k, s1, s2, g1, g2;
		cin >> k >> s1 >> s2 >> g1 >> g2;
		for(int i = 0; i < k; i++) fill(dist[i], dist[i] + k, -1);
		queue<pair<int, int>> Q;
		Q.push({s1, s2});
		dist[s1][s2] = 0;
		while(!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			if(cur.X == g1 && cur.Y == g2) break;
			for(int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= k || ny < 0 || ny >= k) continue;
				if(dist[nx][ny] != -1) continue;
				Q.push({nx, ny});
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
		cout << dist[g1][g2] << '\n';
	}

	return 0;
}