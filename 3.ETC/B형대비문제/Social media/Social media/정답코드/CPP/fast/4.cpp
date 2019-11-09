//18,632KB	107MS	C++	1,275B
static int uid[100001], likes[100001], ts[100001];
static int n_post;
static bool follower[1001][1001];
 
void init(int N)
{
    n_post = 0;
    for (register int i = 1; i <= N; ++i)
        for (register int j = 1; j <= N; ++j)
            follower[i][j] = false;
    for (register int i = 1; i <= N; ++i)
        follower[i][i] = true;
}
 
void follow(int uID1, int uID2, int timestamp)
{
    follower[uID1][uID2] = true;
}
 
void makePost(int uID, int pID, int timestamp)
{
    likes[pID] = 0;
    uid[pID] = uID;
    ts[pID] = timestamp;
    ++n_post;
}
 
void like(int pID, int timestamp)
{
    ++likes[pID];
}
 
void getFeed(int uID, int timestamp, int res[])
{
    for (register int i = 1; i < 10; ++i)
        res[i] = 0;
    if (0 == n_post) return;
    register int idx = 0;
    register int i = n_post;
    register const int x = timestamp - 1000;
    for (; i > 0; --i) {
        if (follower[uID][uid[i]]) {
            if (x > ts[i]) break;
            register const int like_i = likes[i];
            if (10 == idx) {
                if (like_i <= likes[res[9]]) continue;
                idx = 9;
            }
            register int j = idx - 1;
            while (j >= 0 && likes[res[j]] < like_i) {
                res[j + 1] = res[j];
                --j;
            }
            res[++j] = i;
            ++idx;
        }
    }
    if (10 == idx) return;
    for (; i > 0; --i) {
        if (follower[uID][uid[i]]) {
            res[idx++] = i;
            if (10 == idx) return;
        }
    }
}