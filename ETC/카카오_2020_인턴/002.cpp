#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
	vector<int> op = {-3, -2, -1};
	// -1 : *, -2 : +; -3 : - ;
	vector <long long> exp;

	int idx = 0;
	for(int i = 0; i < expression.size(); i++){
		if(i == expression.size() - 1){
			exp.push_back(atoi(expression.substr(idx, i - idx + 1).c_str()));
		} else if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
			exp.push_back(atoi(expression.substr(idx, i - idx).c_str()));
			idx = i + 1;
			if(expression[i] == '*') exp.push_back(-1);
			else if(expression[i] == '+') exp.push_back(-2);
			else if(expression[i] == '-') exp.push_back(-3);
		}
	}
	// for(int i = 0; i < exp.size(); i++){
	// 	cout << exp[i] << ' ';
	// }

	do{
//cout << op[0] << endl;
		vector<long long> temp;
		for(int i = 0; i < exp.size(); i++){
			temp.push_back(exp[i]);
		}
			int count = -1;
		while(++count < 3){
//cout << count << endl;
			for(int i = 0; i < temp.size(); i++){
				if(i%2 && op[count] == temp[i]){
					long long left = temp[i - 1];
					long long right = temp[i + 1];
					long long res;
					if(op[count] == -1){
						res = left * right;
					} else if (op[count] == -2){
						res = left + right;
					} else{
						res = left - right;
					}
					temp[i - 1] = res;
//cout << op[count] << ':'<< res << endl;
					temp.erase(temp.begin() + i, temp.begin() + i + 2);
					i--;
				}
			}
		}
//cout << "temp[0] : "<<temp[0] <<endl;
//cout << "exp[0] : "<<exp[0]<<endl;
		if(abs(temp[0]) > answer)
			answer = abs(temp[0]);
	}while(next_permutation(op.begin(),op.end()));

    return answer;
}

int main()
{
	solution("100-200*300-500+20");
}
