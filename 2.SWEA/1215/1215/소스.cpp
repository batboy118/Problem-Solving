#include<iostream>
#include<string>

using namespace std;


int main() {
	string str[8];
	int N, cnt;
	bool ok;

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		for(int i = 0; i < 8; i++) {
			cin >> str[i];
		}

		cnt = 0;
		ok = false;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8-N+1; j++) {
				for (int k = 0; k <= N / 2; k++) {
					if (str[i][j + k] != str[i][j + N - k -1]) {
						ok = false;
						break;
					}
					else { ok = true; }
				}
				if (ok) {
					cnt++;
					ok = false;
				}
				for (int k = 0; k <= N / 2; k++) {
					if (str[j+k][i] != str[j + N - k - 1][i]) {
						ok = false;
						break;
					}
					else { ok = true; }
				}
				if (ok) {
					cnt++;
					ok = false;
				}
		
			}
		}
		cout << '#' << tc << ' ' << cnt << endl;
	}
	return 0;
}