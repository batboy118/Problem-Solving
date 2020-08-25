#include<iostream>
#include <cstdio>

using namespace std;

int tip[5] = { 0, };
int tiptip;
int k,n;
int temp,temp2;
int x;
int to[5] = { 0, };

void moveRight(int loca, int dir) { 
	temp = 0;
	temp2 = 0;
	
	if (loca <= 4) 
	{
		if (dir == 1) {
			int ttemp = 0;
			if (tip[loca] & 128)
				ttemp = 1;
			temp = tip[loca] & (1 << 2);
			temp2 = tip[loca + 1] & (1 << 6);
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] << 1;
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] | ttemp;
			if ((temp>>2)^(temp2>>6) && loca!= 4) {
				moveRight(loca + 1, -1 );
			}
		}
		else 
		{
			int ttemp = 0;
			if (tip[loca] & 1)
				ttemp = 128;
			temp = tip[loca] & (1 << 2);
			temp2 = tip[loca + 1] & (1 << 6);	
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] >> 1;
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] | ttemp;
			if ((temp >> 2) ^ (temp2 >> 6) && loca!=4) {
				moveRight(loca + 1, 1);
			}
		}
	}
	return;
}

void moveLeft(int loca, int dir) {
	temp = 0;
	temp2 = 0;

	if (loca == x)
		tip[loca] = tiptip;

	if (loca >= 1)
	{
		if (dir == 1) {
			int ttemp = 0;
			if (tip[loca] & 128)
				ttemp = 1;
			temp = tip[loca] & (1 << 6);
			temp2 = tip[loca - 1] & (1 << 2);
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] << 1;
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] | ttemp;
			if ((temp >> 6) ^ (temp2 >> 2) && loca!=1) {

				moveLeft(loca - 1, -1);
			}
		}
		else{
			int ttemp = 0;

			if (tip[loca] & 1)
				ttemp = 128;
			temp = tip[loca] & (1 << 6);
			temp2 = tip[loca - 1] & (1 << 2);
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] >> 1;
			tip[loca] = tip[loca] & 0xFF;
			tip[loca] = tip[loca] | ttemp;
			if ((temp >> 6) ^ (temp2 >> 2) && loca != 1) {
				
				moveLeft(loca - 1, 1);
			}
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> k;
		for (int j = 1; j <= 4; j++) {
				tip[j] = 0;
			}
		for (int j = 1; j <= 4; j++) {
			for (int i = 0; i < 8; i++) {
				cin >> temp;
				tip[j] = tip[j] | (temp << i);
			}
		}
		for (int i = 0; i < k; i++) {
			cin >> x;
			tiptip = tip[x];
			cin >> to[x];
			moveRight(x, to[x]);
			moveLeft(x, to[x]);
		}
		int total = 0;
		if (tip[1] & 1)
			total += 1;
		if (tip[2] & 1)
			total += 2;
		if (tip[3] & 1)
			total += 4;
		if (tip[4] & 1)
			total += 8;
		cout << '#' << test_case << ' ' << total<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}