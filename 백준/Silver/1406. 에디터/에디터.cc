#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string init;
    list<char> boj;

    cin >> init;
    for(char c : init) {
        boj.emplace_back(c);
    }
    auto cursor = boj.end();

    int p;
    cin >> p;
    while(p--) {
        char op;
        cin >> op;
        if(op == 'L') {
            if(cursor != boj.begin()) {
                cursor--;
            }
        }
        else if(op == 'D') {
            if(cursor != boj.end()) {
                cursor++;
            }
        }
        else if(op == 'P') {
            char add;
            cin >> add;
            boj.insert(cursor, add);
        }
        else {
            if(cursor != boj.begin()) {
                cursor--;
                cursor = boj.erase(cursor);
            }
            
        }
    }

    for(char c : boj) { 
        cout << c;
    }

    return 0;
}