//21,568KB	152MS	C++	1,791B
#define MAXUID 1001
#define MAXPID 10000
#define MAXPOST 100001
 
unsigned int lastuid = 0;
unsigned int lastpost = 0;
typedef struct POSTNODE {
    unsigned int uid; // post한 UID 
    unsigned int like; // like 수
    int timestamp;
}Post;
 
Post post[MAXPOST];
int followUID[MAXUID][MAXUID] = { 0 };
int test_case = 0; // followUID 의 여부를 확인을 위해서
 
void init(int N)
{
    lastuid = N;
    lastpost = 0;
    test_case++;
}
 
void follow(int uID1, int uID2, int timestamp)
{
    followUID[uID1][uID2] = followUID[uID1][uID1] = followUID[uID2][uID2] = test_case;
}
 
void makePost(int uID, int pID, int timestamp)
{
    post[pID].uid = uID;
    post[pID].like = 0;
    post[pID].timestamp = timestamp;
 
    lastpost = pID;
}
 
void like(int pID, int timestamp)
{
    post[pID].like++;
}
 
bool highpriority(Post i, Post j) {
    if (i.like > j.like) return true;
    else if (i.like < j.like) return false;
    else if (i.timestamp > j.timestamp) return true;
    return false;
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    unsigned int last_idx = 0;
 
    for (register int i = lastpost; i > 0; i--) {
 
        if (post[i].timestamp < timestamp - 1000 && last_idx == 10)
            break;
 
        if (followUID[uID][post[i].uid] == test_case) { // follow 여부를 체크
            bool check_arr = false;
 
            if (post[i].timestamp >= timestamp - 1000) {
                for (register unsigned int j = 0; j < last_idx; j++) {
                    if (highpriority(post[i], post[pIDList[j]])) {
                         
                        for (register int x = (int)last_idx - 1; x >= j && x >= 0; x--) {
                            if (x == 9) continue;
                            pIDList[x + 1] = pIDList[x];
                        }
 
                        pIDList[j] = i, check_arr = true;
                        if (last_idx < 10) last_idx++;
                        break;
                    }
                }
 
                if (!check_arr && last_idx < 10)
                    pIDList[last_idx++] = i;
            }
            else if (last_idx < 10)
                pIDList[last_idx++] = i;
        }
    }
}