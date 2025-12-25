#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dist[1000005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	if(s==g) {
		cout << 0;
		return 0;
	}

	int dx[2] = {u, -d};
	queue<int> Q;
	Q.push(s);
	dist[s] = 1;
	
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
		
			if(nx < 1 || nx > f) continue;

			if(nx == g) {
				cout << dist[cur];
				return 0;
			}

			if(dist[nx] >= 1) continue;

			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	cout << "use the stairs";

	return 0;
}