#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
	int  end, cost;
	Edge(int end, int cost) :end(end), cost(cost) {};

};
bool check[1001];
int dist[1001];
int back[1001];
vector<Edge> a[10001];
int ans = 0;

int inf = 987654321;
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		a[from].push_back(Edge(to, time));
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
		check[i] = false;
		back[i] = inf;
	}





	back[x] = 0;
	set<pair<int, int>>q;
	q.insert(make_pair(0, x));

	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int x = p.second;

		if (check[x]) {
			continue;
		}

		ios::sync_with_stdio(false);
		cin.tie(NULL);
		check[x] = true;

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].end;
			if (back[y] > back[x] + a[x][i].cost) {
				auto it = q.find(make_pair(back[y], y));

				if (it != q.end()) {
					q.erase(it);
				}
				back[y] = back[x] + a[x][i].cost;
			}
			q.insert(make_pair(back[y], y));
		}
	}
	
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
		check[i] = false;
	}
	





	for (int start = 1; start <= n; start++) {

		dist[start] = 0;
		set<pair<int, int>>q;
		q.insert(make_pair(0, start));

		while (!q.empty()) {
			auto p = *q.begin();
			q.erase(q.begin());
			int x = p.second;

			if (check[x]) {
				continue;
			}


			check[x] = true;

			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i].end;
				if (dist[y] > dist[x] + a[x][i].cost) {
					auto it = q.find(make_pair(dist[y], y));

					if (it != q.end()) {
						q.erase(it);
					}
					dist[y] = dist[x] + a[x][i].cost;
				}
				q.insert(make_pair(dist[y], y));
			}
		}


		for (int i = 1; i <= n; i++) {
			dist[i] = inf;
			check[i] = false;
		}
	}



	cout << ans;
	return 0;
}