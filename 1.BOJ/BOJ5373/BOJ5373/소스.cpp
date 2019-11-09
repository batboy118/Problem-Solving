#include<iostream>

#define endl '\n'

using namespace std;
char G1[3] = { 'L','U','F' };
char G2[3] = {'R', 'D', 'R' };
char top[3][3];
char bottom[3][3];
char front[3][3];
char back[3][3];
char left[3][3];
char right[3][3];
char Surface;
char Dir;
int N;


int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		char top[3][3] = { { 'w','w','w' },{ 'w','w','w' },{ 'w','w','w' } };
		char bottom[3][3] = { { 'y','y','y' },{ 'y','y','y' },{ 'y','y','y' } };
		char front[3][3] = { { 'r','r','r' },{ 'r','r','r' },{ 'r','r','r' } };
		char back[3][3] = { { 'o','o','o' },{ 'o','o','o' },{ 'o','o','o' } };
		char left[3][3] = { { 'g','g','g' },{ 'g','g','g' },{ 'g','g','g' } };
		char right[3][3] = { { 'b','b','b' },{ 'b','b','b' },{ 'b','b','b' } };
		cin >> N;

		while (--N) {
			cin >> Surface >> Dir;
			switch (Surface)
			{
			case 'U' :
				UP
				break;
			case 'F' :
				break;
			case 'R':
				break;
			case 'B':
				break;
			case 'L':
				break;
			case 'D':
				break;
			default:
				break;
			}

		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << top[i][j];
			}
			cout << top[i][j] << '\n';
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}