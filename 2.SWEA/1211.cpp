#include<iostream>

using namespace std;

int main() {
	int Arr[100][100];
	int N;


	for (int i = 1; i <= 10; i++) {
		cin >> N;
		for (int j = 0; j <= 99; j++)
			for (int k = 0; k <= 99; k++) {
				cin >> Arr[j][k];
			}
		
		int y;
		int x;
		int minX = 0;
		int cnt_;
		int min = 9999999;

		for (int z = 0; z < 100; z++) {
			y = 0;
			x = z;
			cnt_ = 0;
			if (Arr[0][x] == 1) {
				while (y < 99) {
					if (Arr[y][x - 1] == 1 && x - 1 >= 0) {
						while (Arr[y][x - 1] == 1 && x - 1 >= 0) {
							x--;
							cnt_++;
						}
					}

					else if (Arr[y][x + 1] == 1 && x + 1 < 100) {
						while (Arr[y][x + 1] == 1 && x + 1 < 100) {
							x++;
							cnt_++;
						}
					}
					y++;
					cnt_++;
				}
			}
			if (cnt_ < min && y == 99) {
				min = cnt_;
				minX = z;
			}
		}
		cout << "#" << N << " " << minX << endl;

	}
}