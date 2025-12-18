#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist_fire[1002][1002];
int dist_jihoon[1002][1002];
int r,c;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		fill(dist_fire[i], dist_fire[i] + c, -1);
		fill(dist_jihoon[i], dist_jihoon[i] + c, -1);
	}
	for(int i = 0; i < r; i++) {
		cin >> board[i];
	}
	queue<pair<int,int>> QJ;
	queue<pair<int,int>> QFire;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(board[i][j]=='F') {
				dist_fire[i][j] = 0;
				QFire.push({i,j});
			}
			if(board[i][j]=='J') {
				dist_jihoon[i][j] = 0;
				QJ.push({i,j});
			}
		}
	}
	while(!QFire.empty()) {
		auto cur2 = QFire.front(); QFire.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur2.X + dx[dir];
			int ny = cur2.Y + dy[dir]; 
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(board[nx][ny] == '#' || dist_fire[nx][ny] >= 0) continue;
			dist_fire[nx][ny] = dist_fire[cur2.X][cur2.Y] + 1;
			QFire.push({nx,ny});
		}
	}

	while(!QJ.empty()) {
		auto cur1 = QJ.front(); QJ.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur1.X + dx[dir];
			int ny = cur1.Y + dy[dir]; 
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist_jihoon[cur1.X][cur1.Y] + 1;
				return 0;
			}
			if(board[nx][ny] == '#' || dist_jihoon[nx][ny] >= 0) continue;
			if(dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist_jihoon[cur1.X][cur1.Y]+1) continue;
			dist_jihoon[nx][ny] = dist_jihoon[cur1.X][cur1.Y] + 1;
			QJ.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}