#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define INF 987654321
using namespace std;

int check[101][101];
int city[101];

int main() {
	int distance[101][101] = { 0 };

	int node, edge;
	cin >> node >> edge;
	for (int i = 1; i <= node; i++) {
		city[i] = i;
		for (int j = 1; j <= node; j++) {
			distance[i][j] = INF;
			check[i][j] = false;
		}
	}

	int from, to, cost;
	for (int i = 1; i <= edge; i++) {
		cin >> from >> to >> cost;
		if (distance[from][to] > cost)
		{
			distance[from][to] = cost;
		}
	}
	for (int k = 1; k <= node; k++) {
		for (int j = 1; j <= node; j++) {
			for (int i = 1; i <= node; i++) {
				if (distance[i][k]!=INF && distance[k][j]!=INF) {
					distance[i][j] =min(distance[i][j], distance[i][k] + distance[k][j]);
					cout <<k<<" " << j<<" "<< i<<" "<< distance[i][j] << endl;
				}
			}
		}
	}
	cout << endl;
	int ans = INF;
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (i == j||distance[i][j]==INF) cout << 0<<" ";
			else cout << distance[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}