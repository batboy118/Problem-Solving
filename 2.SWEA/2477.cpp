#include<iostream>
#include<queue>

using namespace std;

int N, M; // N : 접수 창구, M : 정비 창구
int K; // 고객 수
int A, B;
struct info
{
    int a = 0;
    int b = 0;
    int t = 0;
} customer[10005];
queue<int> aq;
queue<int> bq;

int at[10];
int av[10];
int bt[10];
int bv[10];

void solve(){
	int done_cnt = 0;
	int time_cnt = customer[aq.front()].t;
	while(done_cnt != K){
		for(int i = 1; i <= A; i++){
			if(av[i]){
				customer[av[i]].t--;
				if(customer[av[i]].t == 0){
					bq.push(av[i]);
					av[i] = 0;
				}
			}
		}
		for(int i = 1; i <= A; i++){
			if(aq.empty()) break;
			if(time_cnt < customer[aq.front()].t) break;
			if(av[i] == 0){
				customer[aq.front()].a = i;
				customer[aq.front()].t = at[i];
				av[i] = aq.front();
				aq.pop();
			}
		}
		for(int i = 1; i <= B; i++){
			if(bv[i]){
				customer[bv[i]].t--;
				if(customer[bv[i]].t == 0){
					bv[i] = 0;
				}
			}
		}
		for(int i = 1; i <= B; i++){
			if(bq.empty()) break;
			if(bv[i] == 0){
				customer[bq.front()].b = i;
				customer[bq.front()].t = bt[i];
				bv[i] = bq.front();
				bq.pop();
				done_cnt++;
			}
		}
		time_cnt++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> A >> B >> K >> N >> M;
		for(int i = 1; i <= A; i++){
			cin >> at[i];
			av[i] = 0;
		}
		for(int i = 1; i <= B; i++){
			cin >> bt[i];
			bv[i] = 0;
		}
		for(int i = 1; i <=K; i++){
			cin >> customer[i].t;
			aq.push(i);
		}
		solve();
		int ans = 0;
		for(int i = 1; i <=K; i++){
			if(customer[i].a == N && customer[i].b == M)
				ans += i;
		}
		if(ans == 0) ans = -1;
		cout << '#' << test_case <<' ' << ans <<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}