#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int n;


int find(vector<int>& memo,int k) {


	//base case
	if (k == 1) return 0;
	//memo 

	if (memo[k] != -1) return memo[k];

	memo[k] = find(memo,k - 1) + 1;

	if (k % 3 == 0) // 저장하기전에 검사해줘야 된다.
	{
		int temp = find(memo,k / 3) + 1;
		memo[k] = min(memo[k], temp);
	}
	if (k % 2 == 0)
	{
		int temp = find(memo,k / 2) + 1;
		
		memo[k] = min(memo[k], temp);
	}
	//return
	return memo[k];

}

int main() {
	
	cin >> n;
	vector<int> memo(n + 1, -1);
	memo.resize(n + 1, -1);
	
		cout << find(memo,n) << endl;

	




	return 0;
}