#include <iostream>
using namespace std;

int N;
char star[2250][2250];

void func(int n, int x, int y) {
	if(n == 1) {
		star[x][y] = '*';
		return;
	}
	int dep = n/3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(i == 1 && j == 1) continue;
			func(dep, x + i*dep, y + j*dep);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	func(N,0,0);

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(star[i][j] != '*') {
				cout << ' ';
				continue;
			}
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}