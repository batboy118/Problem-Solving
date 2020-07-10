#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    map <string, int> m;
    int N;
	cin >> N;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        if(m[temp]) m[temp]++;
        else m[temp] = 1;
    }
    map <string, int>::iterator i;
    int max = 0;
    string ans;
    for(i = m.begin(); i != m.end(); i++){
        if(i->second > max){
            max = i->second;
            ans = i->first;
        }
        else if(i->second == max){
            string t = i->first;
            int flag = 0;
            for(int j = 0; j < t.length() && j < ans.length(); j++){
                if(t[j] < ans[j]){
                    ans = t;
                    flag = 1;
                    break;
                }
                else if(t[j] > ans[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && t.length() < ans.length()) ans = t;
        }
    }
	cout << ans;
    return 0;
}
