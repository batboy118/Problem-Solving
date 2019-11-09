#include<iostream>
#define endl '\n'

using namespace std;

int N, M;
bool check[8] = { 0, };
int num[8];
int result[8];

void Re_combi(int id, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		return;
	}
	if (id >= N) return;

	for (int i = id; i < N; i++)
	{
		result[depth] = num[i];
		Re_combi(i, depth + 1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i <N; i++) {
		num[i] = i + 1;
	}
	Re_combi(0, 0);

	return 0;
}