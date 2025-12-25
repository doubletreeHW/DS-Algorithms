#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n, k;
int board[102][102];
int vis[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	while(k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = y1; i < y2; i++) {
			for(int j = x1; j < x2; j++) {
				board[i][j] = 1;
			}	
		}
	}
	int count = 0;
	vector<int> ans;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(vis[i][j] || board[i][j]) continue;
			queue<pair<int, int>> Q;
			count++;
			Q.push({i, j});
			int area = 1;
			vis[i][j] = 1;
			while(!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if(board[nx][ny] || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
					area++;
				}
			}
			ans.emplace_back(area);
		}	
	}
	sort(ans.begin(), ans.end());

	cout << count << '\n';
	for(int x : ans) 
		cout << x << ' ';

	return 0;
}