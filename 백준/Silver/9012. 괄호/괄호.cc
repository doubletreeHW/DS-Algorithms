#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		bool isValid = true;
		stack<int> S;
		string a;
		cin >> a;
		for(char c : a) {
			if(c=='(') {
				S.push(c);
			}
			else {
				if(S.empty()) {
					isValid = false;
					break;
				}
				else {
					S.pop();
				}
			}
		}
		if(isValid && S.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}