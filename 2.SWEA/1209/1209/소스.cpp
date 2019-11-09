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
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j <= 99; j++) sum1 += Arr[j][j];
		int max = sum1;
		
		for (int j = 0; j <= 99; j++) sum2 += Arr[99 - j][j];
		if (max < sum2) max = sum2;

		int temp1, temp2;
		for (int j = 0; j <= 99; j++) {
			temp1 = 0; temp2 = 0;
			for (int k = 0; k <= 99; k++) {
				temp1 += Arr[k][j];
				temp2 += Arr[j][k];
			}
			if (max < temp1) max = temp1;
			if (max < temp2) max = temp2;
		}

		cout << "#" << N << " "<<max<<endl;

	}
}