#include <iostream>
#include <algorithm>
using namespace std;
int stairPoints[301]; //���� ����
int memo[301];
// �� �������� �ִ�����
int count = 0;
int stairs=0;


//�ִ���ã�� �Լ�. n=����
int find(int n) {

	//base case
	if (n == 0) return memo[0]=0;
	if (n== 1)
		memo[n] = stairPoints[1];
	if (n == 2)
		memo[n] = stairPoints[1] + stairPoints[2];
	
	//
	if (memo[n] > 0) return memo[n];


	// n��° ��ܿ� �����ϱ� ���ؼ� 2���� ����� �����Ѵ�.
	//
	memo[n] = max(stairPoints[n] +find(n-2), stairPoints[n] +find(n-3) + stairPoints[n - 1]);

	return memo[n];
}


int main() {
	int stairPoint;

	//��� �� �Է�
	cin >> stairs;
	

	//�����Է�
	for (int i = 1; i <= stairs; i++) {
		memo[i] = 0;
	}
	for (int i = 1; i <= stairs; i++) {
		cin >> stairPoint;
		stairPoints[i] = stairPoint;
	}

	int result;

	result = find(stairs);
	
		cout << result << endl;
	


	return 0;
} 