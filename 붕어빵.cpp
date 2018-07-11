#include<iostream>
using namespace std;
int price[10001], memo[10001];
int P(int N) {
	
	if (N == 0) return memo[N] = 0;
	if (N == 1) return memo[N] = price[N];
	int k;
	for (k = 1; k <= N; k++)
	{
		if (memo[N] < P(N - k) + price[k])
		{
			memo[N] = P(N - k) + price[k];
		}
	}
	return memo[N];
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
	cout << P(N) << "\n";


	return 0;
}