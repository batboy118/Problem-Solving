//36,052KB	850MS	C++	3,926B
#define MAX_USER    1000
#define NULL        0
#define MAX_CALL    100000
#define MAX_TABLE   100001
 
struct Follow {
    int uid;
    Follow* next;
};
 
struct Post {
    int uid;
    int pid;
    int timestamp;
    int like;
 
    Post* next;
};
 
struct Pid {
    int pid;
    Post* post_addr;
     
    Pid* next;
};
 
Follow relation[MAX_USER + 5];
Post post[MAX_USER + 5];
Pid pid_table[MAX_TABLE];
 
Follow follow_arr[MAX_CALL * 2];
Post post_arr[MAX_CALL * 2];
Pid pid_arr[MAX_TABLE * 2];
 
Post post_sort_arr[MAX_CALL * 2];
 
int follow_idx;
int post_idx;
int pid_idx;
int post_sort_idx;
 
Follow* followAlloc() {
    follow_arr[follow_idx].next = NULL;
 
    return &follow_arr[follow_idx++];
}
 
Post* postAlloc() {
    post_arr[post_idx].next = NULL;
    post_arr[post_idx].like = 0;
 
    return &post_arr[post_idx++];
}
 
Pid* pidAlloc() {
    pid_arr[pid_idx].next = NULL;
     
    return &pid_arr[pid_idx++];
}
 
Post* postSortAlloc() {
    post_sort_arr[post_sort_idx].next = NULL;
 
    return &post_sort_arr[post_sort_idx++];
}
 
void init(int N) {
    for (int i = 0; i < MAX_USER + 5; i++) {
        relation[i].next = NULL;
        post[i].next = NULL;
        pid_table[i].next = NULL;
    }
 
    follow_idx = 0;
    post_idx = 0;
    pid_idx = 0;
}
 
void follow(int uID1, int uID2, int timestamp) {
    Follow* f = followAlloc();
    f->uid = uID2;
 
    if (relation[uID1].next != NULL) {
        f->next = relation[uID1].next;
    }
 
    relation[uID1].next = f;
}
 
void makePost(int uID, int pID, int timestamp) {
    Post* p = postAlloc();
    p->uid = uID;
    p->pid = pID;
    p->timestamp = timestamp;
 
    if (post[uID].next != NULL) {
        p->next = post[uID].next;
    }
 
    post[uID].next = p;
 
    Pid* pid = pidAlloc();
    pid->pid = pID;
    pid->post_addr = p;
 
    int pid_key = pID % MAX_TABLE;
     
    if (pid_table[pid_key].next != NULL) {
        pid->next = pid_table[pid_key].next;
    }
 
    pid_table[pid_key].next = pid;
}
 
void like(int pID, int timestamp) {
    int pid_key = pID % MAX_TABLE;
 
    if (pid_table[pid_key].next == NULL) {
        return;
    }
 
    for (Pid* pid = pid_table[pid_key].next; pid != NULL; pid = pid->next) {
        if (pid->pid != pID) {
            continue;
        }
 
        pid->post_addr->like = pid->post_addr->like + 1;
 
        break;
    }
}
 
void postSort2(Post* arr, Post* b, int timestamp) {
    Post* prev = arr;
 
    int cnt = 0;
 
    for (Post* a = arr->next; a != NULL; a = a->next) {
        int a_time = timestamp - a->timestamp;
        int b_time = timestamp - b->timestamp;
 
        if (a_time <= 1000 && b_time <= 1000) {
            if ((a->like == b->like && a->timestamp < b->timestamp) || (a->like < b->like)) {
                b->next = a;
                prev->next = b;
 
                break;
            }
        }
        else if (a_time <= 1000 && b_time > 1000) {
             
        }
        // b 만 게시된지 1000초 이내
        else if (a_time > 1000 && b_time <= 1000) {
            b->next = a;
            prev->next = b;
 
            break;
        }
        // 둘 다 1000초 초과
        else if (a->timestamp < b->timestamp) {
            b->next = a;
            prev->next = b;
 
            break;
        }
 
        prev = a;
        cnt++;
 
        if (cnt > 10) {
            break;
        }
    }
 
    // 여기에 안걸린 경우는?
    prev->next = b;
}
 
void getFeed(int uID, int timestamp, int pIDList[]) {
    Post arr;
    arr.next = NULL;
 
    int idx = 0;
    post_sort_idx = 0;
 
    if (post[uID].next != NULL) {
        for (Post* p = post[uID].next; p != NULL; p = p->next) {
            Post* pp = postSortAlloc();
            pp->like = p->like;
            pp->pid = p->pid;
            pp->timestamp = p->timestamp;
 
            if (arr.next != NULL) {
                postSort2(&arr, pp, timestamp);
            }
            else {
                arr.next = pp;
            }
        }
    }
 
    if (relation[uID].next != NULL) {
        for (Follow* f = relation[uID].next; f != NULL; f = f->next) {
            int uid = f->uid;
             
            if (post[uid].next == NULL) {
                continue;
            }
 
            for (Post* p = post[uid].next; p != NULL; p = p->next) {
                Post* pp = postSortAlloc();
                pp->like = p->like;
                pp->pid = p->pid;
                pp->timestamp = p->timestamp;
 
                if (arr.next != NULL) {
                    postSort2(&arr, pp, timestamp);
                }
                else {
                    arr.next = pp;
                }
            }
        }
    }
 
    Post* pp = arr.next;
 
    for (int i = 0; i < 10; i++) {
        if (pp == NULL) {
            break;
        }
 
        pIDList[i] = pp->pid;
        pp = pp->next;
    }
}