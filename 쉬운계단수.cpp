#include<iostream>
#define mod 100000000
using namespace std;
int memo[101][10];



int main() {
	int N = 0;
	cin >> N;


	for (int i = 1; i <= 9; i++)
		memo[1][i] = 1;

	for (int k = 2; k <= N; k++) {

		for (int i = 0; i <= 9; i++) {
			if (i == 0)
				memo[k][i] += memo[k - 1][i + 1];
			else if (i == 9)
				memo[k][i] += memo[k - 1][i - 1];
			else
				memo[k][i] += memo[k - 1][i - 1] + memo[k - 1][i + 1];

			memo[k][i] %= mod;
		}
	}
		long long result = 0;

		for (int i = 0; i <= 9; i++)
			result += memo[N][i];

		result = result % mod;
		cout << result << "\n";

	return 0;
}