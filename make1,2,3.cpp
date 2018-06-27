#include <iostream>
using namespace std;

int memo[12];

int makeN(int N) {
	//basecase
	if (N <= 3) {
		if (N == 1) return memo[N] = 1;
		if (N == 2) return memo[N] = 2;
		if (N == 3) return memo[N] = 4;
	}
	//memo
	
	if (memo[N] != -1) return memo[N];

	memo[N] = makeN(N - 1) + makeN(N - 2) + makeN(N - 3);
	//return

	return memo[N];


}

int main() {
	int T, result;
	cin >> T;
	for (int i = 0; i <= 11; i++)
		memo[i] = -1;

	for (int i = 1; i <= T; i++) {
	

		int num;
		cin >> num;
		result = makeN(num);
		cout << result << endl;

		return result;
	}
	return 0;
}