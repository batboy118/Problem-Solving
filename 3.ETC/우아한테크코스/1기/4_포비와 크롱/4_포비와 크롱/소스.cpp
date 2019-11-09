#include <iostream>

#define POBI 1
#define CRONG 2
#define DRAW 0

using namespace std;

int solution(int pobi[], int crong[]) {
	int ans;

	if ((pobi[0] + 1 != pobi[1]) || (crong[0] + 1 != crong[1])) return -1;
	if ( (crong[0]+1) % 2 || crong[1] % 2 || (pobi[0] + 1) % 2 || pobi[1] % 2) return -1;
	if ((pobi[0] == 0 || pobi[1] ==400 ) || (crong[0] == 0 && crong[1] == 400)) return -1;

	int pmax=0; 
	int cmax=0;
	int temp;
	int ptemp = 0;
	int ctemp = 0;
	int p_cnt[2] = { 0,0 };
	int c_cnt[2] = { 0,0 };

	int cnt = 3;
	for (int i = 100; i > 0; i /= 10) {
		for (int j = 0; j < 2; j++) {

			if (p_cnt[j] == 0 && (pobi[j] / i) != 0) {
				p_cnt[j] = cnt;
			}
			if (c_cnt[j] == 0 && (crong[j] / i) != 0) {
				c_cnt[j] = cnt;
			}
		}
		cnt--;
	}

//	for (int j = 0; j < 2; j++) {
//		cout <<"crong cnt : "<< c_cnt[j]<<' '<<endl;
//		cout << "pobi cnt : " << p_cnt[j] << ' ' << endl;
//	}

	for (int i = 0; i < 2; i++) {
		ptemp = pobi[i];
		ctemp = crong[i];
		temp = 0;
		for (int j = 0; j < p_cnt[i]; j++) {
			temp += ptemp % 10;
			ptemp /= 10;
		}
//		cout <<"pobi + "<<i <<" : "<< temp << endl;
		if (temp > pmax) pmax = temp;
		temp = 0;
		for (int j = 0; j < c_cnt[i]; j++) {
			temp += ctemp % 10;
			ctemp /= 10;
		}
//		cout << "crong + " << i << " : " << temp << endl;
		if (temp > cmax) cmax = temp;
	}

	for (int i = 0; i < 2; i++) {
		ptemp = pobi[i];
		ctemp = crong[i];
		temp = 1;
		for (int j = 0; j < p_cnt[i]; j++) {
			temp *= ptemp % 10;
			ptemp /= 10;
		}
//		cout << "pobi * " << i << " : " << temp << endl;
		if (temp > pmax) pmax = temp;
		temp = 1;
		for (int j = 0; j < c_cnt[i]; j++) {
			temp *= ctemp % 10;
			ctemp /= 10;
		}
//		cout << "crong * " << i << " : " << temp << endl;
		if (temp > cmax) cmax = temp;
	}
	

	if (cmax > pmax) ans = CRONG;
	else if (cmax < pmax) ans = POBI;
	else ans = DRAW;

	return ans;
}



int main() {

	int pobi1 []  = { 97, 98 };
	int crong1[]  = { 197, 198 };
	int pobi2 []  = { 131, 132 };
	int crong2[]  = { 211, 212 };
	int pobi3[]  = { 99, 103 };
	int crong3[]  = { 211, 212 };

	cout << solution(pobi1, crong1)<<endl;
	cout << solution(pobi2, crong2)<<endl;
	cout << solution(pobi3, crong3)<<endl;


	return 0;
}