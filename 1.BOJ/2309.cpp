// BOJ
// no. 2309
// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
// by JH (batboy118)

#include <iostream>
#include <algorithm>

using namespace std;

int 	man[9];
int		count_ = 0;

int		search(int depth, int pre, int idx[])
{
	if(depth == 7)
	{
		count_++;
		int total = 0;
		for (int i = 0; i< 9; i++)
		{
			if(idx[i])
				total+=man[i];
		}
		if(total == 100)
		{
			for (int i = 0; i< 9; i++)
				if(idx[i])
					cout << man[i] <<'\n';
			return (1);
		}
		else
			return (0);
	}
	for (int i = pre; i < depth + 3; i++)
	{
		idx[i] = 1;
		if(search(depth+1, i + 1, idx))
			return (1);
		idx[i] = 0;
	}
	return (0);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i;
	int j;
	int idx[9] = {0, };

	for (i = 0; i< 9; i++)
		cin >> man[i];
	sort(man, man + 9);
	search(0, 0, idx);
	return (0);
}
