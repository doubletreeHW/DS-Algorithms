#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> S;

	cin >> n;
	while(n--) {
		int init;
		cin >> init;
		if(init == 0) {
			S.pop();
		}
		else {
			S.push(init);
		}
	}

	int sum = 0;
	int size = S.size();
	for(int i = 0; i < size; i++) {
		int top = S.top();
		sum += top;
		S.pop();
	}
	cout << sum;

	return 0;
}