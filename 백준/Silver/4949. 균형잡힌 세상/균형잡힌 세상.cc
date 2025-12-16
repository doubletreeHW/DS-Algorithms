#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true) {
		string a;
		getline(cin, a);
		if(a == ".") break;

		stack<char> S;
		bool isVaild = true;

		for(auto c : a) {
			if(c=='(' || c=='[') {
				S.push(c);
			}
			else if(c==')') {
				if(S.empty() || S.top() != '(') {
					isVaild = false;
					break;
				}
				S.pop();
			}
			else if(c==']') {
				if(S.empty() || S.top() != '[') {
					isVaild = false;
					break;
				}
				S.pop();
			}
		}
		if(!S.empty()) isVaild = false;
		if(isVaild) cout << "yes\n";
		else cout << "no\n"; 
	}
	
	return 0;
}