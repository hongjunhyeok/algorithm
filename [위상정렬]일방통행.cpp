#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;


int ind[10001];
int ind2[10001];
int d[10001];
bool c[10001];

struct info {
	int ed, time;
	info( int ed, int time) :  ed(ed), time(time) {};
};

int main_일방통행() {
	int city, road;
	cin >> city >> road;
	vector<info>a[10001];
	vector<info>b[10001];

	for (int i = 1; i <= road; i++) {
		int from, to, t;
		cin >> from >> to >> t;
		a[from].push_back(info(to, t));
		b[to].push_back(info(from, t));
		ind[to] += 1;
		ind2[from] += 1;
	}
	queue<int>q;
	for (int i = 1; i <= city; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	int start, end;
	cin >> start >> end;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].ed;
			d[y] = max(d[y], d[x] + a[x][i].time);
			ind[y] -= 1;
			if (ind[y] == 0) {
				q.push(y);
			}
		}
	}
	
	
	cout << d[end] << endl;
	for (int i = 1; i <= city; i++) {
		ind[i] = ind2[i];
	}
	for (int i = 1; i <= city; i++) {
		if (ind[i] == 0)
			q.push(i);
	}
	c[end] = true;
	int ans = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < b[x].size(); i++) {
			int y = b[x][i].ed;
			if (c[x] && d[x] - d[y] == b[x][i].time) {
				ans++;
				c[y] = true;
			}
			ind[y] -= 1;

			if (ind[y] == 0)
				q.push(y);
		}
	}
	cout << ans;


	return 0;
}