#include <cstdio>
#include <vector>
#include <set>
using namespace std;

//엣지정의
struct Edge {
	int end, cost;
	Edge(int end, int cost) : end(end), cost(cost)
	{}
};


vector<Edge> a[20001];

//다익스트라를 위한 배열 정의
int dist[20001];
bool check[20001];
int inf = 1000000000;


int main() {

	//입력
	int n, m;
	scanf("%d %d", &n, &m);
	int start = 0;
	scanf("%d", &start);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(Edge(v, w));
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}


	//자기자신은 0으로 초기화.
	dist[start] = 0;
	//큐대신 set을 이용.set = queue + stack,q한번 삽입(시작)
	set<pair<int,int>>q;
	q.insert(make_pair(0, start));
//다익스트라
	while (!q.empty()) {
		int x = q.begin()


	}

	//출력
	
	return 0;
}