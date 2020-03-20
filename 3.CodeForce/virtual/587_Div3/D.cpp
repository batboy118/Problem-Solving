#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int GetGCD(int u, int v)
{
       int t;

       while ( v )
       {
             t = u % v;
             u = v;
             v = t;
       }
       return u;
}


int		main()
{
	int i;
	int n;
	int temp;
	long long total = 0;
	int max;
	int max_cnt = 0;
	int count = 0;
	int stolen_type;
	int gcd;

	vector<int> gap;
	vector<int> sword;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> temp;
		sword.push_back(temp);
	}
	sort(sword.begin(),sword.end());
	max = sword[n - 1];
	for(i = 0; i < n; i++)
	{
		gap.push_back(max - sword[i]);
		if(gap[i] == 0)
		{
			max_cnt = n - i;
			break;
		}
		total += gap[i];
	}
	stolen_type = n - max_cnt;
	gcd = GetGCD(gap[0], gap[1]);
	for ( i = 2; i <stolen_type; ++i )
	 	gcd = GetGCD(gcd, gap[i]);
	for ( i = 2; i <stolen_type; ++i )
	 	gcd = GetGCD(gcd, gap[i]);

	cout << total/gcd <<' ' << gcd;
	return (0);
}
