#include<iostream>
#include<algorithm>

using namespace std;

int Arr[1000001];

int main() {

	int N, temp;
	cin >> N;
	Arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		Arr[i] = Arr[i - 1] + 1;
		if (i % 2 == 0)
		{
			temp= Arr[i / 2] + 1;
			Arr[i] = min(Arr[i], temp);
		}
		if (i % 3 == 0)
		{
			temp = Arr[i / 3] + 1;
			Arr[i]= min(Arr[i], temp);
		}
	}

	cout << Arr[N];

	return 0;
}