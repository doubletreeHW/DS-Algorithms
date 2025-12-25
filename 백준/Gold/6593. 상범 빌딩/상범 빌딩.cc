#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char board[31][31][31];
int dist[31][31][31];
int l, r, c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1) {
		cin >> l >> r >> c;
		if(l==0 && r==0 && c==0) return 0;

		queue<tuple<int, int, int>> Q;
		bool istrapped = true;

		for(int i = 0; i < l; i++) {
			for(int j = 0; j < r; j++) {
				fill(dist[i][j], dist[i][j] + c, -1);
			}
		}

		for(int i = 0; i < l; i++) {
			for(int j = 0; j < r; j++) {
				for(int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if(board[i][j][k] == 'S') {
						Q.push({i, j, k});
						dist[i][j][k] = 0;
					}
				}
			}
		}
		
		while(!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			int curX, curY, curZ;
			tie(curX, curY, curZ) = cur;
			for(int dir = 0; dir < 6; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if(board[nx][ny][nz] == 'E') {
					istrapped = false;
					cout << "Escaped in " << dist[curX][curY][curZ] + 1 << " minute(s)." << '\n';
					break;
				}
				if(nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
				if(dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == '#') continue;
				Q.push({nx,ny,nz});
				dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			}
			if(!istrapped) break;
		}
		if(istrapped) cout << "Trapped!" << '\n';
	}	
}