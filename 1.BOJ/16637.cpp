#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

int main() {
	vector<int> order(9);
	vector<char> v(19);
	queue <int> number;
	queue <char> oper;
	bool checkOrder[19] = { false };
	int N;
	int result = 0;
	int temp;
	bool cond;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N / 2; i++) {
		order[i] = (i * 2) + 1;
	}



	for(int i=0; i<(1<<N/2); i++){
		for (int j = 0; j < N / 2; j++) {
			if (i & (1 << j)) {
				checkOrder[j] = true;
			}
		}
		cond = 0;
		for (int j = 1; j < N-2; j += 2) {
			if (checkOrder[j] == checkOrder[j + 2]) {
				cond = 1;
				break;
			};
		}
		if (cond == 0) continue;

		number.push(v[0]);
		for (int j = 1; j < N; j += 2) {
			if (checkOrder[j]) {
				int tN = number.back();
				number.;
				switch (v[j]) {
				case '+':
					number.push(tN + v[j + 1]);
					break;
				case '-':
					number.push(tN - v[j + 1]);
					break;
				case '*':
					number.push(tN * v[j + 1]);
					break;
				}
			}
			else {
				oper.push(v[j]);
				number.push(v[j + 1]);
			}

		}

			temp = number.front();
			number.pop();
			while (!number.empty()) {
				if (oper.front() == '*') {
					temp *= number.front();
					number.pop();
					oper.pop();
				}
				else if (oper.front() == '/') {
					temp /= number.front();
					number.pop();
					oper.pop();

				}
				else if (oper.front() == '+') {
					temp += number.front();
					number.pop();
					oper.pop();

				}
				else if (oper.front() == '-') {
					temp -= number.front();
					number.pop();
					oper.pop();
				}
			}
			if (temp > result) {
				result = temp;
			}

			for (int j = 0; j < N / 2; j++) {
				checkOrder[j] = false;
			}
			}
		}
}