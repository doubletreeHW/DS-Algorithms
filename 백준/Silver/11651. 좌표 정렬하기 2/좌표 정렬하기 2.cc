#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	vector<pair<int, int>> coordinate;
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coordinate.emplace_back(y, x);
	}
	sort(coordinate.begin(), coordinate.end());

	for(int i = 0; i < n; i++) {
		cout << coordinate[i].second << " " << coordinate[i].first << "\n";
	}
	
	return 0;
}