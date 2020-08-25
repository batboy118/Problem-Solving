#include<iostream>
#include<stack>

using namespace std;


int main() {
	int N;
	int map1[100];
	int map2[100];
	int temp;
	int result;
	stack<int> st;

	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc >> N;

		for (int i = 0; i < 99; i++) {
			map1[i] = -1;
			map2[i] = -1;
		}
		map1[99] = 1;
		map2[99] = 1;

		for (int i = 0; i < N; i++) {
			cin >> temp;
			if (map1[temp] == -1) {
				cin >> map1[temp];
			}
			else {
				cin >> map2[temp];
			}
		}

		st.push(map1[0]);
		if (map2[0] != -1) {
			st.push(map2[0]);
		}
		result = 0;
		while (!st.empty()) {

			temp = st.top();

			if (map1[st.top()] == 99 || map2[st.top()] == 99) {
				result = 1;
				break;
			}

			if (map1[temp]!= -1) {
				st.push(map1[temp]);
				map1[temp] = -1;

				if (map2[temp] != -1) {
					st.push(map2[temp]);
					map2[temp] = -1;
				}
			}
			else { st.pop(); }

			
		}

		cout << '#' << tc << ' ' << result << endl;
	}
	return 0;
}