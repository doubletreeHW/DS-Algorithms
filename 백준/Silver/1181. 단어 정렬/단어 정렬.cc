#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool stringcmp(string& a, string& b) {
	if(a.length() != b.length()) {
		return a.length() < b.length();
	}

	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> words;
	string s;
	int n;
	
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < i; j++){
			if(s == words[j]) {
				continue;
			}
		}
		words.emplace_back(s);

	}

	sort(words.begin(), words.end(), stringcmp);

	auto last = unique(words.begin(), words.end());
	words.erase(last, words.end());

	for(string& word : words) {
		cout << word << "\n";
	}

	return 0;
}