#include <bits/stdc++.h>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;
int f[42];

int fib(int n) {
    if (n == 1 || n == 2) {
		cnt1++;
		return 1;  
	}
    else return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2]; 
		cnt2++; 
	}
    return f[n];
}

int main() {
	int n;
	int rec, dp;
	cin >> n;
	rec = fib(n);
	dp = fibonacci(n);

	cout << cnt1 << ' ' << cnt2;
	return 0;
}