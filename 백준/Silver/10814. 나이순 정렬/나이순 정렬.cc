#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int main() {
	vector<pair<int, string>> user;
	string name;
	int age;
	int n;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> age >> name;
		user.emplace_back(age, name);
	}
	stable_sort(user.begin(), user.end(), [](const pair<int, string>& a, 
		const pair<int, string>& b){return a.first < b.first;});

	for(int i = 0; i < n; i++) {
		cout << user[i].first << " " << user[i].second << "\n";
	}

	return 0;
}