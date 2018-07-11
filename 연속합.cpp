#include<iostream>
using namespace std;

int main() {
	int N;
	int number[100000];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}
	int max = number[1];
	int total = 0;
	for (int i = 1; i <= N; i++) {
		total += number[i];
		if (max < total) {
			max = total;
			
		}if (total < 0) total = 0;
	}
	cout << max;

	return 0;
}