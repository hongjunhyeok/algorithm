#include<iostream>

#include<algorithm>
using namespace std;
int sticky[1000][2];
int memo[1000];
int S(int n,int b) {
	
}


int main() {
	int T; 
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> sticky[1000][0];
		}
		for (int i = 1; i <= N; i++) {
			cin >> sticky[1000][1];
		}

		int result = max({ S(N,0),S(N,1),S(N,2)});
		cout << result << "\n";
	}
	return 0;
}