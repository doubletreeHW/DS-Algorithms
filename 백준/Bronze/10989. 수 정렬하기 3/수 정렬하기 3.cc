#include <iostream> // 계수 정렬(Counting Sort)
#include <vector>

using namespace std;

// 최대값은 10000이므로 크기를 10001로 설정합니다 (인덱스 1부터 10000까지 사용).
const int MAX_VAL = 10001; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int N;
    cin >> N;

	vector<int> counts(MAX_VAL, 0);
    
	for(int i = 0; i < N; i++) {
		int num;

		if(!(cin >> num)) {
			break;
		}

		counts[num]++;
	}

	for(int i = 1; i < MAX_VAL; i++) {
		for(int j = 0; j < counts[i]; j++) {
			cout << i << "\n";
		}
	}

    return 0;
}