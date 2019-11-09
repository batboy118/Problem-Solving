#include <iostream>

using namespace std;

bool arr[51][101];
int code[15];
int ans;
int sum;
int r, c;
bool OK;

int matching(int val) {
	if (val == 1101)// 0001101
		return 0;
	if (val == 11001)//0011001
		return 1;
	if (val == 10011)//0010011
		return 2;
	if (val == 111101)
		return 3;
	if (val == 100011)
		return 4;
	if (val == 110001)
		return 5;
	if (val == 101111)
		return 6;
	if (val == 111011)
		return 7;
	if (val == 110111)
		return 8;
	if (val == 1011)
		return 9;
}





int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin>>arr[i][j];
			}
		}
		int si, li;
		int sj, lj;
		for (int i = r - 1; i >= 0; i--) {
			for (int j = c - 1; j >= 0; j--) {
				if (arr[i][j] == 1) {
					li = i;
					lj = j;
					break;
				}
			}
		}

		for (int j = lj; j >= 0; j -= 7) {
			if (arr[li][j] != 1) {
				sj = lj + 1;
				break;
			}
		}
		int idx = 0;
		for (int j = 0; lj >= j; j+=7) {
			int cnt = 1;
			int temp = 0;
			temp += arr[li][j];
			while (cnt<7) {
				temp *= 10;
				cnt++;
				temp += arr[li][j + cnt];
			}
			code[idx]=matching(temp);
			idx++;
		}

		int sum = 0;

		for (int i = 0; i < idx; i++) {
			sum += code[i];
			if (idx % 2 == 0) {
				sum += code[i]*2;
			}
		}

		if (sum % 10 == 0) {
			for (int i = 0; i < idx; i++) {
				if (idx % 2 == 0) {
					sum -= code[i] * 2;
				}
			}
		}
		
		else ans = 0;


		cout << '#' << tc << ' ' << ans<<endl;
	}
	return 0;
}