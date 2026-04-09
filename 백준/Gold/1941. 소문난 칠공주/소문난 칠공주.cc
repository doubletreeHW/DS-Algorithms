#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
int cnt=0;
int cntArr = 0;
string board[5];
bool isused[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int k, int start) {
	if(k==7) {
		int cntArr = 1;
		int cntS = 0;
		bool vis[5][5];
		fill(vis[0], vis[0]+25, false);
		queue<pair<int, int>> Q;
		for(int i = 0; i < 5; i++) {
			bool found = false;
			for(int j = 0; j < 5; j++) {
				if(isused[i][j]) {
					Q.push({i,j});
					found = true;
					if(board[i][j] == 'S') cntS++;
					vis[i][j] = true;
					break;
				}
			}
			if(found) break;
		}
		
		while(!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for(int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
				if(vis[nx][ny] || !(isused[nx][ny])) continue;
				vis[nx][ny] = true;
				Q.push({nx,ny});
				if(board[nx][ny] == 'S') {
					cntS++;
				}
				cntArr++;
			}
		}
		
		if(cntArr==7 && cntS >= 4) {
			cnt++;
		}

		return;
	}
	for(int i = start; i < 25; i++) {
		int r = i / 5;
		int c = i % 5;
		isused[r][c] = true;
		func(k+1, i + 1);
		isused[r][c] = false;

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < 5; i++) 
		cin >> board[i];
	func(0, 0);
	cout << cnt;

	return 0;
}