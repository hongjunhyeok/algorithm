#include<iostream>
using namespace std;
int memo[1010];

int fibonacci(int n) {
	if (n == 0) {
		return memo[n] = 1;
	}
	if (n == 1) {

		return memo[n] = 1;
	}
	if (memo[n] != 0) return memo[n];
	int& sum = memo[n];
	
	sum = (2*fibonacci(n - 2) + fibonacci(n - 1)) % 10007;
	return sum;
}

int main() {

	int num;
	cin >> num;
	int result = fibonacci(num);
	cout << result;



	return 0;
}