#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int m[4];
int ans;
unsigned char mg[4];
int k;
int op[100];
int dir[100];
int d[4];

void rotate(int cur) {
	bool temp = d[cur] == 1 ? (mg[cur] & 1) : (mg[cur] & (1<<7));
	if (d[cur] == -1) {
		mg[cur] = mg[cur] << 1;
		if (temp) {
			mg[cur] = mg[cur] | 1;
		}
		else {
			mg[cur] = mg[cur] & 254;
		}
	}
	else{
		mg[cur] = mg[cur] >> 1;
		if (temp) {
			mg[cur] = mg[cur] | 128;
		}
		else {
			mg[cur] = mg[cur] & 127;
		}
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			if ((j + op[i])% 2 == 1) {
				d[j] = dir[i] * -1;
			}
			else {
				d[j] = dir[i];
			}
		};
		int flag[4] = { 0,0,0,0 };
		int cur = op[i] + 1;
		while (cur < 4) {
			if ((bool)(mg[cur - 1] & (1 << 5)) != (bool)(mg[cur] & (1 << 1))) {
				flag[cur] = 1;
				cur++;
			}
			else break;
		}
		cur = op[i] - 1;
		while (cur >= 0) {
			if ((bool)(mg[cur] & (1 << 5)) != (bool)(mg[cur + 1] & (1 << 1))) {
				flag[cur] = 1;
				cur--;
			}
			else break;
		}
		rotate(op[i]);
		cur = op[i] + 1;
		while (cur < 4) {
			if (flag[cur]){
				rotate(cur);
				cur++;
			}
			else break;
		}
		cur = op[i] - 1;
		while (cur >= 0) {
			if (flag[cur]) {
				rotate(cur);
				cur--;
			}
			else break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (mg[i] & (1 << 7)) {
			ans += pow(2, i);
		}
	}
}

int main(){
	cin >> m[0] >> m[1] >> m[2] >> m[3];
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> op[i] >> dir[i];
		op[i]--;
	}
	int cnt = 0;
	while(cnt < 8){
		for (int i = 0; i < 4; i++) {
			mg[i] = mg[i] | ((m[i] % 10) << cnt);
			m[i] = m[i] / 10;
		}
		cnt++;
	}
	solve();
	cout << ans;
	return 0;
}
