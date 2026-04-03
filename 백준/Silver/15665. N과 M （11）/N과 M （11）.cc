#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m,n;
int arr[10];
vector<int> v;

void func(int k) {
	if(k==m) {
		for(int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = 0;
	for(int i = 0; i < n; i++) {
		if(tmp != v[i]) {
			arr[k] = v[i];
			tmp = arr[k];
			func(k+1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	func(0);
	return 0;
}