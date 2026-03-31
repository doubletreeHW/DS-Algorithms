#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
vector<int> v;

void func(int k) {
	if(k==m) {
		for(int i=0; i<m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i=0; i<n; i++) {
		arr[k] = v[i];
		func(k+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	func(0);
	return 0;
}