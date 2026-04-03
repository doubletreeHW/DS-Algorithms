#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[16];
char v[16];

void func(int k, int start) {
	if(k==l) {
		bool aeiou = false;
		int cnt = 0;
		for(int i = 0; i < l; i++) {
			if(	   arr[i] == 'a'
				|| arr[i] == 'e'
				|| arr[i] == 'i'
				|| arr[i] == 'o'
				|| arr[i] == 'u' ) {
					aeiou = true;
			}
			else cnt++;
		}
		if(aeiou && cnt >= 2) {
			for(int i = 0; i < l; i++) {
				cout << arr[i];
			}
			cout << '\n';
			return;
		}
		return;
	}
	for(int i  = start; i < c; i++) {
		arr[k] = v[i];
		func(k+1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for(int i = 0; i < c; i++) cin >> v[i];
	sort(v, v+c);
	func(0, 0);
	return 0;
}