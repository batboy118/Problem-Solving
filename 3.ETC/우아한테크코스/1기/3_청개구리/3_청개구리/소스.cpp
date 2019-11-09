#include<iostream>
#include<string>

using namespace std;

string solution(string word) {
	string ans;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			ans += 'Z' - word[i] + 'A';
		}
		else if (word[i] >= 'a' && word[i] <= 'z') {
			ans += 'z' - word[i] + 'a';
		}
		else ans += word[i];
	}

	return ans; 
}


int main() {

	string word = "I love you";
	cout<<solution(word);

	return 0;
}