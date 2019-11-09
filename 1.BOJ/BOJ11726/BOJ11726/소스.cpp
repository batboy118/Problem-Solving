#include<iostream>
#include<algorithm>

using namespace std;

int Arr[1001];

int main() {

	int N, temp;
	cin >> N;
	Arr[0] = 1;
	Arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		Arr[i] = (Arr[i - 1] + Arr[i - 2]) % 10007;;
	}

	cout << Arr[N]%10007;

	return 0;
}