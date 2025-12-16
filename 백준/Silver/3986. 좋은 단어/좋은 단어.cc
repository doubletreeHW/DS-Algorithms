#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	int cnt;
	int n;
	cin >> n;
	while(n--) {
		stack<int> S;
		string a;
		cin >> a;
		for(char c : a) {
			if(S.empty() || S.top()!=c) {
				S.push(c);
				continue;
			}
			S.pop();		
		}
		if(S.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}