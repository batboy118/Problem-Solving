//21,600KB	168MS	C++	1,983B
#define MAXN ((int)1e3 + 5)
#define MAXPOST ((int)1e5 + 5)
 
int M;  // total number of POST
int isFollow[MAXN][MAXN];
int result[11];
 
typedef struct _POST {
    int uID;    // user ID
    int time;   // timestamp
    int like;   // nubmer of like
} POST;
 
POST post[MAXPOST]; 
 
 
void init(int N)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            isFollow[i][j] = (i == j ? 1 : 0);
        }
    }
    M = 0;
}
 
void follow(int uID1, int uID2, int timestamp)
{
    isFollow[uID1][uID2] = 1;
}
 
void makePost(int uID, int pID, int timestamp)
{
    M++;    // increase the total number of POST
    post[M].uID = uID;
    post[M].time = timestamp;
    post[M].like = 0;
}
 
void like(int pID, int timestamp)
{
    post[pID].like++;
}
 
 
 
int min(int x, int y) {
    return x < y ? x : y;
}
 
 
int cmp(int pID1, int pID2) {
    if (post[pID1].like != post[pID2].like) 
        return post[pID1].like > post[pID2].like;
    return post[pID1].time > post[pID2].time;
}
 
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    int cnt = 0; // current number of POST
 
    for (int i = 0; i <= 10; i++) result[i] = -1;    // reset the result array
 
    for (int i = M; i >= 1; i--) {
        if (cnt >= 10 && (post[i].time < timestamp - 1000) ) break; // 10개 이상 && post[pID].timestamp < timestamp-1000 인 경우, 그냥 탈출
        if (!isFollow[uID][post[i].uID]) continue;                  // 조회 권한 없는 경우
         
         
        if (post[i].time < timestamp - 1000) result[cnt++] = i;      // 여기는 이미 10개 미만 경우임 && post[pID].timestamp < timestamp-1000 인 경우, 목록에 추가
        else {
            for (int j = min(cnt, 10) - 1; j >= 0; j--) {    // 여기는 이미 10개 미만 && timestamp 이내인 경우임 cmp 통해서 비교하여 insertion sort 필요
                if (cmp(i, result[j])) {    // 추가할 요소의 우선순위가 더 높은 경우
                    result[j + 1] = result[j];
                    result[j] = -1;
                }
                else {
                    result[j + 1] = i;
                    break;
                }
            }
            if (result[0] == -1) result[0] = i;
            cnt = min(cnt + 1, 10);
        }
         
     
    }
 
    for (int i = 0; i < min(cnt, 10); i++)   // 결과 옮겨 담기
        pIDList[i] = result[i];
}