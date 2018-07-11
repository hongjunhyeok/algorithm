#include<iostream>
#include<algorithm>

using namespace std;
int memo[501][501];
int triangle[501][501];
int find_triangle_sum(int n,int index) {

	if (n == 0) return 0;

	if (memo[n][index] > 0) return memo[n][index];

	memo[n][index] = triangle[n][index]+ max(find_triangle_sum(n +1,index), find_triangle_sum(n + 1,index+1));

	return memo[n][index];
}

int main() {
	


		int H;
		cin >> H;
		if (H > 100) exit(0);
		
		for(int i=H;i>=1;i--)
			for (int j = 1; j <= H + 1-i; j++) {
				cin >> triangle[i][j];
			}


		int re=find_triangle_sum(,1);
		cout << re << endl;
		

		
		
		return 0;
}