#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
	}
	else {
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		if (a[tree[node * 2]] <= a[tree[node * 2 + 1]]) {
			tree[node] = tree[node * 2];
		}
		else {
			tree[node] = tree[node * 2 + 1];
		}
	}
}
///////////////////////////////////
int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) {
		return -1;
	}
	if (i <= start && end <= j) { 
		return tree[node];
	}
	int m1 = query(a, tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(a, tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) {
		return m2;
	}
	else if (m2 == -1) {
		return m1;
	}
	else {
		if (a[m1] <= a[m2]) {
			return m1;
		}
		else {
			return m2;
		}
	}
}

//이동이 필요!!!!!
long long largest(vector<int> &a, vector<int> &tree, int start, int end) {
	int n = a.size();
	int m1 = query(a, tree, 1, 0, n - 1, start, end);
	int size = (end - start + 1)* a[m1];
	if (m1 + 1 <= end) {
		int tmp = largest(a, tree, m1+1,end);
		if (size < tmp) size = tmp;
	}
	if (m1 - 1 >= start) {
		int tmp = largest(a, tree, start, m1 - 1);
		if (size < tmp) size = tmp;
	}
	return size;
}
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i<n; i++) {
			cin >> a[i];
		}
		int h = (int)(ceil(log2(n)) + 1e-9);
		int tree_size = (1 << (h + 1));
		vector<int> tree(tree_size);
		init(a, tree, 1, 0, n - 1);


		for (int i = 0; i < tree_size; i++)
			cout << tree[i] << '\n';
		cout << largest(a, tree, 0, n - 1) << '\n';
	}
	return 0;
}