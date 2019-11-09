#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;


int main() {
	int T;
	int N;
	int x;
	int n;
	int result;
	string s;
	stack <char> st;
	
	 

	for (int tc = 1; tc <= 10; tc++) {

		cin >> N >> s;
		result = 1;
		for (int i = 0; i < N; i++) {
			if(s[i]=='{' || s[i] == '[' || s[i] == '(')
				st.push(s[i]);

			else {
				if(st.empty()){
					result = 0;
					break;
				}

				if (s[i] == '}') {
					if (st.top() == '{')
						st.pop();
					else {
						result = 0;
						break;
					}
				}

				else if (s[i] == ']') {
					if (st.top() == '[')
						st.pop();
					else {
						result = 0;
						break;
					}
				}

				else if (s[i] == ')') {
					if (st.top() == '(')
						st.pop();
					else {
						result = 0;
						break;
					}
				}

			}

			
		}
		

		cout << '#' << tc << ' ' << result << '\n';
	}
}