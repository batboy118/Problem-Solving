//27,876KB	937MS	C++	6,312B
#define MAX_USER 1001
#define MAX_POST 100001
 
#define TYPE_FOLLOWER 0
#define TYPE_POST 1
 
#define POST_INFO_ID 0
#define POST_INFO_TS 1
#define POST_INFO_LIKE 2
 
#define LOG_PRINT 0
 
typedef struct llnode {
    int data; // uID, pID
    struct llnode* next;
}llnode;
 
typedef struct llnodeHeap {
    int use;
    llnode node;
    llnode* tail;
}llnodeHeap;
 
llnodeHeap followerList[MAX_USER]; // 팔로우한 유저의 목록
llnodeHeap postList[MAX_USER]; // 작성한 포스트의 목록
 
int postInfo[MAX_POST][3]; // 포스트 정보 (postId, timestamp, like)
int sortedPost[MAX_POST] = { -1, }; // GetFeed 호출 시 정렬에 이용됨
int sortedCount = 0;
int lowestPriority = 0;
 
 
// Linked list (>>>)
void initListNode(llnode* node) // init heap node
{
    node->data = 0;
    node->next = nullptr;
}
 
llnode* getListNode(int type, int index)
{
    if (type == TYPE_FOLLOWER) {
        if (followerList[index].use != 1) {
            // init head
            followerList[index].use = 1;
            initListNode(&followerList[index].node);
        }
        return &followerList[index].node;
    }
    else if (type == TYPE_POST) {
        if (postList[index].use != 1) {
            // init head
            postList[index].use = 1;
            initListNode(&postList[index].node);
        }
        return &postList[index].node;
    }
    return nullptr;
}
llnode* appendListNode(int type, int index, int data)
{
    int i = 1;
    llnode* node = new llnode;
 
    if (type == TYPE_FOLLOWER) {
        if (followerList[index].use != 1) {
            // init (this node is used as head)
            followerList[index].use = 1;
            followerList[index].node.data = data;
            followerList[index].node.next = nullptr;
            followerList[index].tail = &followerList[index].node;
            return &followerList[index].node;
        }
 
        node->data = data;
        node->next = nullptr;
 
        followerList[index].tail->next = node;
        followerList[index].tail = node;
    }
    else if (type == TYPE_POST) {
        if (postList[index].use != 1) {
            // init (this node is used as head)
            postList[index].use = 1;
            postList[index].node.data = data;
            postList[index].node.next = nullptr;
            postList[index].tail = &postList[index].node;
            return &postList[index].node;
        }
        node->data = data;
        node->next = nullptr;
 
        postList[index].tail->next = node;
        postList[index].tail = node;
    }
    return nullptr;
}
// Linked list (<<<)
 
// Sort (>>>)
int getPriority(int post1, int post2, int timestamp)
{
    // post1이 높은 순위를 가지면 => return 1
    // post2가 높은 순위를 가지면 => return 0
    int ts_gap_1 = timestamp - postInfo[post1][POST_INFO_TS];
    int ts_gap_2 = timestamp - postInfo[post2][POST_INFO_TS];
     
    if (ts_gap_1 <= 1000 && ts_gap_2 > 1000) {
        return 1;
    }
    if (ts_gap_1 > 1000 && ts_gap_2 <= 1000) {
        return 0;
    }
    // 둘 다 1000초 초과 -> Timestamp 큰 글이 우선순위
    if (ts_gap_1 > 1000 && ts_gap_2 > 1000) {
        if (postInfo[post1][POST_INFO_TS] > postInfo[post2][POST_INFO_TS]) {
            return 1;
        }
        else {
            return 0;
        }
    }
     
    // 둘 다 1000초 이내
    if (postInfo[post1][POST_INFO_LIKE] > postInfo[post2][POST_INFO_LIKE]) {
        return 1;
    }
    if (postInfo[post1][POST_INFO_LIKE] < postInfo[post2][POST_INFO_LIKE]) {
        return 0;
    }
    if (postInfo[post1][POST_INFO_LIKE] == postInfo[post2][POST_INFO_LIKE]) {
        if (postInfo[post1][POST_INFO_TS] > postInfo[post2][POST_INFO_TS]) {
            return 1;
        }
        else {
            return 0;
        }
    }
 
    return 1;
}
 
int heapPush(int value, int timestamp)
{
    if (sortedCount + 1 > MAX_POST)
    {
        return 0;
    }
 
    // 속도 향상
    if (sortedCount > 0) {
        lowestPriority = getPriority(lowestPriority, value, timestamp) ? value : lowestPriority;
    }
 
    sortedPost[sortedCount] = value;
 
    int current = sortedCount;
    while (current > 0 && getPriority(sortedPost[current], sortedPost[(current - 1) / 2], timestamp))
    {
        int temp = sortedPost[(current - 1) / 2];
        sortedPost[(current - 1) / 2] = sortedPost[current];
        sortedPost[current] = temp;
        current = (current - 1) / 2;
    }
 
    sortedCount = sortedCount + 1;
 
    return 1;
}
 
int heapPop(int* value, int timestamp)
{
    if (sortedCount <= 0)
    {
        return -1;
    }
 
    *value = sortedPost[0];
    sortedCount = sortedCount - 1;
 
    sortedPost[0] = sortedPost[sortedCount];
 
    int current = 0;
    while (current * 2 + 1 < sortedCount)
    {
        int child;
        if (current * 2 + 2 == sortedCount)
        {
            child = current * 2 + 1;
        }
        else
        {
            if (getPriority(sortedPost[current * 2 + 1], sortedPost[current * 2 + 2], timestamp)) {
                child = current * 2 + 1;
            }
            else {
                child = current * 2 + 2;
            }
        }
 
        if (getPriority(sortedPost[current], sortedPost[child], timestamp))
        {
            break;
        }
 
        int temp = sortedPost[current];
        sortedPost[current] = sortedPost[child];
        sortedPost[child] = temp;
 
        current = child;
    }
    return 1;
}
// Sort (<<<)
 
void init(int N)
{
    for (int i = 1; i < MAX_USER; i++) {
        followerList[i].use = 0;
        postList[i].use = 0;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    appendListNode(TYPE_FOLLOWER, uID1, uID2);
}
 
void makePost(int uID, int pID, int timestamp)
{
    appendListNode(TYPE_POST, uID, pID);
    postInfo[pID][POST_INFO_ID] = pID;
    postInfo[pID][POST_INFO_TS] = timestamp;
    postInfo[pID][POST_INFO_LIKE] = 0;
}
 
void like(int pID, int timestamp)
{
    postInfo[pID][POST_INFO_LIKE] += 1;
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    if (followerList[uID].use != 1) {
        return;
    }
 
    sortedCount = 0;
    lowestPriority = 0;
 
    // 나의 포스트를 sortedArray에 추가
    register llnode* myPost = &postList[uID].node;
    for (; myPost != nullptr; myPost = myPost->next) {
        if (postList[uID].use == 1) {
            // 현재 가장 낮은 순위를 가진 post 보다 우선순위가 낮으면, queue에 넣을 필요 없음
            if (sortedCount < 10 || getPriority(myPost->data, lowestPriority, timestamp)) {
                heapPush(myPost->data, timestamp);
            }
        }
    }
     
    register llnode* followerNode = &followerList[uID].node;
    for (; followerNode != nullptr; followerNode = followerNode->next) {
        if (postList[followerNode->data].use == 1) {
            register llnode* postNode = &postList[followerNode->data].node;
            for (; postNode != nullptr; postNode = postNode->next) {
                // 현재 가장 낮은 순위를 가진 post 보다 우선순위가 낮으면, queue에 넣을 필요 없음
                if (sortedCount < 10 || getPriority(postNode->data, lowestPriority, timestamp)) {
                    heapPush(postNode->data, timestamp);
                }
            }
        }
    }
 
    for (int i = 0; i < MAX_POST && i < 10; i++) {
        int value = 0;
        int ret = heapPop(&value, timestamp);
        if (ret == -1) {
            break;
        }
        pIDList[i] = value;
    }
}