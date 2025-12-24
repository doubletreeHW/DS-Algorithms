#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
string board[1001];
#define X first
#define Y second
int dist_fire[1001][1001];
int dist_man[1001][1001];
int c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0 ,1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c;
	while(c--) {
		int w, h;
		cin >> w >> h;

		queue<pair<int, int>> QF;
		queue<pair<int, int>> QM;

		for(int i = 0; i < h; i++) {
			fill(dist_fire[i], dist_fire[i] + w, -1);
			fill(dist_man[i], dist_man[i] + w, -1);
			cin >> board[i];
			for(int j = 0; j < w; j++) {
				if(board[i][j]=='@') {
					QM.push({i, j});
					dist_man[i][j] = 0;
				}
				if(board[i][j]=='*') {
					QF.push({i, j});
					dist_fire[i][j] = 0;
				}
			}
		}
		while(!QF.empty()) {
			auto cur = QF.front(); QF.pop();
			for(int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(dist_fire[nx][ny] != -1 || board[nx][ny] == '#') continue;
				QF.push({nx, ny});
				dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1; 
			}
		}
		bool isEscape = false;
		while(!QM.empty()) {
			auto cur = QM.front(); QM.pop();
			for(int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
					isEscape = true;
					cout << dist_man[cur.X][cur.Y] + 1 << '\n';
					break;
				} 
				if(board[nx][ny] == '#' || dist_man[nx][ny] != -1) continue;
				if(dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist_man[cur.X][cur.Y] + 1) continue;
				QM.push({nx, ny});
				dist_man[nx][ny] = dist_man[cur.X][cur.Y] + 1; 
			}
			if(isEscape) break;
		}
		if(!isEscape) cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}