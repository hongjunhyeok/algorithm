#include <iostream>
#include <algorithm>
using namespace std;
int memo2[1000][3];
int memo[1000][3];
int num;
int cost_eval(int n, int color) {
	if (n == num) return 0;

	if (memo2[n][color] != 0) return memo2[n][color];

	if(color == 0) memo2[n][color] = memo[n][0] + min(cost_eval(n + 1, color+1), cost_eval(n + 1, color+2));
	if (color == 1) memo2[n][color] = memo[n][1] + min(cost_eval(n + 1, color+1), cost_eval(n + 1, color  -1));
	if (color == 2) memo2[n][color] = memo[n][2] + min(cost_eval(n + 1, color - 1), cost_eval(n + 1, color - 2));

	
	return memo2[n][color];
}

int main() {
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> memo[i][0];
		cin >> memo[i][1];
		cin >> memo[i][2];
	}
	int cc;
	int paint_cost;
	

	

	cout << min({ cost_eval(0,0),cost_eval(0,1),cost_eval(0,2)});
	return 0;

}