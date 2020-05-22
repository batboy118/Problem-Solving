#include <stdio.h>
#include <string.h>

#define DEL -1234567890

int N,M,T;
int cir[55][55];
int del_check[55][55];
int x, d, k;
int flag;
int cnt;

void rotate(int c){
	int cc = k;
	while(cc--){
		if(d == 0){
			int temp = cir[c][M];
			for(int i = M; i > 1; i--){
				cir[c][i] = cir[c][i - 1];
			}
			cir[c][1] = temp;
		}
		else{
			int temp = cir[c][1];
			for(int i = 1; i < M; i++){
				cir[c][i] = cir[c][i + 1];
			}
			cir[c][M] = temp;
		}
	}
}


void del(){
	//같은 원판 내에서 이웃 확인
	for(int i = 1; i < N + 1; i++){
		for(int j  = 1; j < M; j++){
			if(cir[i][j] != DEL && cir[i][j] == cir[i][j+1]){
				del_check[i][j] = 1;
				del_check[i][j + 1] = 1;
			}
		}
		if(cir[i][M] != DEL && cir[i][M] == cir[i][1]){
			del_check[i][1] = 1;
			del_check[i][M] = 1;
		}
	}
	//다른 원판 이웃 확인
	for(int i = 1; i < N; i++){
		for(int j  = 1; j < M + 1; j++){
			if(cir[i + 1][j] != DEL && cir[i + 1][j] == cir[i][j]){
				del_check[i + 1][j] = 1;
				del_check[i][j] = 1;
			}
		}
	}
	//이웃이 같은 값이면 제거
	for(int i = 1; i < N + 1; i++){
		for(int j  = 1; j < M + 1; j++){
			if(del_check[i][j])
			{
				flag = 1;
				cir[i][j] = DEL;
			}
		}
	}
}

int update(double num){
	for(int i = 1; i < N + 1; i++){
		for(int j  = 1; j < M + 1; j++){
			if(cir[i][j] != DEL && (double)cir[i][j] > num)
			{
				cir[i][j]--;
			}
			else if(cir[i][j] != DEL && (double)cir[i][j] < num){
				cir[i][j]++;
			}
		}
	}
}

int get_total(){
	int total = 0;
	for(int i = 1; i < N + 1; i++){
		for(int j  = 1; j < M + 1; j++){
			if(cir[i][j] != DEL)
			{
				cnt++;
				total += cir[i][j];
			}
		}
	}
	return total;
}

int main(){
	scanf("%d %d %d", &N, &M, &T);
	for(int i = 1; i < N + 1; i++){
		for(int j  = 1; j < M + 1; j++){
			scanf("%d", &cir[i][j]);
		}
	}
	while(T--){
		scanf("%d %d %d", &x, &d, &k);
		memset(del_check, 0, sizeof(del_check));
		for(int i = 1; x * i < N + 1; i++){
			rotate(x * i);
		}
		flag = 0;
		del();
		if(flag == 0){
			cnt = 0;
			double total = get_total();
			if(cnt == 0)
				break;
			update(total / (double)cnt);
		}
	}
	printf("%d", get_total());
	return 0;
}
