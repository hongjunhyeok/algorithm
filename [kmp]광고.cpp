#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;


vector<int> preprocessing(string s) {
	int j = 0;
	int size = s.size();
	vector<int>pi(size+1);
	for (int i = 1; i < size; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else
			pi[i] = 0;
	}
	return pi;
}


int main() {
	int L;
	string s;
	cin >> L;
	cin >> s;

	auto pi = preprocessing(s);

	cout << L - pi[L-1];
}