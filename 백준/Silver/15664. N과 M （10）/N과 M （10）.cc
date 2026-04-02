#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
int isused[10];
vector<int> v;

void func(int k, int start) {
	if(k==m) {
		for(int i=0; i<m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = 0;
	for(int i = start; i < n; i++) {
		if(!isused[i] && tmp != v[i]) {
			arr[k] = v[i];
			isused[i] = true;
			tmp = arr[k];
			func(k+1, i+1);
			isused[i] = false;
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
	func(0, 0);
	return 0;
}