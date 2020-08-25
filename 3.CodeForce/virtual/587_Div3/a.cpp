#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int		main()
{
	int i;
	int n;

	int count = 0;
	string str;

	cin >> n >> str;
	for(i = 0; i < n; i++)
	{
		if(str[i] == 'a')
		{
			i++;
			if(str[i] == 'a')
			{
				str[i] = 'b';
				count++;
			}
		}
		else
		{
			i++;
			if(str[i] == 'b')
			{
				str[i] = 'a';
				count++;
			}
		}
	}

	cout << count << '\n' << str;
	return (0);
}
