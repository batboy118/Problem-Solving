#include<iostream>
#include<limits.h>

using namespace std;

int N;
int num[12];
int cnt[4];
int max_val;
int min_val;

void solve(int depth, int val){
    if(depth == N){
        if(max_val < val) max_val = val;
        if(min_val > val) min_val = val;
        return;
    }
    if(cnt[0] > 0){
        cnt[0]--;
        solve(depth + 1, val + num[depth]);
        cnt[0]++;
    }
    if(cnt[1] > 0){
        cnt[1]--;
        solve(depth + 1, val - num[depth]);
        cnt[1]++;
    }
    if(cnt[2] > 0){
        cnt[2]--;
        solve(depth + 1, val * num[depth]);
        cnt[2]++;
    }
    if(cnt[3] > 0){
        cnt[3]--;
        solve(depth + 1, val / num[depth]);
        cnt[3]++;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        max_val = INT_MIN;
        min_val = INT_MAX;
        cin >> N;
        for(int  i = 0; i < 4; i++){
            cin >> cnt[i];
        }
        for(int i = 0; i < N; i++)
            cin >> num[i];
        solve(1, num[0]);
        cout << "#" << test_case << " " << (max_val - min_val) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}