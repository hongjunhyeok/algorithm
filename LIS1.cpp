#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, ret;
int A[1000], memo[1000],D[1000];
void go(int p) {
	if (p == -1) return;
	
	go(memo[p]);
	printf("%d ", A[p]);
}
int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		
	}

	for (int i = 0; i < N; i++) {
		D[i] = 1;
		memo[i] = -1;
		for (int j = 0; j < N; j++) {
			//Á¡È­½Ä D[i] = D[j]+1 if D[i] < D[j]+1
			if (D[j] + 1 > D[i] && A[j] < A[i])
			{
				D[i] = D[j] + 1;
				memo[i] = j;
			}
		}
	}
	int result = D[0];
	int p = 0;
	for (int i = 0; i < N; i++) {
		if (result < D[i])
		{
			result = D[i];
				p = i;
		}
	}
	
	printf("%d\n", result);
	go(p);

	return 0;
}