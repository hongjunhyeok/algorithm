#include <iostream>
using namespace std;
long long d[1001][10];
long long mod = 100007;
int main() {
	int n;
	cin >> n ;
	long long result = 0;
	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= 9; k++) {
			for (int j = 0; j <= k; j++) {
				d[i][k] += d[i - 1][j];
				d[i][k] %= mod;
			}
			
		}
	}
	for (int i= 0; i <= 9; i++)
		result += d[n][i];
	result %= mod;
	cout << result << '\n';
	return 0;
}