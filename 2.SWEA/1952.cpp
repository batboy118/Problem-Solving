#include<iostream>

using namespace std;

int day, one_month, three_month, one_year;
int plan[13];
int min_val[13];
int temp;
int ans;

void solve(int depth) {
	if (depth >= 13) {
		if (ans > temp) {
			ans = temp;
		}
		return;
	}
	temp += min_val[depth];
	solve(depth + 1);
	temp -= min_val[depth];
	temp += three_month;
	solve(depth + 3);
	temp -= three_month;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> day >> one_month >> three_month >> one_year;
		for (int i = 1; i < 13; i++) {
			cin >> plan[i];
		}
		temp = 0;
		ans= one_year;
		for (int i = 1; i < 13; i++) {
			if (one_month < day * plan[i]) {
				min_val[i] = one_month;
			}
			else {
				min_val[i] = day * plan[i];
			}
		}
		solve(1);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
