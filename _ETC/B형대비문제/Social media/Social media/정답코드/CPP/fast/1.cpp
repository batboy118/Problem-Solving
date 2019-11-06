//22,776KB	97MS	C++	2,217B	
#define fi(i,a,b) for(register int i=a; i<b; ++i)
#define fde(i,a,b) for(register int i=a; i>=b; --i)
 
int post_uid[101000];
int post_likes[101000];
int post_ts[101000];
int post_next[101000];
 
int last[1002], old[1002];
int pc;
int n_;
int fw[1002][1002];
int fwc[1002];
 
void init(int N)
{
    n_ = N;
    pc = 0;
    fi(i, 1, n_ + 1) fwc[i] = 1, fw[i][0] = i, last[i] = 0;
}
 
void follow(int uID1, int uID2, int timestamp)
{
    fw[uID1][fwc[uID1]++] = uID2;
}
 
void makePost(int uID, int pID, int timestamp)
{
    post_likes[pID] = 0;
    post_uid[pID] = uID;
    post_ts[pID] = timestamp;
    post_next[pID] = last[uID];
    last[uID] = pID;
    pc = pID;
}
 
void like(int pID, int timestamp)
{
    post_likes[pID]++;
}
 
#define LESS(a,b) a.val < b.val
template<class T>
void qsrt(T* v, int left, int right)
{
    if (left >= right || left >= 10) return;
    register T t;
    if (left + 1 == right) { if (LESS(v[right], v[left])) { t = v[right]; v[right] = v[left]; v[left] = t; } return; }
    register T pivot = v[left + (right - left) / 2];
 
    register int i = left, j = right;
    while (true) {
        while (LESS(v[i], pivot)) i++;
        while (LESS(pivot, v[j])) j--;
        if (i >= j) break;
        t = v[i]; v[i] = v[j]; v[j] = t;
        i++; j--;
    }
    qsrt(v, left, j);
    qsrt(v, j + 1, right);
}
 
struct { int val, idx; } d[100000];
 
void getFeed(int uID, int timestamp, int res[])
{
    register int aidx = 0;
    register int u;
    timestamp -= 1000;
    fi(i, 0, fwc[uID]) {
        u = fw[uID][i];
        register int p = last[u];
        while (p && post_ts[p] >= timestamp) {
            d[aidx].val = -(post_likes[p] * 101000 + post_ts[p]);
            d[aidx].idx = p;
            ++aidx;
            p = post_next[p];
        }
        old[u] = p;
    }
    register int need = 10 - aidx;
    if (need >0)
        fi(i, 0, fwc[uID]) {
        u = fw[uID][i];
        register int p = old[u];
        fi(j, 0, need) {
            if (!p) break;
            d[aidx].val = -post_ts[p];
            d[aidx].idx = p;
            ++aidx;
            p = post_next[p];
        }
    }
    qsrt(d, 0, aidx - 1);
    if (aidx > 10) aidx = 10;
    fi(i, 0, aidx) res[i] = d[i].idx;
}