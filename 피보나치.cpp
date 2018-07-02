#include<iostream>
using namespace std;
long long int memo[91];

long long int  fibonacci(int n) {
	if (n == 1) {
		return memo[n] = 1;
	}
	if (n == 2){
		
		return memo[n]= 1;
	}
	if (memo[n] != 0) return memo[n];
	long long int& sum = memo[n];
	sum = fibonacci(n - 2) + fibonacci(n - 1);
	return sum;
}

int main() {
	
		int num;
		cin >> num;

		long long int result = fibonacci(num);
		cout <<result <<endl;

		for (int i = 1; i <= num; i++)
		{
			memo[i] = 0;
		}
	
	return 0;
}