#include <iostream>
#include <string>
using namespace std;

int main() {
	int count[10] = {0,};
	string s;
	cin >> s;
	
	for(char digit : s) {
		count[digit - '0']++;
	}

	count[6] = (count[6] + count[9] + 1) / 2;
	count[9] = 0;

	int top = count[0];
	for(int i = 1; i < 10; i++) {
		if(top < count[i]) {
			top = count[i];
		}
	}
	cout << top;

	return 0;
}