//23,552KB	163MS	C++	3,442B
#define MAX_SIZE 100000
#define MAX_USER 1001
 
class post {
public:
    post():like(0), ts(0), next(nullptr) {
    }
    int like;
    int ts;
    int pID;
    post *next;
};
post post_table[100001];
 
class user {
public:
    user():head(nullptr), timeout_node(nullptr) {
    }
    int following[MAX_USER];
    post *head;
    post *timeout_node;
};
user user_table[MAX_USER];
int following_cnt[MAX_USER];
 
void init(int N)
{
    for(register int idx = 1; idx <= N; ++idx) {
        user_table[idx].head = nullptr;
        user_table[idx].timeout_node = nullptr;
        user_table[idx].following[1] = idx;
        following_cnt[idx] = 1;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    user_table[uID1].following[++following_cnt[uID1]] = uID2;
}
 
void makePost(int uID, int pID, int timestamp)
{
    post_table[pID].ts = timestamp;
    post_table[pID].like = 0;
    post_table[pID].pID = pID;
    post *next = user_table[uID].head;
    user_table[uID].head = &post_table[pID];
    user_table[uID].head->next = next;
}
 
void like(int pID, int timestamp)
{
    post_table[pID].like += 1;
}
 
class node {
public:
    int score;
    int pID;
};
node heap[MAX_SIZE];
int heap_size = 0;
 
void heap_push(node& value)
{
    if (heap_size + 1 > MAX_SIZE)
        return;
    heap[heap_size] = value;
    register int current = heap_size;
    while (current > 0 && heap[current].score > heap[(current - 1) / 2].score) 
    {
        node temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }
    heap_size += 1;
}
 
int heap_pop(node &value)
{
    if (heap_size <= 0)
        return -1;
    value = heap[0];
    heap_size -= 1;
    heap[0] = heap[heap_size];
    register int current = 0;
    while (current * 2 + 1 < heap_size)
    {
        int child;
        if (current * 2 + 2 == heap_size)
            child = current * 2 + 1;
        else
            child = heap[current * 2 + 1].score > heap[current * 2 + 2].score ? current * 2 + 1 : current * 2 + 2;
 
        if (heap[current].score > heap[child].score)
            break;
 
        node temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;
 
        current = child;
    }
    return heap_size;
}
 
post *timeout[MAX_USER];
void getFeed(int uID, int timestamp, int pIDList[])
{
    heap_size = 0;
    int size = following_cnt[uID];
    for(register int idx = 1; idx <= size; ++idx) {
        int followee_id = user_table[uID].following[idx];
        register post *cur = user_table[followee_id].head;
        timeout[followee_id] = nullptr;
        while(cur) {
            if(cur->ts < timestamp - 1000) {
                timeout[followee_id] = cur;
                break;
            }
            int score = ((cur->like+1) * MAX_SIZE + cur->ts);            
            node n;
            n.score = score; 
            n.pID = cur->pID;
            heap_push(n);
            cur = cur->next; 
        }        
    }
    if(heap_size < 10) {
        for(register int idx = 1; idx <= size; ++idx) {
            int followee_id = user_table[uID].following[idx];
            register post *cur = timeout[followee_id];
            while(cur) {
                node n;
                n.score = cur->ts; 
                n.pID = cur->pID;
                heap_push(n);
                cur = cur->next;
            }
        }
    }
    register int idx = 0;
    while(idx < 10) {
        node value;
        if(heap_pop(value) == -1)
            break;
        pIDList[idx++] = value.pID; 
    }
}