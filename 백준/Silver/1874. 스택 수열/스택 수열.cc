#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
 	cin.tie(0);
	stack<int> S;
	int count = 1;
	int n;
	cin >> n;
	string ans;
	while(n--) {
		int t;
		cin >> t;
		while(count<=t) {
			S.push(count++);
			ans += "+\n";
		}
		if(S.top() != t) {
			cout << "NO\n";
			return 0;
		}
		S.pop();
		ans += "-\n";
	}
	cout << ans;

	return 0;
}