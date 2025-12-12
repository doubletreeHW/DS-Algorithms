#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	queue<int> Q;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		Q.push(i);
	}
	for(int i = 1; i < n; i++) {
		int card;
		Q.pop();
		card = Q.front();
		Q.pop();
		Q.push(card);
	}

	cout << Q.front();

	return 0;
}