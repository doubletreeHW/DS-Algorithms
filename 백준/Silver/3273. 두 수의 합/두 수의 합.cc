#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool num[2000001]= {};
	int a[1000001] = {};
	int n, x;
	int count = 0;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	for(int i = 0; i < n; i++) {
		if(x - a[i] > 0 && num[x-a[i]]) {
			count++;
		}
		num[a[i]] = true;
	}

	cout << count;

	return 0;
}