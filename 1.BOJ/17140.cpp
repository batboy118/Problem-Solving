#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int A[100][100];
int B[100];
int cnt = 0;
unsigned int rowMax = 3;
unsigned int colMax = 3;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void R() {
	for (int i = 0; i < rowMax; i++) {
		sort(A[i], A[i] + colMax);
		vector <pair<int, int>> temp;
		int idx = -1;
		for (int j = 0; j < colMax; j++) {
			if (A[i][j] == 0) continue;
			if (temp.empty() || temp[idx].first != A[i][j]) {
				idx++;
				temp.push_back(make_pair(A[i][j], 1));
			}
			else {
				temp[idx].second++;
			}
		}
		sort(temp.begin(), temp.end(), cmp);
		for (unsigned int j = 0; j < temp.size() && j < 100; j++){
			A[i][2 * j] = temp[j].first;
			A[i][2 * j + 1] = temp[j].second;
		}
		for (unsigned int j = temp.size() * 2; j < colMax && j < 100; j ++) {
			A[i][j] = 0;
		}
		if (temp.size() * 2 > colMax && temp.size() * 2 <= 100)
			colMax = temp.size() * 2;
	}
}

void C() {
	for (int i = 0; i < colMax; i++) {
		for (int j = 0; j < rowMax; j++) {
			B[j] = A[j][i];
		}
		sort(B, B + rowMax);
		vector <pair<int, int>> temp;
		int idx = -1;
		for (int j = 0; j < rowMax; j++) {
			if (B[j] == 0) continue;
			if (temp.empty() || temp[idx].first != B[j]) {
				idx++;
				temp.push_back(make_pair(B[j], 1));
			}
			else {
				temp[idx].second++;
			}
		}
		sort(temp.begin(), temp.end(), cmp);
		for (unsigned int j = 0; j < temp.size() && j < 100; j++) {
			A[j * 2][i] = temp[j].first;
			A[j * 2 + 1][i] = temp[j].second;
		}
		for (unsigned int j = temp.size() * 2; j < rowMax && j < 100; j++) {
			A[j][i] = 0;
		}
		if (temp.size() * 2 > rowMax && temp.size() * 2 <= 100)
			rowMax = temp.size() * 2;
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	r--;
	c--;
	while (1) {
		if (cnt > 100) {
			cout << -1;
			break;
		}
		else if (A[r][c] == k) {
			cout << cnt;
			break;
		}
		cnt++;
		if (rowMax >= colMax) {
			R();
		}
		else {
			C();
		}
	}
}
