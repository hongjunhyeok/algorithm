#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[1001];
struct Edge {
	int start, end;
	bool operator < (const Edge &other)const {
		return start < other.start;
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
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= 1000; i++) {
			parent[i] = i;
		}

		vector<Edge>computer(m+1);

		for (int i = 1; i <= m; i++) {
			cin >> computer[i].start >> computer[i].end;
		}

		sort(computer.begin(), computer.end());
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x = computer[j].start;
				int y = computer[j].end;
		

				x = Find(x);
				y = Find(y);
				if (x != y) {
					Union(x, y);
					sum += 1;
				}
			}
		}

		cout << sum<<endl;

	}
}