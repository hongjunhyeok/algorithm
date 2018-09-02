#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[1001];
struct Edge {
	int start, end, cost;
	bool operator < (const Edge &other)const {
		return cost < other.cost;
	}
};

int Find(int n) {
	if (n == parent[n])
		return n;
	else
		return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);
	parent[x] = y;
}

int main() {


	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 1000; i++) {
		parent[i] = i;
	}

	vector<Edge>computer(m);

	for (int i = 0; i < m; i++) {
		cin >> computer[i].start >> computer[i].end >> computer[i].cost;
	}

	sort(computer.begin(), computer.end());
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int x = computer[j].start;
			int y = computer[j].end;
			int z = computer[j].cost;

			x = Find(x);
			y = Find(y);
			if (x != y) {
				Union(x, y);
				sum += z;
			}



		}
	}

	cout << sum;

}