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


vector<Edge> a[20001];

//���ͽ�Ʈ�� ���� �迭 ����
int dist[20001];
bool check[20001];
int inf = 1000000000;


int main() {

	//�Է�
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


	//�ڱ��ڽ��� 0���� �ʱ�ȭ.
	dist[start] = 0;
	//ť��� set�� �̿�.set = queue + stack,q�ѹ� ����(����)
	set<pair<int,int>>q;
	q.insert(make_pair(0, start));
//���ͽ�Ʈ��
	while (!q.empty()) {
		int x = q.begin()


	}

	//���
	
	return 0;
}