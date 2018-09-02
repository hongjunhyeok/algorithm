#include <cstdio>
#include <vector>
#include <set>
using namespace std;

//��������
struct Edge {
	int end, cost;
	Edge(int end, int cost) : end(end), cost(cost)
	{}
};


vector<Edge> a[100001];

//���ͽ�Ʈ�� ���� �迭 ����
int dist[1001];
bool check[1001];
int inf = 1000000000;


int main() {

	//�Է�
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(Edge(v, w));
	}
	int start = 0, end = 0;
	scanf("%d %d", &start, &end);
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}



	//�ڱ��ڽ��� 0���� �ʱ�ȭ.
	dist[start] = 0;
	//ť��� set�� �̿�.set = queue + stack,q�ѹ� ����(����)
	set<pair<int, int>>q;
	q.insert(make_pair(0, start));
	//���ͽ�Ʈ��
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

			if (dist[y] > dist[x] + a[x][i].cost)
			{
				
				dist[y] = dist[x] + a[x][i].cost;
			}
			q.insert(make_pair(dist[y], y));
		}


	}
	printf("%d", dist[end]);
	//���

	return 0;
}