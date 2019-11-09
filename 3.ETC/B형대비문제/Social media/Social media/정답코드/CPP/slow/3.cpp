//22,276KB	630MS	C++	4,506B
//#include <stdio.h>
//사용자: 본인 id, 팔로잉 정보
//게시물 : 게시물 id 의 발행한 사용자, 게시물id의  좋아요, 게시물의 id의 타임스탬프
//N: 사용자는 1000
// 각 함수 10만회 이하, 단 getfeed 만 5천 이하.
#define MAXN (1000+1)
#define MAXT (100000+1)
 
 
int userInfo[MAXN][MAXN];
typedef struct list {
    int uID;
    int like;
    int timestamp;
}LIST;
 
LIST data[MAXT];
int heap[MAXT];
 
int current_pid;
int heapSize;
 
 
void init(int N)
{
    //printf("N: %d\n", N);
    heapSize = 0;
    for (register int i = 1; i <= N; i++) {
        for (register int j = 1; j <= N; j++) {
            userInfo[i][j] = 0;
        }
        userInfo[i][i] = 1;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    userInfo[uID1][uID2] = 1;
}
 
void makePost(int uID, int pID, int timestamp)
{
    data[pID].uID = uID;
    data[pID].timestamp = timestamp;
    data[pID].like = 0;
    current_pid = pID;
}
 
void like(int pID, int timestamp)
{
    data[pID].like++;
}
 
/* 오리지날
int heapPush(int value)
{
    if (heapSize + 1 > MAX_SIZE)
    {
        printf("queue is full!");
        return 0;
    }
 
    heap[heapSize] = value;
 
    int current = heapSize;
    while (current > 0 && heap[current] < heap[(current - 1) / 2])
    {
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
 
    heapSize = heapSize + 1;
 
    return 1;
}
*/
 
int compare(LIST a, LIST b)
{
    int ret = 0;
 
    if (a.like > b.like) {
        ret = 1;
    }
    else if (a.like == b.like) {
        if (a.timestamp > b.timestamp) {
            ret = 1;
        }
        else {
            ret = 0;
        }
    }
    else {
        ret = 0;
    }
 
    return ret;
}
 
int heapPush(int value)
{
    if (heapSize > MAXT)
    {
        //printf("queue is full!");
        return 0;
    }
 
    heap[heapSize] = value;
 
 
    int current = heapSize;
 
    //compare(                data[heap[current]], data[heap[(current - 1) / 2]]                       )
 
 
    while (current > 0 && compare(data[heap[current]], data[heap[(current - 1) / 2]]))
    {
 
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
 
    heapSize = heapSize + 1;
 
    return 1;
}
 
 
 
int heapPop(int* value)
{
    if (heapSize <= 0)
    {
        return -1;
    }
 
    *value = heap[0];
    heapSize = heapSize - 1;
 
    heap[0] = heap[heapSize];
 
    int current = 0;
    while (current * 2 + 1 < heapSize)
    {
        int child;
        if (current * 2 + 2 == heapSize)
        {
            child = current * 2 + 1;
        }
        else
        {
            child = compare(data[heap[current * 2 + 1]], data[heap[current * 2 + 2]]) ? current * 2 + 1 : current * 2 + 2;
        }
 
        if (compare(data[heap[current]], data[heap[child]]))
        {
            break;
        }
 
        int temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;
 
        current = child;
    }
    return 1;
}
 
/*
1. 게시된 지 1,000 초 이내인 게시글이 그렇지 않은 게시글보다 우선순위가 높다.
2. 게시된 지 1,000 초 이내인 게시글들 중에는 “like” 가 많은 게시글의 우선순위가 높다.
3. 게시된 지 1,000 초 이내이면서 “like” 의 개수가 같은 게시글들 중에는 “timestamp” 가 높은 게시글의 우선순위가 높다.
4. 게시된 지 1,000 초를 초과한 게시글의 경우, “timestamp” 가 높은 게시글의 우선순위가 높다.
*/
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    //printf("getfeed uid:%d timestamp:%d\n", uID, timestamp);
    int temp = 0;
    int temp2[MAXT] = { 0, };
    int over1000_Cnt = 0;
    //int candidate[MAXT] = { 0, };
    for (register int i = current_pid; i >= 1; i--) {
        if (userInfo[uID][data[i].uID] == 0) continue;
 
        //if (userInfo[uID][data[i].uID] == 1) {
        /*if (data[i].uID == uID || userInfo[uID][data[i].uID] == 1) {*/
        int delta = timestamp - data[i].timestamp;
        if (delta <= 1000) {
 
            /*
            for (int m = 0; m < 10; m++) {
                if (data[i].like > data[candidate[m]].like) {
                    for (int n = 8; n >= m; n--) {
                        candidate[n + 1] = candidate[n];
                    }
                    candidate[m] = i;
                    break;
                }
            }
            */
            //printf("data[%d].like: %d, timestampe:%d\n", i, data[i].like, data[i].timestamp);
 
            heapPush(i);
 
 
        }
        else {
            if (over1000_Cnt == 10) break;
            temp2[over1000_Cnt++] = i;//
        }
        //}
    }
 
 
 
    //int cnt = 0;
    //for (int i = 0; i < 10; i++) {
    //  if (candidate[i] != 0) {
    //      pIDList[i] = candidate[i];
    //      cnt++;
    //  }
    //}
 
 
    int cnt = 0;
 
    for (int i = 0; i < 10; i++) {
        int value = 0;
        heapPop(&value);
        if (value != 0) {
            pIDList[i] = value;
            /*printf("heap result pIDList[%d]:%d\n", i, pIDList[i]);*/
            cnt++;
        }
    }
 
    //for (int i = 0; i < 10; i++) {
    //  printf("temp2[%d]: %d\n", i, temp2[i]);
    //}
 
 
    for (int i = 0; i < 10; i++) {
        if (cnt < 10) {
            pIDList[cnt++] = temp2[i];
        }
    }
 
    heapSize = 0;
}