#include <iostream>

using namespace std;

int main() {

	int hig[1000];
	int counting;
	int N;
	for (int T = 1; T <= 10; T++) {
		cin >> N;
		counting = 0;
		for (int j = 0; j<N; j++) {
			cin >> hig[j];
		}

		for (int i = 2; i<N - 2; i++) {
			if (hig[i] <= hig[i - 1] || hig[i] <= hig[i - 2] || hig[i] <= hig[i + 1] || hig[i] <= hig[i + 2])
				continue;
			else {
				int temp = hig[i - 1];
				if (temp < hig[i - 2]) temp = hig[i - 2];
				if (temp < hig[i + 1]) temp = hig[i + 1];
				if (temp < hig[i + 2]) temp = hig[i + 2];
				counting += (hig[i]-temp);
			}
		}

		cout << '#' << T << ' ' << counting << endl;
	}
	return 0;
}
