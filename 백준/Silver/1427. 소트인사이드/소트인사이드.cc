#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main() {
	string n;
	vector<int> boj;
	int i = 0;

	cin >> n;

	for (char c : n) {
		int temp = c - '0';
		boj.push_back(temp);
	}
	sort(boj.begin(),boj.end(), greater<int>());

	for(int digit : boj) {
		cout << digit;
	}

	return 0;
}