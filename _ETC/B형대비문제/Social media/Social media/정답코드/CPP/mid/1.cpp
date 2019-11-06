//21,976KB	150MS	C++	3,220B	
#define MAX_NUM     100001 // 2.     timestamp 는 1 에서 시작하고 최대 100,000 까지 증가한다. 4.     모든 게시물들의 timestamp 는 서로 다르다.
#define MAX_NNUM    10000000001 // 2.     timestamp 는 1 에서 시작하고 최대 100,000 까지 증가한다. 4.     모든 게시물들의 timestamp 는 서로 다르다.
#define MAX_UID     1001 // 1.     사용자 수 N 은 2 이상 1,000 이하의 정수이다. (2 ≤ N ≤ 1,000)
struct Doc {
    int Time;
    int UID;
    int PID;
    int likeCnt;
};
struct User {
    int FollowCnt;
    int FollowUser[MAX_UID];
};
struct INPUT {
    int PID;
    unsigned long long Order;
};
Doc DocDB[MAX_NUM];
INPUT Input[MAX_UID];
User UserDB[MAX_UID];
int LastPID;
 
void init(int N){
    LastPID = 0;
    for (int i = 0; i <= N; ++i) {
        UserDB[i].FollowCnt = 0;
    }
}
void follow(int uID1, int uID2, int timestamp) { // 다른 사용자를 “follow” 한다. “follow”를 하게 되면, 그 사용자의 게시글을 볼 수 있다. 
    UserDB[uID1].FollowUser[++UserDB[uID1].FollowCnt] = uID2;
}
void makePost(int uID, int pID, int timestamp){
    LastPID = pID;
    DocDB[LastPID].UID = uID;
    DocDB[LastPID].PID = pID;
    DocDB[LastPID].Time = timestamp;
    DocDB[LastPID].likeCnt = 0; 
}
void like(int pID, int timestamp){
    ++DocDB[pID].likeCnt;
}
void quickSort(int first, int last){
    int pivot, i, j;
    INPUT temp;
 
    if (first < last)    {
        pivot = first;
        i = first;
        j = last;
 
        while (i < j)        {
            while (Input[i].Order >= Input[pivot].Order && i < last)          {
                i++;
            }
            while (Input[j].Order < Input[pivot].Order)          {
                j--;
            }
            if (i < j)           {
                temp = Input[i];
                Input[i] = Input[j];
                Input[j] = temp;
            }
        }
 
        temp = Input[pivot];
        Input[pivot] = Input[j];
        Input[j] = temp;
 
        quickSort(first, j - 1);
        quickSort(j + 1, last);
    }
}
 
void getFeed(int uID, int timestamp, int pIDList[]){
    int VisitUser[MAX_UID] = { 0, };
    int AddCount = 0, CheckTime = timestamp - 1000;
    int i;
/* 
1. 게시된 지 1,000 초 이내인 게시글이 그렇지 않은 게시글보다 우선순위가 높다.  : 1000초 가중치 : 10000000000
2. 게시된 지 1,000 초 이내인 게시글들 중에는 “like” 가 많은 게시글의 우선순위가 높다.  : Like 가중치 :  100000
3. 게시된 지 1,000 초 이내이면서 “like” 의 개수가 같은 게시글들 중에는 “timestamp” 가 높은 게시글의 우선순위가 높다.  : timestamp 가중치 : 1
4. 게시된 지 1,000 초를 초과한 게시글의 경우, “timestamp” 가 높은 게시글의 우선순위가 높다. : 별도  */
    // 1000초 이내 게시글 찾기 (* User 확인 필요)
    for (i = 1; i <= UserDB[uID].FollowCnt; ++i) {
        VisitUser[UserDB[uID].FollowUser[i]] = 1;       
    }
    VisitUser[uID] = 1;
    for (i = LastPID; i > 0 ; --i) {
        if (DocDB[i].Time < CheckTime) {
            break;
        }
        if (VisitUser[DocDB[i].UID] == 1) {
            Input[AddCount].PID = DocDB[i].PID;
            Input[AddCount].Order = MAX_NNUM + (DocDB[i].likeCnt * MAX_NUM) + DocDB[i].Time;            
            AddCount++;
        }       
    }   
    // 1000초 이내 게시글이 10개 미만일 경우 1000초 이상에서 추가하기
    for ( ; i > 0; --i) {
        if (AddCount >= 10) break;
        if (VisitUser[DocDB[i].UID] == 1) {
            Input[AddCount].PID = DocDB[i].PID;
            Input[AddCount].Order = DocDB[i].Time;
            AddCount++;
        }       
    }
    // 찾은 것 중 우선순위 정렬하기(* 10개 미만일 수 있으니 i 개수까지만.)   
    quickSort(0, AddCount-1);
    int Comp = AddCount >= 10 ? 10 : AddCount;
    for (i = 0; i < Comp; ++i) {
        pIDList[i] = Input[i].PID;
    }
}