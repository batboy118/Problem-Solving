//30,656KB	108MS	C++	2,665B
#define MAX_NUM 10000
int input[MAX_NUM];
int input_id[MAX_NUM];
 
void quickSort(int first, int last)
{
    register int pivot;
    register int i;
    register int j;
    register int temp;
 
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
 
        while (i < j)
        {
            while (input[i] <= input[pivot] && i < last)
            {
                i++;
            }
            while (input[j] > input[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
                 
                temp = input_id[i];
                input_id[i] = input_id[j];
                input_id[j] = temp;
            }
        }
 
        temp = input[pivot];
        input[pivot] = input[j];
        input[j] = temp;
 
        temp = input_id[pivot];
        input_id[pivot] = input_id[j];
        input_id[j] = temp;
 
 
        quickSort(first, j - 1);
        quickSort(j + 1, last);
    }
}
 
#define NULL 0
#define MAX_TIMESTAMP 100000 // 2. timestamp 는 1 에서 시작하고 최대 100,000 까지 증가한다.
#define MAX_PID MAX_TIMESTAMP
 
struct Feed {
    int pID;
    int timestamp;
    int like;
    Feed* next;
};
Feed feed[MAX_PID];
 
#define MAX_USER 1000 // 1. 사용자 수 N 은 2 이상 1, 000 이하의 정수이다. (2 ≤ N ≤ 1, 000)
struct User {
    int num_following;
    int following_ids[MAX_USER + 1];
    Feed* timeout[MAX_USER + 1];
    Feed* next;
};
User user[MAX_USER + 1];
 
void init(int N) {
    for (register int n = 1; n <= N; n++) {
        user[n].following_ids[0] = n;
        user[n].num_following = 1;
        user[n].next = NULL;
    }
}
 
void follow(int uID1, int uID2, int timestamp) {
    user[uID1].following_ids[user[uID1].num_following++] = uID2;
}
 
void makePost(int uID, int pID, int timestamp) {
    register Feed* pFeed = &feed[pID];
    pFeed->pID = pID;
    pFeed->timestamp = timestamp;
    pFeed->like = 0;
    pFeed->next = user[uID].next;
    user[uID].next = pFeed;
}
 
void like(int pID, int timestamp) {
    feed[pID].like++;
}
 
void getFeed(int uID, int timestamp, int pIDList[]) {
    register Feed* pFeed;
    register int num = 0;
    register int i = 0;
    for (int n = 0; n < user[uID].num_following; n++) {
        user[uID].timeout[n] = NULL;
        for (pFeed = user[user[uID].following_ids[n]].next; pFeed != NULL; pFeed = pFeed->next) {
            if (pFeed->timestamp < timestamp - 1000) {
                user[uID].timeout[n] = pFeed;
                break;
            }
            input[num] = -(pFeed->like*(MAX_TIMESTAMP + 1) + pFeed->timestamp);
            input_id[num] = pFeed->pID;
            num++;
        }
    }
 
    if (num < 10) {
        register int rem = 10 - num;
        for (int n = 0; n < user[uID].num_following; n++) {
            i = 0;
            for (pFeed = user[uID].timeout[n]; pFeed != NULL && i < rem; i++, pFeed = pFeed->next) {
                input[num] = -(pFeed->timestamp);
                input_id[num] = pFeed->pID;
                num++;
            }
        }
    }
    quickSort(0, num - 1);
    for (i = 0; i < 10; i++) {
        pIDList[i] = input_id[i];
    }
}