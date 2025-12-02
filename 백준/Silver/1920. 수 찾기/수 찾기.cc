#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool check(vector<long>& vec, long num);

int main() {
	vector<long> vec;
	vector<long> isExist;
	vector<int> ans;
	int n, m;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++) {
		long temp;
		cin >> temp;
		vec.emplace_back(temp);
	}

	cin >> m;
	for(int i = 0; i < m; i++) {
		long temp;
		cin >> temp;
		isExist.emplace_back(temp);
	}

	sort(vec.begin(), vec.end());
	for(int i = 0; i < m; i++) {
		bool a = check(vec, isExist[i]);
		cout << a << "\n";
	}

	return 0;
}

bool check(vector<long>& vec, long num) {
	int low = 0;
	int high = vec.size() - 1;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(vec[mid] == num) {
			return true;
		}
		else if(vec[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return false;
}