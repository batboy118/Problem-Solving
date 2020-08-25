#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){ return a > b; }

int main(){
    int M, N;
    cin >> N >> M;
	int P[M];
    for(int i = 0; i < M; i++) cin >> P[i];
    sort(P, P + M, desc);
	int total = 0;
	int val = 0;
	for(int i = 0; i < N ; i++){
		int temp = (i + 1) * P[i];
		if(temp >= total){
			val = P[i];
			total = temp;
		}
	}
	cout << val << ' ' << total;
}
