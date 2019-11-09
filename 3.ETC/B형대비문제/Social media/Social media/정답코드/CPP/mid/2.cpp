//22,752KB	151MS	C++	2,724B
#define MAX_USERS       1000
#define MAX_POSTINGS    100000
#define NULL 0
#define MAX_SIZE 11
 
typedef struct _post {
    int pid;
    int uid;
    int createdTime;
    int likes;
    _post* next;
} Post;
 
typedef struct _user {
    int nFollows;
    int following[MAX_USERS];
    int nPosts;
    Post* posts;
} User;
 
User users[MAX_USERS + 1];
Post posts[MAX_POSTINGS + 1];
 
int CURRENT_TIME;
bool operator<(Post a, Post b);
 
void init(int N)
{
    register int i;
    for (i = 1; i <= N; i++) {
        users[i].nFollows = 1;
        users[i].following[0] = i;
        users[i].nPosts = 0;
        users[i].posts = NULL;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    users[uID1].following[users[uID1].nFollows++] = uID2;
}
 
void makePost(int uID, int pID, int timestamp)
{
    posts[pID].pid = pID;
    posts[pID].uid = uID;
    posts[pID].createdTime = timestamp;
    posts[pID].likes = 0;
    if (users[uID].posts != NULL)
    {
        posts[pID].next = users[uID].posts;
    }
    else {
        posts[pID].next = NULL;
    }
    users[uID].posts = &posts[pID];
    users[uID].nPosts += 1;
}
 
void like(int pID, int timestamp)
{
    posts[pID].likes += 1;
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    CURRENT_TIME = timestamp;
    Post heap[MAX_SIZE];
    register int i, j;
    int count = 0;
    for (i = 0; i < users[uID].nFollows; i++) {
        int u = users[uID].following[i];
 
        Post* cur = users[u].posts;
        for (j = 0; j < users[u].nPosts; j++) {
 
            if (count < 10) {
                heap[count].createdTime = cur->createdTime;
                heap[count].likes = cur->likes;
                heap[count].pid = cur->pid;
                heap[count].uid = cur->uid;
                count++;
                if (count >= 2) {
                    for (int m = count - 1; m > 0; m--) {
                        if (heap[m - 1] < heap[m]) {
                            // swap
                            Post tmp = heap[m];
                            heap[m] = heap[m - 1];
                            heap[m - 1] = tmp;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else {
                if (heap[9] < *cur) {
                    heap[9].createdTime = cur->createdTime;
                    heap[9].likes = cur->likes;
                    heap[9].pid = cur->pid;
                    heap[9].uid = cur->uid;
 
                    for (int m = 9; m > 0; m--) {
                        if (heap[m - 1] < heap[m]) {
                            // swap
                            Post tmp = heap[m];
                            heap[m] = heap[m - 1];
                            heap[m - 1] = tmp;
                        }
                        else {
                            break;
                        }
                    }
                }
                else {
                    if ((cur->createdTime + 1000) <= CURRENT_TIME) {
                        break;
                    }
                }
            }
 
            cur = cur->next;
        }
    }
 
    for (i = 0; i < count; i++) {
        pIDList[i] = heap[i].pid;
    }
}
 
bool operator<(Post left, Post right)
{
    int val1, val2;
    if (left.createdTime + 1000 < CURRENT_TIME)
        val1 = left.createdTime;
    else
        val1 = left.likes * 100000 + left.createdTime;
 
    if (right.createdTime + 1000 < CURRENT_TIME)
        val2 = right.createdTime;
    else
        val2 = right.likes * 100000 + right.createdTime;
 
    return val1 < val2;
}