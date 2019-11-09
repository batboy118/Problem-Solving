#include <iostream>

using namespace std;

int solution(int number) {
	int cnt = 0;
	for (int i = 3; i <= number; i++) {
		int temp = i;
		for (int j = 0; j < 4 ; j++) {
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) cnt++;
			if((temp /= 10) == 0) break;
		}
	}
	return cnt;
}



int main() {

	int a = 13;
	int b = 33;
	int c = 50;

	cout << solution(a) << endl;
	cout << solution(b) << endl;
	cout << solution(c) << endl;

	return 0;
}