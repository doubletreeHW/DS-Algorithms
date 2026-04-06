#include <iostream>
using namespace std;

int n;
int a, b;

int pcNum(int a, int b) {
    int num = 1;
    for(int i = 0; i < b; i++) {
        num = num * a % 10;
    }
    return (num == 0 ? 10 : num);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << pcNum(a, b) << '\n';
    }
    return 0;
}