#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
int board[65][65];

bool check(int n, int x, int y) {
	for(int i = x; i < x + n; i++) {
		for(int j = y; j < y + n; j++) {
			if(board[x][y] != board[i][j])
				return false;
		}
	}
	return true;
}

void func(int n, int x, int y) {
	if(check(n, x, y)) {
		cout << board[x][y];
		return;
	}
	cout << '(';
	int half = n/2;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			func(half, x + i*half, y + j*half);
		}
	}
	cout << ')';
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	func(N, 0, 0);

	return 0;
}