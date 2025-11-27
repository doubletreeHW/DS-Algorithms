#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	vector<int> coordinate;
	vector<int> comp;
	int n;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coordinate.emplace_back(temp);
		comp.emplace_back(temp);
	}

	sort(coordinate.begin(), coordinate.end());
	auto distinct = unique(coordinate.begin(), coordinate.end());
	coordinate.erase(distinct, coordinate.end());


	for(int i = 0; i < n; i++) {
		auto it = lower_bound(coordinate.begin(), coordinate.end(), comp[i]);
		int compressedCoordinate = distance(coordinate.begin(), it);
		cout << compressedCoordinate << " ";
	}

	return 0;
}