#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool isMinus = false;
    
    int h1, m1;
    cin >> h1 >> m1;
    
    int m2 = 0;
    
    m2 = m1 - 45;
    
    if(m2 < 0) {
        isMinus = true;
        m2 += 60;
    }
    
    if(isMinus) h1--;
    
    if(h1 < 0) h1 = 23;
    
    cout << h1 << ' ' << m2;
}