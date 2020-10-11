#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue <pair<int,int>> q;
	q.push(make_pair(1,2));
	cout << q.front().first;
}
