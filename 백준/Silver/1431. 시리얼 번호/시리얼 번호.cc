#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool comp(const string& a, const string& b);

int main() {
	vector<string> serialNum;
	string s;
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		serialNum.emplace_back(s);
	}
	sort(serialNum.begin(), serialNum.end(), comp);

	for(int i = 0; i < n; i++) {
		cout << serialNum[i] << "\n";
	}

	return 0;
}

bool comp(const string& a, const string& b) {
	if(a.length() != b.length()) {
		return a.length() < b.length();
	}

	int result1 = 0;
	int result2 = 0;
	for(char x : a) {
		if(isdigit(x)) {
			result1 += (x - '0');
		}
	}

	for(int x : b) {
		if(isdigit(x)) {
			result2 += (x - '0');
		}
	}

	if(result1 != result2) {
		return result1 < result2;
	}

	return a < b;
}