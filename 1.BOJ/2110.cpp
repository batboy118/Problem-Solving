// BOJ
// no. 2110
// 공유기 설치
// https://www.acmicpc.net/problem/2110
// by JH (batboy118)

#include <iostream>
#include <algorithm>

using namespace std;

int				main()
{
	int			n;
	int			c;
	int			a;
	int			gap;
	int			ans;
	int			min;
	int			max;
	int			pre_pos;
	int			count_wifi;
	int			x[200000];

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> c;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x, x+n);
	min = 1;							//간격의 최소값 설정
	max = x[n - 1] - x[0];				//간격의 최대값 설정
	ans = 1;
	while(min <= max)
	{
		gap = (min + max) / 2;			// 이분 탐색으로 비교할 gap을 구함 (gap은 '최소한' 지켜져야 하는 간격을 의미)
		pre_pos = x[0];					// x[0]위치에는 항상 공유기 설치 (기준점)
		count_wifi = 1;					// gap에서 설치 가능한 wifi의 수를 카운트 하는 변수, x[0]에 1개 설치
		for(int i = 1; i < n; i++) 		//x[1]부터 비교
		{
			if(x[i] - pre_pos >= gap) 	//바로 이전에 설치된 wifi와의 간격이 gap보다 크면 wifi 설치
			{
				count_wifi++;			//wifi를 설치했으므로, count++
				pre_pos = x[i];			//바로 이전 설치된 wifi의 좌표 업데이트
			}
		}
		if(count_wifi >= c)				// 간격이 gap이상일 떄 설치 가능한 wifi 갯수가 준비되 wifi의 수와 같거나 많은 경우
		{
			ans = gap;				// 최소 간격을 gap으로 updatae
			min = gap + 1;				// 더 큰 최소 간격이 가능한지, min 값을 gap+1로 변경
		}								// (min++을 하지 않는 이유는 2분 탐색을 하기 위함, 어차피 정답의 최소값은 gap보다는 크기 때문에 답이 현재의 ans+1(=gap+1)이라고 해도,
		else							// 어차피 다음 번에 else 조건에 걸리게 되어, max = gap -1이 계속해서 반복적으로 될 것이고, 결국에 gap이 현재의 ans + 1 까지 도달 할 것이다.)
		{
			max = gap - 1;				// 설치 가능한 wifi의 수가 준비된 wifi의 수보다 적을 경우 gap을 더 줄여 주어야 한다.
		}								// 더 큰 최소 간격이 가능한지, min 값을 gap+1로 변경
	}
	cout << ans;
	return (0);
}

/*
if(count_wifi >= c)
		{
			if(count_wifi == c)
				ans = gap;
			min = gap + 1;
		}
}

위 부분 처럼 `if(count_wifi == c)` 일 경우에만, ans값을 업데이트 해주지 않은 이유는 gap이상인 경우를 모두 따지기 때문에, c값과 동일한 경우가 존재하지 않을 수 있기 때문이다.
설치 가능한 와이파이의 수 c가 4일 경우 최소 간격 gap일 경우 설치가능한 wifi의 수가 4가 안나올 경우도 있기 때문이다.
아래의 예시가 그렇다. (gap = 2와 gap = 3일 경우 3-5를 왔다갔다 한다.)

공유기 수 = 4
0 1 2 3 4 5 6 7 8 9
+   +   + +   +   +
(집 :  0 2 4 5 7 9)

gap = (9 + 1) / 2 = 5 이면 와이파이는 3개 설치가능
gap = (8 + 1) / 2 = 4 이면 와이파이는 3개 설치가능
gap = (7 + 1) / 2 = 4 이면 와이파이는 3개 설치가능
gap = (6 + 1) / 2 = 3 이면 와이파이는 3개 설치가능
gap = (5 + 1) / 2 = 3 이면 와이파이는 3개 설치가능
gap = (4 + 1 ) / 2 = 2 이면 와이파이는 5개 설치가능
gap = (4 + 2 ) / 2 = 3 이면 와이파이는 3개 설치가능
gap = (3 + 2 ) / 2 = 2 이면 와이파이는 5개 설치가능
gap = (3 + 3 ) / 2 = 3 이면 와이파이는 3개 설치가능
*/
