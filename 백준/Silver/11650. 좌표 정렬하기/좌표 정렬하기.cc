#include <iostream>
#include <algorithm>
#include <vector>
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
		coordinate.push_back({x, y});
	}

	sort(coordinate.begin(), coordinate.end());

	for(int i = 0; i < n; i++) {
		cout << coordinate[i].first << " " << coordinate[i].second << "\n";
	}

	return 0;
}