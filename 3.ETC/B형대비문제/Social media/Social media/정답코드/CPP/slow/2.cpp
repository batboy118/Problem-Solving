//32,220KB	614MS	C++	4,831B
#define MAX_USER 1010
#define MAX_POST 100010
 
struct Post
{
    int uid;
    int pid;
    int time;
    int like;
    Post *prev;
    Post *next;
    Post *up;
    Post *down;
}mPost[MAX_POST];
int mPostIdx = 0;
 
struct Info
{
    Post *head;
    Post *tail;
    int follow[MAX_USER];
    int count;
}mInfo[MAX_USER];
int mInfoIdx = 0;
 
struct User
{
    Info *info;
}mUser[MAX_USER];
 
struct pInfo
{
    Post *head;
    Post *tail;
}mpInfo[MAX_POST];
int mpInfoIdx = 0;
 
struct postTable
{
    pInfo *info;
}mpostTable[MAX_POST];
 
Post heap[MAX_POST];
int heapSize = 0;
 
 
 
Post *makeData()
{
    return &mPost[mPostIdx++];
}
Info *makeInfo()
{
    return &mInfo[mInfoIdx++];
}
pInfo *makepostInfo()
{
    return &mpInfo[mpInfoIdx++];
}
 
void init(int N)
{
    mPostIdx = mInfoIdx = mpInfoIdx = heapSize = 0;
    for (register int i = 0; i < MAX_POST; i++)
    {
        mPost[i].uid = mPost[i].pid = mPost[i].like = mPost[i].time = 0;
        mPost[i].prev = mPost[i].next = mPost[i].up = mPost[i].down = 0;
         
        heap[i].uid = heap[i].pid = heap[i].like = heap[i].time = 0;
        heap[i].prev = heap[i].next = heap[i].up = heap[i].down = 0;
        if (i < MAX_USER)
        {
            mInfo[i].head = mInfo[i].tail = 0;
            mInfo[i].count = 0;
            *mInfo[i].follow = 0;
 
            mUser[i].info = 0;
        }   
        mpInfo[i].head = mpInfo[i].tail = 0;
        mpostTable[i].info = 0;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    if (mUser[uID1].info == 0)
    {
        mUser[uID1].info = makeInfo();
    }
    mUser[uID1].info->follow[mUser[uID1].info->count] = uID2;
    mUser[uID1].info->count++;
}
 
void makePost(int uID, int pID, int timestamp)
{
    Post *post = makeData();
    post->uid = uID;
    post->pid = pID;
    post->time = timestamp;
    post->like = 0;
    post->prev = post->next = post->up = post->down = 0;
 
    if (mUser[uID].info == 0)
    {
        mUser[uID].info = makeInfo();
        mUser[uID].info->head = mUser[uID].info->tail =   0;
    }
    if (mUser[uID].info->head == 0)
    {
        post->prev = post->next = 0;
        mUser[uID].info->head = mUser[uID].info->tail = post;
    }
    else
    {
        post->prev = mUser[uID].info->tail;
        post->prev->next = post;
        post->next = 0;
        mUser[uID].info->tail = post;
 
        /*post->prev = 0;
        post->next = mUser[uID].info->head;
        if(post->next != 0)
            post->next->prev = post;
        mUser[uID].info->head = post;*/
    }
 
    if (mpostTable[pID].info == 0)
    {
        mpostTable[pID].info = makepostInfo();
    }
    if (mpostTable[pID].info->head == 0)
    {
        post->up = post->down = 0;
        mpostTable[pID].info->head = mpostTable[pID].info->tail = post;
    }
    else
    {
        post->up = mpostTable[pID].info->tail;
        post->up->down = post;
        post->down = 0;
        mpostTable[pID].info->tail = post;
        /*post->up = 0;
        post->down = mpostTable[pID].info->head;
        if(post->down != 0)
            post->down->up = post;
        mpostTable[pID].info->head = post;*/
    }
}
 
void like(int pID, int timestamp)
{
    if (mpostTable[pID].info->head != 0)
    {
        mpostTable[pID].info->head->like++;
    }
}
 
int compare(Post &p1, Post &p2, int time)
{
    if (time - p1.time <= 1000 && time - p2.time <= 1000)
    {
        if (p1.like != p2.like) return p1.like - p2.like;
        if (p1.time != p2.time) return p1.time - p2.time;
    }
    else
    {
        if (p1.time != p2.time) return p1.time - p2.time;
    }
}
 
int heapPush(Post value, int time)
{
    if (heapSize + 1 > MAX_POST)
    {
        //printf("queue is full!");
        return 0;
    }
 
    heap[heapSize] = value;
 
    int current = heapSize;
    while (current > 0 && compare(heap[current], heap[(current - 1) / 2], time)   > 0 )
    {
        Post temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
 
    heapSize = heapSize + 1;
 
    return 1;
}
 
int heapPop(Post *value, int time)
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
            child = compare(heap[current * 2 + 1], heap[current * 2 + 2], time)  > 0  ? current * 2 + 1 : current * 2 + 2;
        }
 
        if (compare(heap[current], heap[child], time) > 0)
        {
            break;
        }
 
        Post temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;
 
        current = child;
    }
    return 1;
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    if (mUser[uID].info != 0)
    {
        heapSize = 0;
        int count = 0;
        for (register int i = 0; i < mUser[uID].info->count; i++)
        {
            int fid = mUser[uID].info->follow[i];
            if (mUser[fid].info != 0)
            {
                Post *post = mUser[fid].info->tail;
                while (post != 0)
                {
                    heapPush(*post, timestamp);
                    count++;
                    post = post->prev;
                }
            }
        }
        Post *cur = mUser[uID].info->head;
        while (cur != 0)
        {
            heapPush(*cur, timestamp);
            count++;
            cur = cur->next;
        }
        Post result;
        for (register int k = 0; k < 10; k++)
        {
            if (heapPop(&result, timestamp) != -1)
            {
                pIDList[k] = result.pid;
            }
        }
    }
}