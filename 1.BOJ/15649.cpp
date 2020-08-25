#include<iostream>
#define endl '\n'

using namespace std;

int N, M;
bool check[8] = { 0, };
int num[8];
int result[8];
void permu(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout <<result[i]<<' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < N; i++) {

		if (!check[i]) {
			check[i] = 1;
			result[depth] = num[i];
			permu(depth + 1);
			check[i] = 0;
		}
	}
	
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i <N; i++) {
		num[i] = i + 1;
	}
	permu(0);

	return 0;
}