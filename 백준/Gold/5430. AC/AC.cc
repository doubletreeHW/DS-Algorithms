#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

void parse(string& arr, deque<int>& DQ) {
	int cur = 0;
	if(arr.size() <= 2) return; 

    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i] == ','){
             DQ.push_back(cur);
             cur = 0;
        }
        else{
             cur = 10 * cur + (arr[i] - '0');
        }
    }
	 if(cur != 0)
  	 	 DQ.push_back(cur);
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		deque<int> DQ;
		bool isWrong= false;
		int rev = 0;
		string func, arr;
		int arrLen;
		cin >> func >> arrLen >> arr;
		parse(arr, DQ);
		for(char c : func) {
			if(c=='R') {
				rev = 1 - rev;
			}
			else {
				if(DQ.empty()) {
					isWrong = true;
					break;
				}

				if(!rev) {
					DQ.pop_front();
				}
				else {
					DQ.pop_back();
				}
			}
		}
		if(isWrong) {
			cout << "error\n";
		}
		else {
			if(rev) {
				reverse(DQ.begin(), DQ.end());
			}
			cout << '[';
			for(int j = 0; j < DQ.size(); j++) {
				cout << DQ[j];
				if(j+1 != DQ.size()) 
					cout << ',';	
			}
			cout << ']' << '\n';
		}			
	}

	return 0;
}