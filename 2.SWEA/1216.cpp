#include<iostream>
#include<string>

using namespace std;


int main() {
	string str[100];
	int N, max;
	bool ok;

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		for (int i = 0; i < 100; i++) {
			cin >> str[i];
		}

		max = 0;
		ok = false;

		for (int L = 1; L <= 100; L++) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100 - L + 1; j++) {

					for (int k = 0; k <= L / 2; k++) {
						if (str[i][j + k] != str[i][j + L - k - 1]) {
							ok = false;
							break;
						}
						else { ok = true; }
					}
					if (ok) {
						if (L > max) {
							max = L;
						}
						ok = false;
					}

					for (int k = 0; k <= L / 2; k++) {
						if (str[j + k][i] != str[j + L - k - 1][i]) {
							ok = false;
							break;
						}
						else { ok = true; }
					}
					if (ok) {
						if (L > max) {
							max = L;
						}
						ok = false;
					}
					
				}
			}
		}
		cout << '#' << tc << ' ' << max << endl;
	}
	return 0;
}