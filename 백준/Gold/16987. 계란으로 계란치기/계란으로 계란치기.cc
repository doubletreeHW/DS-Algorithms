#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int maxEgg;
int damage[8];
int hp[8];
void func(int k) {
	if(k==n) {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(hp[i]<=0) cnt++;
		}
		if(cnt > maxEgg) maxEgg = cnt;
		return;
	}

	if(hp[k] <= 0) {
		func(k+1);
			return;
	}
	bool struck = false;

	for(int i = 0; i < n; i++) {
		if(i != k && hp[i] > 0) {
			struck = true;
			hp[i] -= damage[k];
			hp[k] -= damage[i];
			func(k+1);
			hp[i] += damage[k];
			hp[k] += damage[i];
		}
	}
	if(!struck) func(k+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> hp[i] >> damage[i];
	}
	func(0);
	cout << maxEgg;
	return 0;
}