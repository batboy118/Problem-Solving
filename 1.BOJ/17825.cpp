#include <iostream>
#include <string.h>


using namespace std;

int val[10]; // 주사위 던진 값
int ans = 0;
int order[10]; //각 주사위 값에 대한 말 번호 저장
int location[4]; // 현재 각 말의 위치
int finished[4]; // 각 말이 도착지접에 왔는지 chek (1: 도착)
int useInnerMap[4]; // 각 말이 가운데 맵으로 들어왔는지  check (1이면 중앙으로 진입)
int score = 0;

//중복위치 체크
int check_same_location(int n){
	if(n == 20 || n == 107 || n == 206 || n == 307 ){
		for(int i = 0; i<4; i++){
			if(finished[i] ==0 && (location[i] == 20 || location[i] == 107 || location[i] == 206 || location[i] == 307)) return 1;
		}
		return 0;
	}
	if(n < 100){
		if(n < 20 && n % 5 == 0)
			n = (n / 5) * 100;
		for(int i = 0; i<4; i++){
			if(finished[i] == 0 && n == location[i]) return 1;
		}
	} else{
		if((n < 200 && n > 103) || (n < 300 && n > 202) || n >=303){
			if(n < 300 && n > 202)
				n++;
			for(int i = 0; i<4; i++){
				if(finished[i] ==0){
					if(location[i] > 200 && location[i] < 300){
						if(n % 100 == (location[i] + 1) % 100) return 1;
					}
					else if (location[i] > 100){
						if(n % 100 == (location[i]) % 100) return 1;
					}
				}
			}
		}
		else{
			for(int i = 0; i<4; i++){
				if(finished[i] ==0 && n == location[i]) return 1;
			}
		}
	}
	return 0;
}

//중앙 진입한 경우 이동 처리
int innerMove(int i, int token){
	int checkNum = (location[token] + val[i]) % 100 ;
	if(checkNum >= 4 || (location[token] + val[i] > 202 && location[token] + val[i] < 300)){
		if(check_same_location(location[token] + val[i]))
			return 0;
		location[token] = location[token] + val[i];
		if(checkNum >= 8 || (location[token] > 206 && location[token] < 300))
			finished[token] = 1;
		else if(location[token] > 200 && location[token] < 300){
			int temp = 20 + (checkNum - 2) * 5;
			score += temp;
		}
		else{
			int temp = 20 + (checkNum - 3) * 5;
			score += temp;
		}
	}
	else{
		if(check_same_location(location[token] + val[i]))
			return 0;
		location[token] += val[i];
		int temp;
		if(location[token] < 200){
			temp = 10 + checkNum * 3;
		} else if(location[token] < 300){;
			temp = 20 + checkNum * 2;
		} else if(location[token] < 400){
			if(location[token] == 301) temp = 28;
			else if(location[token] == 302) temp = 27;
			else if(location[token] == 303) temp = 26;
		}
		score += temp;
	}
	return 1;
}

void play(){
	score = 0;
	memset(location, 0, sizeof(location));
	memset(finished, 0, sizeof(finished));
	memset(useInnerMap, 0, sizeof(useInnerMap));
	for(int i = 0; i < 10; i++){
		int token = order[i];
		if(finished[token]) return; // 도착한 말이 선택되었으면 리턴;
		if(useInnerMap[token]){   // 가운데 맵으로 진입한 경우
			if(innerMove(i, token) == 0){
				return; // 중복위치를 선택하면 리턴;
			};
		} else {  // 외곽으로 이동하는 경우
			if(check_same_location(location[token] + val[i])) return; // 중복위치를 선택하면 리턴;
			location[token] += val[i];
			if(location[token] > 20){ //도착했으면 finished = 1 로 변경
				finished[token] = 1;
			}
			else{
				if(location[token] < 20 && location[token] % 5 == 0){   // 가운데로 가는 길목이면 useInnerMap =1 세팅
					useInnerMap[token] = 1;
					score += location[token] * 2;
					if(location[token] == 5) location[token] = 100;    //5번째 칸(10점 칸)에 도착하면, 100으로 위치 수정
					else if(location[token] == 10) location[token] = 200; //10번째 칸(20점 칸)에 도착하면, 200으로 위치 수정
					else if(location[token] == 15) location[token] = 300; //15번째 칸(30점 칸)에 도착하면, 300으로 위치 수정
				}
				else{
					score += location[token] * 2;
				}
			}
		}
	}
	if(score > ans)
		ans = score;
}

//말을 움직일 순서 저장
void set_order(int depth){
	if(depth == 10){
		play();
		return;
	}
	for(int i = 0;  i < 4 ;i++){
		order[depth] = i;
		set_order(depth + 1);
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 10; i++)
		cin >> val[i];
	set_order(0);
	cout << ans << "\n";
	return 0;
}
