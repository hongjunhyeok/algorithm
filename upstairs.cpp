#include <iostream>
#include <algorithm>
using namespace std;
int stairPoints[301]; //층의 점수
int memo[301];
// 각 층마다의 최대점수
int count = 0;
int stairs=0;


//최대합찾는 함수. n=층수
int find(int n) {

	//base case
	if (n == 0) return memo[0]=0;
	if (n== 1)
		memo[n] = stairPoints[1];
	if (n == 2)
		memo[n] = stairPoints[1] + stairPoints[2];
	
	//
	if (memo[n] > 0) return memo[n];


	// n번째 계단에 도착하기 위해선 2가지 방법이 존재한다.
	//
	memo[n] = max(stairPoints[n] +find(n-2), stairPoints[n] +find(n-3) + stairPoints[n - 1]);

	return memo[n];
}


int main() {
	int stairPoint;

	//계단 수 입력
	cin >> stairs;
	

	//점수입력
	for (int i = 1; i <= stairs; i++) {
		memo[i] = 0;
	}
	for (int i = 1; i <= stairs; i++) {
		cin >> stairPoint;
		stairPoints[i] = stairPoint;
	}

	int result;

	result = find(stairs);
	
		cout << result << endl;
	


	return 0;
} 