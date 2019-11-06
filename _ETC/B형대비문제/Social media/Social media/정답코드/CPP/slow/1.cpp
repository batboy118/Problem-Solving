//21,584KB	610MS	C++	4,403B
#define MAX_CALL        100000
#define MAX_USER        1000
#define null            0
 
struct Link {
    int id;
    Link* next;
 
}LinkList[200000];
 
struct PostInfo {
    int pid;
    int uid;
    int like;
    int tempstamp;
}PostList[MAX_CALL];
 
struct UserInfo {
    int uid;
    Link* userHead;
    Link* postHead;
}UserList[MAX_USER+1];
 
int ProityQ[MAX_CALL];
int PQ_Size;
int UserCount;
 
PostInfo* allocPost(int uid, int pid, int timestamp);
UserInfo* getUserInfo(int uid);
void addPost(UserInfo* uInfo, int pid);
PostInfo* getPost(int pid);
void addFollow(UserInfo* uInfo, int uid, int timestamp);
void pushPostFromUser(int uid, int timestamp);
void addPQ(int pid, int timestamp);
int popPQ(int timestamp);
Link* allocLink();
int LinkIndex;
 
void init(int N)
{
    LinkIndex = 0;
    UserCount = N;
    PQ_Size = 0;
    for (int i = 1; i < N+1; i++) {
        UserList[i].uid = i;
        UserList[i].userHead = null;
        UserList[i].postHead = null;
    }
    for (int i = 0; i < MAX_CALL; i++) {
        LinkList[i] = { 0, };
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    UserInfo* uInfo = getUserInfo(uID1);
    addFollow(uInfo, uID2, timestamp);
}
 
void makePost(int uID, int pID, int timestamp)
{
    PostInfo* pInfo = allocPost(uID, pID, timestamp);
    UserInfo* uInfo = getUserInfo(uID);
    addPost(uInfo, pID);
}
 
void like(int pID, int timestamp)
{
    PostInfo* pInfo = getPost(pID);
    pInfo->like++;
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    PQ_Size = 0;
    UserInfo* uInfo = getUserInfo(uID);
    Link* link = uInfo->userHead;
    pushPostFromUser(uID, timestamp);
    while (link != null) {
        int uId = link->id;
        pushPostFromUser(uId, timestamp);
        link = link->next;
    }
    int size = PQ_Size;
    if (size > 10) size = 10;
    for (int i = 0; i < size; i++) {
        pIDList[i] = popPQ(timestamp);
    }
}
 
Link* allocLink() {
    Link* link = &LinkList[LinkIndex++];
    link->next = null;
 
    return link;
}
 
PostInfo* allocPost(int uid, int pid, int timestamp) {
    PostInfo* pInfo = &PostList[pid];
    pInfo->pid = pid;
    pInfo->uid = uid;
    pInfo->tempstamp = timestamp;
    pInfo->like = 0;
    return pInfo;
}
 
PostInfo* getPost(int pid) {
    return &PostList[pid];
}
 
UserInfo* getUserInfo(int uid) {
    return &UserList[uid];
}
 
void addPost(UserInfo* uInfo, int pid) {
    Link* link = allocLink();
    link->id = pid;
    link->next = uInfo->postHead;
    uInfo->postHead = link;
}
 
void addFollow(UserInfo* uInfo, int uid, int timestamp) {
    Link* link = allocLink();
    link->id = uid;
    link->next = uInfo->userHead;
    uInfo->userHead = link;
}
 
void pushPostFromUser(int uid, int timestamp) {
    UserInfo* uInfo = getUserInfo(uid);
    Link* link = uInfo->postHead;
    while (link != null) {
        int pid = link->id;
        addPQ(pid, timestamp);
        link = link->next;
    }
}
 
bool isRecentPost(int target, int src, int timestamp) {
    PostInfo* pTInfo = getPost(target);
    PostInfo* pSInfo = getPost(src);
    int pTime = timestamp - pTInfo->tempstamp;
    int sTime = timestamp - pSInfo->tempstamp;
    if (pTime <= 1000 && sTime > 1000) {
        return true;
    }
    if (pTime > 1000 && sTime <= 1000) {
        return false;
    }
 
    if (pTime > 1000 && sTime > 1000) {
        if (pTInfo->tempstamp > pSInfo->tempstamp)
            return true;
        else
            return false;
    }
 
    if (pTInfo->like > pSInfo->like) return true;
    if (pTInfo->like == pSInfo->like) {
        if (pTInfo->tempstamp > pSInfo->tempstamp) return true;
    }
     
    return false;
}
 
void addPQ(int pid, int timestamp) {
    if (PQ_Size + 1 > MAX_CALL)
    {
    //  printf("queue is full!");
        return ;
    }
 
    ProityQ[PQ_Size] = pid;
 
    int current = PQ_Size;
    while (current > 0 && isRecentPost(ProityQ[current] , ProityQ[(current - 1) / 2], timestamp))
    {
        int temp = ProityQ[(current - 1) / 2];
        ProityQ[(current - 1) / 2] = ProityQ[current];
        ProityQ[current] = temp;
        current = (current - 1) / 2;
    }
 
    PQ_Size = PQ_Size + 1;
}
 
int popPQ(int timestamp) {
    int value = ProityQ[0];
    if (PQ_Size <= 0)
    {
        return -1;
    }
 
    PQ_Size = PQ_Size - 1;
 
    ProityQ[0] = ProityQ[PQ_Size];
 
    int current = 0;
    while (current * 2 + 1 < PQ_Size)
    {
        int child;
        if (current * 2 + 2 == PQ_Size)
        {
            child = current * 2 + 1;
        }
        else
        {
            if (isRecentPost(ProityQ[current * 2 + 1], ProityQ[current * 2 + 2], timestamp) == true)
                child = current * 2 + 1;
            else
                child = current * 2 + 2;
             
        }
 
        if (isRecentPost(ProityQ[current] , ProityQ[child], timestamp))
        {
            break;
        }
 
        int temp = ProityQ[current];
        ProityQ[current] = ProityQ[child];
        ProityQ[child] = temp;
 
        current = child;
    }
    return value;
 
}