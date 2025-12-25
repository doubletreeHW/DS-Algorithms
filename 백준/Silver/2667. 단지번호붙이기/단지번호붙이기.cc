#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define X first
#define Y second
string board[26];
int vis[26][26];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> board[i];
	int count = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(vis[i][j] || board[i][j] == '0') continue;
			queue<pair<int, int>> Q;
			int area = 1;
			count++;
			Q.push({i, j});
			vis[i][j] = 1;
			while(!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(vis[nx][ny] || board[nx][ny] == '0') continue;
					Q.push({nx, ny});
					vis[nx][ny] = 1;
					area++;
				}
			}
			ans.emplace_back(area);
		}
	}
	sort(ans.begin(), ans.end());
	cout << count << '\n';
	for(int i : ans)
		cout << i << '\n';
	return 0;
}