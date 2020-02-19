#include<iostream>

using namespace std;

int main() {
	int Arr[100][100];
	int N;
	int targetX;
	int startX;


	for (int i = 1; i <= 10; i++) {
		cin >> N;
		for (int j = 0; j <= 99; j++)
			for (int k = 0; k <= 99; k++) {
				cin >> Arr[j][k];
			}
		for (int j = 0; j <= 99; j++) {
			if (Arr[99][j] == 2) {
				targetX = j;
				break;
			}
		}
		int y = 99;
		int x = targetX;
		while (y > 0) {
			if (Arr[y][x - 1] == 1&& x - 1>=0) {
				while (Arr[y][x - 1] == 1 && x - 1 >= 0){
				x--;
				}
			}

			else if (Arr[y][x + 1] == 1 && x+1<100) {
				while (Arr[y][x + 1] == 1 && x + 1<100) {
					x++;
				}
			}
			startX = x;
			y--;
		}

		cout << "#" << N << " " << startX << endl;

	}
}