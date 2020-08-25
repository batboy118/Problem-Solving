#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define x1 0
#define y1 1
#define x2 2
#define y2 3

using namespace std;


int 	fn(int *w, int *b){
	if(w[x1] >= b[x1] && w[x2] <= b[x2])
	{
		if(w[y1] >= b[y1] && w[y2] <= b[y2])
		{
		//	cout <<"1 : " <<w[x1] << ' '<< w[y1] << ' '<< w[x2] << ' '<< w[y2] << '\n';
			return (-1);
		}
		else if(w[y2] >= b[y1] && w[y1] < b[y1] && w[y2] <= b[y2])
			w[y2] = b[y1];
		else if(w[y1] <= b[y2] && w[y2] > b[y2] && w[y1] >= b[y1])
			w[y1] = b[y2];
		if(w[y1] == w[y2] || w[x1] == w[x2])
		{
		//	cout <<"1-1 : " <<w[x1] << ' '<< w[y1] << ' '<< w[x2] << ' '<< w[y2] << '\n';
			return (-1);
		}
	}
	if(w[y1] >= b[y1] && w[y2] <= b[y2])
	{
		if(w[x1] >= b[x1] && w[x2] <= b[x2])
		{
		//	cout << "2 : "<< w[x1] << ' '<< w[y1] << ' '<< w[x2] << ' '<< w[y2] << '\n';
			return (-1);
		}
		else if(w[x2] >= b[x1] && w[x1] < b[x1] && w[x2] <= b[x2])
			w[x2] = b[x1];
		else if(w[x1] <= b[x2] && w[x2] > b[x2] && w[x1] >= b[x1])
			w[x1] = b[x2];
		if(w[x1] == w[x2] || w[y1] == w[y2])
		{
		//	cout << "2-1 : "<< w[x1] << ' '<< w[y1] << ' '<< w[x2] << ' '<< w[y2] << '\n';
			return (-1);
		}
	}

	return (0);
}


int		main()
{
	int i;
	int n;
	int temp;
	int count = 0;
	int w[4];
	int b1[4], b2[4];

	for(i = 0; i < 4; i++)
		cin >> w[i];
	for(i = 0; i < 4; i++)
		cin >> b1[i];
	for(i = 0; i < 4; i++)
		cin >> b2[i];
	if(fn(w,b1) == -1)
	{
		cout << "NO";
		return (0);
	}
	if(fn(w,b2) == -1)
	{
		cout << "NO";
		return (0);
	}
	cout << "YES";
	return (0);
}
