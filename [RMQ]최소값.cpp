#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void init(vector<int> &tree, vector<int> &a, int node, int start, int end, bool ismin) {

	//leaf node같은경우 a의 시작값이 해당노드의 최소값이다.(하나밖에 없음)
	if (start == end) {
		tree[node] = a[start];
	}
	//post-order 루트같은경우 자식노드중으 최소값을 저장하게 된다.
	else {
		init(tree, a, node * 2, start, (start + end) / 2, ismin);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, ismin);
		if (ismin)
			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		else
			tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

void update(vector<int>&tree, int value, int node, int start, int end, int index) {
	if (index < start || end <index) {
		return;
	}
	if (start == end) {
		tree[node] = value; return;
	}
	update(tree, value, 2 * node, start, (start + end) / 2, index);
	update(tree, value, 2 * node + 1, (start + end) / 2 + 1, end, index);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);

}
// i~j에해당하는 최소값 반환.
int query(vector<int> &tree, int node, int start, int end, int i, int j, bool ismin) {

	//물어보는 구간이 실질범위를 넘어가는 경우 :: 무효값 반환
	if (i > end || j < start) {
		return -1;
	}
	// i~j에 해당하는 부분이 실질범위를 포함하는경우 :: 해당 노드(최소값) 반환
	if (i <= start && end <= j) {
		return tree[node];
	}

	// 그외의 경우는 쪼개서 검사해야한다.
	int m1 = query(tree, 2 * node, start, (start + end) / 2, i, j, ismin);
	int m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j, ismin);

	//m1과 m2둘중의 하나는 -1이다.
	if (m1 == -1) {
		return m2;
	}
	else if (m2 == -1) {
		return m1;
	}
	else {
		if (ismin)
			return min(m1, m2);
		else
			return max(m1, m2);
	}



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int>input(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<int>tree_min(tree_size);
	vector<int>tree_max(tree_size);

	init(tree_min, input, 1, 1, N, true);
	init(tree_max, input, 1, 1, N, false);

	vector<pair<int, int>>input2(M + 1);
	for (int i = 1; i <= M; i++) {
		int from, to;
		cin >> from >> to;
		input2[i] = make_pair(from, to);

	}
	for (int i = 1; i <= M; i++) {
		int st = input2[i].first;
		int ed = input2[i].second;
		int min = query(tree_min, 1, 1, N, st, ed, true);
		int max = query(tree_max, 1, 1, N, st, ed, false);
		cout << min << " " << max << "\n";
	}

	return 0;
}