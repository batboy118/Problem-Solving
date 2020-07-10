#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	int list[N];
	for(int i = 0; i < N; i++){
		cin >> list[i];
	}
	sort(list, list + N);
	int t = 0;
	int total = 0;
	for(int i = 0; i< N; i++){
		t += list[i];
		total += t;
	}
	cout << total;
}
