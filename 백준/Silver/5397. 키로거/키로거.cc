#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l;
	cin >> l;
	for(int i = 0; i < l; i++) {
		string init;
		cin >> init;
		list<char> boj;
		auto cursor = boj.begin();
		for(char c : init) {
			if(c == '<') {
				if(cursor != boj.begin()) cursor--;
			}
			else if(c == '>') {
				if(cursor != boj.end()) cursor++;
			}
			else if(c == '-') {
				if(cursor != boj.begin()) {
					auto delete_idx = cursor;
					delete_idx--;
					cursor = boj.erase(delete_idx);
				}
			}
			else {
				boj.insert(cursor, c);
			}
		}
		for(char c : boj) {
			cout << c;
		}
		cout << "\n";
	}

	return 0;
}