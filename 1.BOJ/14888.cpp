#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
int add_n;
int sub_n;
int div_n;
int mul_n;
int MIN = INT_MAX;
int MAX = INT_MIN;
int num[11];
int op[10];

void cal(){
    int res = num[0];
    for(int i = 0 ; i < N - 1; i++){
        if(op[i] == 1)
            res += num[i + 1];
        else if(op[i] == 2)
            res -= num[i + 1];
        else if(op[i] == 3)
            res *= num[i + 1];
        else
            res /= num[i + 1];
    }
    if(res > MAX){
        MAX = res;
    }
    if(res < MIN){
        MIN = res;
    }
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
        cin >> num[i];
	}
    cin >> add_n >> sub_n >> mul_n >> div_n;
    for(int i = 0; i < add_n; i++){
        op[i] = 1;
    }
    for(int i = 0; i < sub_n; i++){
        op[i + add_n] = 2;
    }
    for(int i = 0; i < mul_n; i++){
        op[i + add_n + sub_n] = 3;
    }
    for(int i = 0; i < div_n; i++){
        op[i + add_n + sub_n + mul_n] = 4;
    }
    do{
        cal();
    }while(next_permutation(op, op + N - 1));
	cout << MAX << "\n";
    cout << MIN << "\n";
	return 0;
}
