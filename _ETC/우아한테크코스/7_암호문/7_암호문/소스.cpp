#include <iostream>
#include <string>

using namespace std;


string solution(string str) {
	bool canReduce = true;
	
	while (canReduce) {
		canReduce = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == str[i+1]) {
				int j;
				for (j = 1; j < str.size() - i; j++) {
					if (str[i] != str[i + j]){
						j;
						break;
					}
				}
				str.erase(i, j);
				i--;
				canReduce = true;
			}

		}
	}


	return str;
}


int main() {

	string str = "browoanoommnaon";


	cout << solution(str);


	return 0;
}