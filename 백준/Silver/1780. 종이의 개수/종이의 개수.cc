#include <bits/stdc++.h>
using namespace std;
int N;
int paper[3];
int board[2200][2200];

bool check(int x, int y, int n) {
	for(int i = x; i < x + n; i++) {
		for(int j = y; j < y + n; j++) {
			if(board[x][y] != board[i][j]) 
				return false;
		}
	}
	return true;
}

void func(int cnt, int x, int y) {
	if(check(x,y,cnt)) {
		paper[board[x][y] + 1] += 1;
		return;
	}
	int z = cnt/3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			func(z, x + i*z, y + j*z);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	func(N,0,0);
	for (int i = 0; i < 3; i++) 
		cout << paper[i] << "\n";
	return 0;
}