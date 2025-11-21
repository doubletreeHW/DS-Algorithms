#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long n;
	vector<long> boj;
	cin >> n;

	for(int i = 0; i < n; i++) {
		long temp;
		cin >> temp;
		boj.push_back(temp);
	}

	sort(boj.begin(), boj.end());

	for(int i = 0; i < n; i++) {
		cout << boj[i] << "\n";
	}

	return 0;
}