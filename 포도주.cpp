#include<iostream>
#include<algorithm>
using namespace std;
int memo[10001];

int podo[10001];
int maxpodo(int n) {
	if (n <= 0) return 0;
	if (n == 1) return memo[1] = podo[1];
	if (n == 2) return memo[2] = podo[1] + podo[2];

	if (memo[n] > 0) return memo[n];
	memo[n] = max({ maxpodo(n - 3) + podo[n - 1] + podo[n], maxpodo(n - 2) + podo[n] ,maxpodo(n-4)+podo[n-2]+podo[n-1]});
	
	return memo[n];
}

int main() {
	int Num;
	cin >> Num;

	for (int i = 1; i <= Num; i++) {
		cin >> podo[i];
	}
	

	//연달아 마셨으면 2 한번 뛰어 넘었으면 1
	
	cout << maxpodo(Num) << "\n";
	
	return 0;

}