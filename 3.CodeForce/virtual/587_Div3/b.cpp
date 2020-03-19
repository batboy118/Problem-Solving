#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int		main()
{
	int i;
	int n;
	int temp;
	int count = 0;
	vector<pair<int, int>>can;

	cin >> n;
	for(i = 1; i <=  n;i ++)
	{
		cin  >> temp;
		can.push_back(pair<int,int>(i, temp));
	}
	sort(can.begin(), can.end(), cmp);
	for(i = 0; i <  n; i ++)
	{
		count += ((can[i].second * (i) ) + 1);
	}
	cout << count << '\n';
	for(i = 0; i <  n;i ++)
	{
		cout <<can[i].first << ' ';
	}
	return (0);
}
