#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

bool desc(int a, int b) {
	return a > b;
}

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int K;
	int answer;
	string str;
	vector <int> strToInt;
	int setOfnum[28];
	freopen("sample_input.txt", "r", stdin);

	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		cin >> str;
		int lenOfnum = N / 4;

		strToInt.clear();
		
		for (int i = N-1; i >= 0; i--) {
			if (str[i] <= '9' && str[i] >= '0') strToInt.push_back(str[i] - '0');
			else strToInt.push_back( (str[i] - 'A') + 10);
		}

		for (int i = 0; i < N; i++) setOfnum[i] = 0;

		for (int i = 0; i < N; i++) {
				int k = 1;
			for (int j = 0; j < lenOfnum; j++) {
				
				if (N <= i+j) {
					setOfnum[i]+= (strToInt[i + j - N] * k);
				}
				else {
					setOfnum[i] += (strToInt[i + j] * k);
				}

				k *= 16;

				}
			}

		sort(setOfnum, setOfnum+N, desc);

		int cnt = 1;
		if (K == 1) { answer = setOfnum[0];}
		else {
			for (int i = 1; i < N; i++) {
				if (setOfnum[i] != setOfnum[i - 1]) { cnt++; }
				if (cnt == K) {
					answer = setOfnum[i];
					break;
				}
			}
		}
		
		cout << '#' << test_case << ' ' << answer << '\n';;

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}