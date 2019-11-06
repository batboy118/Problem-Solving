//20,892KB	112MS	C++	4,382B
#define NULL 0
#define MAX_N   1005
#define MAX_SIZE 100001
 
struct DATA {
    int pId;    
    int timestamp;
    int like;
    DATA *next;
};
 
DATA Post[100001]; 
 
DATA *my_post[MAX_N]; 
DATA *my_post_out_time[MAX_N];
 
short Follower[MAX_N][MAX_N];
short F_Cnt[MAX_N];
 
DATA *Heap[10001];
int heapSize;
 
 
extern int ans[10];
extern int user_ans[10];
//int tc;
 
inline int push_intime(DATA *node)
{
    if (heapSize + 1 > MAX_SIZE)
    {       
        return -1;
    }
 
    Heap[heapSize] = node;
 
    register int current = heapSize;
    register int c1;
    while (current > 0 && (Heap[current]->like > Heap[(c1 = (current - 1) / 2)]->like ||
        (Heap[current]->like == Heap[c1]->like && Heap[current]->timestamp > Heap[c1]->timestamp) ))
    {
        DATA *temp = Heap[c1];
        Heap[c1] = Heap[current];
        Heap[current] = temp;
        current = c1;
    }
 
    heapSize = heapSize + 1;
 
    return 1;
}
 
inline int pop_intime()
{
    if (heapSize <= 0)
    {
        return -1;
    }
 
    DATA *node = Heap[0];
    heapSize = heapSize - 1;
 
    Heap[0] = Heap[heapSize];
 
    register int current = 0;
 
    register int c1, c2;
    while ((c1 = current * 2 + 1) < heapSize)
    {
        int child;
        if ((c2 = current * 2 + 2) == heapSize)
        {
            child = c1; // current * 2 + 1;
        }
        else
        {
            if (Heap[c1]->like > Heap[c2]->like || (Heap[c1]->like == Heap[c2]->like && Heap[c1]->timestamp > Heap[c2]->timestamp))
            {
                child = c1;
            }
            else
            {
                child = c2;
            }           
        }
 
        if (Heap[current]->like > Heap[child]->like || (Heap[current]->like == Heap[child]->like && Heap[current]->timestamp > Heap[child]->timestamp))
        {
            break;
        }
 
        DATA *temp = Heap[current];
        Heap[current] = Heap[child];
        Heap[child] = temp;
 
        current = child;
    }
    return node->pId;
}
 
 
inline int push_outtime(DATA *node)
{
    if (heapSize + 1 > MAX_SIZE)
    {
        return -1;
    }
 
    Heap[heapSize] = node;
 
    register int current = heapSize;
    register int c1;
    while (current > 0 && Heap[current]->timestamp > Heap[(c1 = (current - 1) / 2)]->timestamp)
    {
        DATA *temp = Heap[c1];
        Heap[c1] = Heap[current];
        Heap[current] = temp;
        current = c1;
    }
 
    heapSize = heapSize + 1;
 
    return 1;
}
 
inline int pop_outtime()
{
    if (heapSize <= 0)
    {
        return -1;
    }
 
    DATA *node = Heap[0];
    heapSize = heapSize - 1;
 
    Heap[0] = Heap[heapSize];
 
    register int current = 0;
    register int c1, c2;
    while ((c1 = current * 2 + 1) < heapSize)
    {
        int child;
        if ((c2=current * 2 + 2) == heapSize)
        {
            child = c1;
        }
        else
        {
            child = Heap[c1]->timestamp  > Heap[c2]->timestamp ? c1 : c2;
        }
 
        if (Heap[current]->timestamp > Heap[child]->timestamp)
        {
            break;
        }
 
        DATA *temp = Heap[current];
        Heap[current] = Heap[child];
        Heap[child] = temp;
 
        current = child;
    }
    return node->pId;
}
 
void init(int n)
{
    //++tc;
    for (register int i = 1; i <= n; ++i)
    {
        my_post[i] = NULL;
 
        Follower[i][0] = i;
        for (register int j = 1; j < F_Cnt[i]; ++j)
        {
            Follower[i][j] = 0;
        }
        F_Cnt[i] = 1;
    }
}
 
void makePost(int uID, int pID, int timestamp)
{
    DATA *node = &Post[pID];
 
    node->pId = pID;
    //node->uId = uID;
    node->timestamp = timestamp;
    node->like = 0;
    node->next = my_post[uID];
 
    my_post[uID] = node;
 
}
 
void like(int pID, int timestamp)
{
    Post[pID].like++;
}
 
void follow(int uID, int uID2, int timestamp)
{
    Follower[uID][F_Cnt[uID]++] = uID2;
}
 
 
void getFeed(int uID, int timestamp, int ans1[])
{
     
    heapSize = 0;
 
    for (register int i = 0; i < F_Cnt[uID]; ++i)
    {
        int f_uId = Follower[uID][i];
        my_post_out_time[f_uId] = NULL;
 
        register DATA *node = my_post[f_uId];
        while (node)
        {
            register DATA *next = node->next;            
 
            if (timestamp - node->timestamp > 1000 )
            {
                // 1000초 넘어가는곳 저장
                my_post_out_time[f_uId] = node;
                break;
            }
 
            push_intime(node);
 
            node = next;
        }
    }
 
    register int pid_cnt=0;
    for (pid_cnt = 0; pid_cnt < 10; ++pid_cnt)
    {       
        register int pId = pop_intime();
        if (pId < 0) break;
        ans1[pid_cnt] = pId;
    }
 
    if (pid_cnt < 10)
    {
        heapSize = 0;
 
        for (register int i = 0; i < F_Cnt[uID]; ++i)
        {
            register int f_uId = Follower[uID][i];
 
            register int cnt = 0;
            register DATA *node = my_post_out_time[f_uId];
            while (node)
            {
                register DATA *next = node->next;
 
                push_outtime(node);
 
                if (++cnt == 10 - pid_cnt)
                {
                    break;
                }
                node = next;
            }
        }
 
        for (register int i=pid_cnt; i < 10; ++i)
        {           
            register int pId = pop_outtime();
            if (pId < 0) break;
            ans1[i] = pId;
        }
    }
}