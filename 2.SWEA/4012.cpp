#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int a[16][16];
int order[16];
vector<int> A;
vector<int> B;
int ans;
void solve(){
    int valA = 0;
    int valB = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            valA+=a[A[i]][A[j]];
        }
    }
    for(int i = 0; i < B.size(); i++){
        for(int j = 0; j < B.size(); j++){
            valB+=a[B[i]][B[j]];
        }
    }
    int diff = abs(valA - valB);
    if(ans > diff) ans = diff;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        for(int i = 0; i< N; i++)
            for(int j = 0; j< N; j++)
                cin>>a[i][j];
        fill(order, order + N/2, 0);
        fill(order + N/2, order + N, 1);
        ans = 1234567890;
        do{
            for(int i = 0 ; i < N; i ++){
                if(order[i]){
                    A.push_back(i);
                }
                else{
                    B.push_back(i);
                }
            }
            solve();
            A.clear();
            B.clear();
        }while(next_permutation(order, order + N));
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}