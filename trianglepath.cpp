#include<iostream>
#include<algorithm>

using namespace std;
int memo[101][101];
int triangle[101][101];
int find_triangle_sum(int n,int index) {

	if (n == 0) return 0;

	if (memo[n][index] > 0) return memo[n][index];

	int &ptr = memo[n][index];
	ptr = triangle[n][index]+ max(find_triangle_sum(n -1,index), find_triangle_sum(n - 1,index+1));

	return ptr;
}

int main() {
	

	int  T;
	cin >> T;
	for (int k = 1; k <= T; k++) {
		int H;
		cin >> H;
		if (H > 100) exit(0);
		
		for(int i=H;i>=1;i--)
			for (int j = 1; j <= H + 1-i; j++) {
				cin >> triangle[i][j];
			}

	/*	cout << "입력값: " << endl;
		for (int i = H; i >= 1; i--)
	 {
		for (int j = 1; j <= H + 1 - i; j++) {

			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
		cout << "메모하기전 " << endl;
		for (int i = H; i >= 1; i--)
		{
			for (int j = 1; j <= H + 1 - i; j++) {

				cout << memo[i][j] << " ";
			}
			cout << endl;
		}
		cout << "메모한 후 " << endl;
		find_triangle_sum(H, 1);

		for (int i = H; i >= 1; i--)
		{
			for (int j = 1; j <= H + 1 - i; j++) {

				cout << memo[i][j] << " ";
			}
			cout << endl;
		}
*/
		int re=find_triangle_sum(H,1);
		cout << re << endl;
		

		
		
	}
}