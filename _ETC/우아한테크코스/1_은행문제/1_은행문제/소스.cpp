#include <iostream>
# define CHANGE_LIST 50000, 10000, 5000, 1000, 500, 100, 50, 10, 1
# define NUM_OF_CHANGE 9

using namespace std;

int main() {

	int money;
	int answer[NUM_OF_CHANGE] = { 0, };
	int change_list[NUM_OF_CHANGE] = { CHANGE_LIST };

	cout<< "돈을 입력하세요 : ";
	cin >> money;

	for (int i = 0; i < NUM_OF_CHANGE; i++) {
		if (money >= change_list[i]) {
			answer[i] = money/ change_list[i];
			money %= change_list[i];
		}
	}
	for (int i = 0; i < NUM_OF_CHANGE; i++) {
		cout << answer[i] <<' ';
	}

	return 0;
}