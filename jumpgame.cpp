#include <string>
#include <vector>
#include <iostream>


using namespace std;


int board[100][100];
int n;


//오른쪽으로 ? 아래쪽으로 ? 
bool jump(int x, int y) {
	if (x > n || y > n) return false;
	if (y == n - 1 && x == n - 1) return true;

	return jump(x + board[x][y], y) || jump(x, y + board[x][y]);
}
int memo[100][100] = { 0, };

int jump_memo(int x, int y) {
	int check = 0;

	//기저사례
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	//memo
	int& ptr = memo[x][y];
	if (ptr != -1) return ptr;

	int jumper = board[x][y];
	ptr = jump_memo(x + jumper, y) || jump_memo(x, y + jumper);
	

	//return
	return ptr;
}

int main() {
	int t = 0;
	int x, y;

	cin >> t;
	while (t--) {
		
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				 memo[i][j]=-1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		if (board[n-1][n-1] != 0) exit(1);

		jump_memo(0, 0);
		if (jump_memo(0, 0)) cout << "YES"<<endl;
		else cout << "NO"<<endl;

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << memo[i][j] << " ";
			cout << "\n";
		}*/
		
	}
	

	return 0;

}




