//22,752KB	106MS	C++	2,999B
#if 1
#define MAX_USER    1001
#define MAX_POST    100001
#define MAX_TS      100001
 
#define max(a, b) (a > b ? a : b)
 
typedef  struct _post {
    int timestamp;
    int like;
    int uid;
    int prev;
}Post;
 
typedef struct _user {
    int last_id;    // last post id
    int pause;      // paused post id
    int follow[MAX_USER];
    int cnt_follow;
}User;
 
 
User user[MAX_USER];
Post post[MAX_POST];
 
void init(int N)
{
    register int i;
 
    for (i = 1; i < MAX_USER; ++i) {
        user[i].cnt_follow = 0;
        user[i].last_id = 0;
        user[i].pause = 0;
    }
}
 
void follow(int uID1, int uID2, int timestamp)
{
    user[uID1].follow[user[uID1].cnt_follow++] = uID2;
}
 
void makePost(int uID, int pID, int timestamp)
{
    post[pID].like = 0;
    post[pID].timestamp = timestamp;
    post[pID].uid = uID;
 
    post[pID].prev = user[uID].last_id;
    user[uID].last_id = pID;
}
 
void like(int pID, int timestamp)
{
    post[pID].like++;
}
 
typedef struct _res {
    int pid;
    int timestamp;
}Res;
 
Res data[MAX_POST];
int pq_idx;
 
void PQInit() {
    pq_idx = 1;
}
 
void swap(int a, int b) {
    Res tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}
 
void push(int pid, int timestamp) {
    data[pq_idx].pid = pid;
    data[pq_idx].timestamp = timestamp;
    pq_idx++;
 
    register int p, c;
    c = pq_idx - 1;
    while (c > 1) {
        p = c >> 1;
        if (data[c].timestamp > data[p].timestamp) {
            swap(c, p);
            c = p;
        }
        else {
            break;
        }
    }
}
 
int pop() {
    int ret = data[1].pid;
    data[1] = data[--pq_idx];
 
    register int p, l, r;
    p = 1;
    while (p < pq_idx) {
        l = p << 1;
        if (l >= pq_idx) break;
        r = l + 1;
        if (data[r].timestamp > data[l].timestamp) {
            l = r;
        }
        if (data[l].timestamp > data[p].timestamp) {
            swap(l, p);
            p = l;
        }
        else {
            break;
        }
    }
    return ret;
}
 
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    register int uid, pid, curTS, i, count, prevTS;
 
    PQInit();
    pid = user[uID].last_id;
    count = 0;
    while (pid) {
        if (timestamp - post[pid].timestamp <= 1000) {
            curTS = post[pid].like * MAX_TS + post[pid].timestamp;
            push(pid, curTS);
            count++;
        }
        else {
            user[uID].pause = pid;
            break;
        }
        pid = post[pid].prev;
    }
     
    for (i = user[uID].cnt_follow - 1; i >= 0; --i) {
        uid = user[uID].follow[i];
        pid = user[uid].last_id;
        while (pid) {
            if (timestamp - post[pid].timestamp <= 1000) {
                curTS = post[pid].like * MAX_TS + post[pid].timestamp;
                push(pid, curTS);
                count++;
            }
            else {
                user[uid].pause = pid;
                break;
            }
            pid = post[pid].prev;
        }
    }
 
    if (count < 10) {
        pid = user[uID].pause;
        while (pid) {
            push(pid, post[pid].timestamp);
            prevTS = post[pid].timestamp;
            pid = post[pid].prev;
            count++;
            if (count >= 10) break;
        }
 
        for (i = user[uID].cnt_follow - 1; i >= 0; --i) {
            uid = user[uID].follow[i];
            pid = user[uid].pause;
            while (pid) {
                if (count >= 10 && prevTS > post[pid].timestamp) break;
                push(pid, post[pid].timestamp);
                pid = post[pid].prev;
            }
        }
    }
 
    for (i = 0; i < 10; ++i) {
        if (pq_idx == 1) break;
        pIDList[i] = pop();
    }
}
#endif