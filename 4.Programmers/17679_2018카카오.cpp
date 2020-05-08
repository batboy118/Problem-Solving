// Programmers
// no. 17679
// [1차] 프렌즈4블록
// https://programmers.co.kr/learn/courses/30/lessons/17679
// by JH (batboy118)

#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int check[32][32];
int height[32];
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    //각 열 초기 높이 index 저장
    for(int i = 0; i < n; i++){
        height[i] = m - 1;
    }
    while(1)
    {
        int flag = 1;

        //4개 만나는 모든 지점 탐색
        for(int i = m-1; i > 0; i--){
            for(int j = n-1; j > 0; j--){
                if(board[i][j] && board[i][j] == board[i - 1][j]
                && board[i][j-1] == board[i][j] && board[i-1][j-1] == board[i][j]){
                    flag = 0;
                    check[i][j] = 1;
                    check[i][j-1] = 1;
                    check[i-1][j] = 1;
                    check[i-1][j-1] = 1;
                }
            }
        }

        //갱신없으면 끝내기
        if(flag){
            break;
        }

        //터진 블럭 개수 세기 + 터진 부분 0으로 치환
        for(int i = n-1; i > -1; i--){
            for(int j = m - 1; j > m - height[i] - 2; j--){
                if(check[j][i]){
                    answer++;
                    board[j][i] = 0;
                }
            }
        }


        //블럭 내리기
        for(int i = n - 1; i > -1; i--){
            for(int j = m - 1; j > m - height[i] - 2; j--){
                if(board[j][i] == 0){
                    for(int k = j; k > m - height[i] - 1; k--){
                        board[k][i] = board[k - 1][i];
                    }
                    board[m - height[i] - 1][i] = 0;
                    height[i]--;
                    j++;   //동일 지점 다시 탐색하기 위해 ++해줌 (바로 위가 빈 블럭일 수 있으므로)
                }
            }
        }

        memset(check, 0, sizeof(check));

    }

    return answer;
}
