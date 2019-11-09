#include<iostream>
#include<string>

using namespace std;


int main() {
	string str;
	int N, cnt;
	string pas;
	bool ok;

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		cin >> pas;
		cin >> str;
		cnt = 0;
		ok = false;

		for (int i = 0; i <= str.length() - pas.length(); i++) {
			for (int j = 0; j < pas.length(); j++) {
				if (str[i + j] != pas[j]) {
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
		cout << '#' << N << ' ' << cnt << endl;
	}
	return 0;
}