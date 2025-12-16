#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	int cnt = 0;
	stack<int> S;
	string ps;
	cin >> ps;
	for(int i = 0; i<ps.length(); i++) {
		if(ps[i]=='(') 
			S.push(ps[i]);
		else if ( ps[i]==')' && ps[i-1]=='(' && i != 0) {
			S.pop();
			cnt += S.size();
		}
		else {
			S.pop();
			cnt += 1;
		}
	}
	cout << cnt;
	
	return 0;
}