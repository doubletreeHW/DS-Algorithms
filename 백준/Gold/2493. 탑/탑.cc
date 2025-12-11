#include <iostream> // 맨처음에 내가 떠올리지못하고 참고해서 코딩함
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
 	cin.tie(0);
	stack<pair<int, int>> tower;

	tower.push({100000001, 0});
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		while(tower.top().first < height) {
			tower.pop();
		}
		cout << tower.top().second << ' ';
		tower.push({height, i});
	}

	return 0;
}