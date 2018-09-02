#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;


int match(string s, string p) {
	int n = s.size();
	int m = p.size();
	for (int i = 0; i < n-m; i++) {
		bool ok = true;
		for (int j = 0; j < m; j++) {
			if (s[i + j] != p[j]) {
				ok = false;
			}
		}
		if (ok) return i;
	}
	return -1;
} 
vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j])
		{
			pi[i] = j + 1;
			j++;
		}
		else
			pi[i] = 0;
	}
	return pi;
}
vector<int>kmp(string s, string p) {
	auto pi = preprocessing(p);
	vector<int>ans;
	int n = s.size();
	int m = p.size();
	int i = 0, j = 0;

	for (i; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if(s[i]==p[j])
			if (j == m - 1) {
				ans.push_back(i - j);
				j = pi[j];
			}
			else {
				j += 1;
			}
	}
	return ans;

}
int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	auto matched = kmp(s, p);
	cout << matched.size() << '\n';
	for (int i = 0; i < matched.size(); i++) {
		cout << matched[i];
	}
	cout << '\n';
	return 0;

	
}