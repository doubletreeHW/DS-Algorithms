#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int check(vector<long>& card, long num);
int lowerBound(const vector<long>& card, long num);
int upperBound(const vector<long>& card, long num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n;
		vector<long> card(n);
	for(int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> m;
		vector<long> counting(m);
	for(int i = 0; i < m; i++) {
		cin >> counting[i];
	}
	
	for(int i = 0; i < m; i++) {
		int lower = lowerBound(card, counting[i]);
		int upper = upperBound(card, counting[i]);
		cout << upper - lower << " ";
	}

	return 0;
}

int lowerBound(const vector<long>& card, long num) {
	int low = 0;
	int high = card.size();
	int result = card.size();

	while(low < high){
		int mid = low + (high - low) / 2;

		if(card[mid] >= num) {
			result = mid;
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

int upperBound(const vector<long>& card, long num) {
	int low = 0;
	int high = card.size();
	int result = card.size();

	while(low < high){
		int mid = low + (high - low) / 2;

		if(card[mid] > num) {
			result = mid;
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}
