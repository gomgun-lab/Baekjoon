#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {
	int N, K, W, V, MAX, weight, value;

	cin >> N >> K;

	N = N + 1;
	K = K + 1;

	int** BackPack = new int* [N];
	int** Product = new int* [N];

	for (int i = 0; i < N; i++) BackPack[i] = new int[K];

	for (int i = 0; i < N - 1; i++) Product[i] = new int[2];
	for (int i = 0; i < N - 1; i++) cin >> Product[i][0] >> Product[i][1];

	for (int i = 0; i < N - 1; i++) {
		weight = Product[i][0], value = Product[i][1];
		for (int j = 0; j < K; j++) {
			if (j < weight) { 
				if (i == 0) BackPack[i][j] = 0;
				else BackPack[i][j] = BackPack[i - 1][j];
			}
			else {
				if (i == 0) BackPack[i][j] = value;
				else BackPack[i][j] = max(BackPack[i - 1][j], BackPack[i - 1][j - weight] + value);
			}
		}
	}

	printf("%d ", BackPack[N - 2][K - 1]);
	
	return 0;
}