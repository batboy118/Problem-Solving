#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
vector <long> op;
string ex;
int ans = INT_MIN;

long cal(int a, int b, char op) {
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

void sol(int sum, int idx) {
	if (idx + 2 >= N) {
		if (sum > ans) ans = sum;
		return;
	}
	int val = cal(sum, op[idx + 2], op[idx + 1]);
	sol(val, idx + 2);
	if (idx + 4 < N) {
		val = cal(op[idx + 2], op[idx + 4], op[idx + 3]);
		val = cal(sum, val, op[idx + 1]);
		sol(val, idx + 4);
	}
}

int main() {
	cin >> N >> ex;
	for (int i = 0; i < N; i++) {
		if(i % 2 ==0)
		op.push_back(ex[i] - '0');
		else {
			op.push_back(ex[i]);
		}
	}
	sol(op[0], 0);
	cout << ans;
	return 0;
}
