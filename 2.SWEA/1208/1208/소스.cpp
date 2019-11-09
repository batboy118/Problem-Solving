#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int hig[100];
	int N;
	int max = 99;
	int min = 0;

	for (int T = 1; T <= 10; T++) {
		cin >> N;

		for (int j = 0; j<100; j++) {
			cin >> hig[j];
		}

		sort(hig, hig + 100);

		max = 99;
		min = 0;

		for (int i = 0; i < N; i++) {
			if (hig[99] == hig[max] && hig[99] >= hig[max - 1])
				max = 99;
			else if (hig[99] < hig[max]) max = max;
			else max = max--;

			if (hig[0] == hig[min] && hig[0] <= hig[min + 1])
				min = 0;
			else if (hig[0] > hig[min]) min = min;
			else min = min++;

			hig[max]--;
			hig[min]++;

			if (hig[max] - hig[min] <= 1) {
				break;
			}
		}
		sort(hig, hig + 100);
		cout << '#' << T << ' ' << hig[99] - hig[0] << endl;


	}
	return 0;
}
