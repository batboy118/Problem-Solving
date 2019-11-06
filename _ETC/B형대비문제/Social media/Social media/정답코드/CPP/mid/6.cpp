//19,812KB	177MS	C++	4,072B	
class User {
public:
    bool followers[1001] = {0,};
    int count;
} users[1001];
 
class Post {
public:
    int uid;
    int pid;
    int timestamp;
    int like;
 
    bool operator<(const Post& other) const {
        bool ret = like < other.like;
        bool eq = like == other.like;
        if (ret) {
            return ret;
        }
        else if (eq) {
            return timestamp < other.timestamp;	
        }
        return false;
    }
    bool operator>(const Post& other) const {
        bool ret = like > other.like;
        bool eq = like == other.like;
        if (ret) {
            return ret;
        }
        else if (eq) {
            return timestamp > other.timestamp;
        }
        return false;
    }
} posts[100000];
 
Post *history[100000] = {0,};
int hist_length = 0;
 
void addHistory(Post* post) {
    history[hist_length++] = post;
}
 
void quickSort(int first, int last, Post* p[])
{
    int pivot;
    int i;
    int j;
    Post* temp;
 
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
 
        while (i < j)
        {
            while (i < last && *p[i] > *p[pivot])
            {
                i++;
            }
            while (*p[j] < *p[pivot])
            {
                j--;
            }
            if (i < j)
            {
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
            }
        }
 
        temp = p[pivot];
        p[pivot] = p[j];
        p[j] = temp;
 
        quickSort(first, j - 1, p);
        quickSort(j + 1, last, p);
    }
}
 
int N = 0;
 
void init(int N)
{
    N = N;
    // Init Users
    for(register int i = 0; i < N+1; i++) {
        for(register int j = 0 ; j < N+1; j++)
            users[i].followers[j] = false;
        users[i].count = 0;
    }
     
    // Init posts
    for(register int i = 0; i < 100000; i++) {
        posts[i].like = 0;
        posts[i].uid = 0;
        posts[i].pid = 0;
        posts[i].timestamp = 0;
    }
     
    // Init history
    for(register int i = 0; i < hist_length; i++)
        history[i] = 0;
    hist_length = 0;
}
 
// uID1이 uID2를 follow
void follow(int uID1, int uID2, int timestamp)
{
    users[uID1].followers[uID1] = true;
    users[uID1].followers[uID2] = true;
    users[uID1].count++;
}
 
// 글 작성
void makePost(int uID, int pID, int timestamp)
{
    posts[pID].uid = uID;
    posts[pID].pid = pID;
    posts[pID].timestamp = timestamp;
    addHistory(&posts[pID]);
}
 
// 누군진 모르겠지만 like하였음
void like(int pID, int timestamp)
{
    posts[pID].like++;
}
 
// 최디 10개 글을 우선순위 순으로 return
void getFeed(int uID, int timestamp, int pIDList[])
{
    // INIT
    for(int i = 0 ; i < 10; i++) {
        pIDList[i] = 0;
    }
     
    if(hist_length == 0)
        return;
     
    // GET LIST from history
    int idx = hist_length - 1;
    bool* available_users = users[uID].followers;
    Post *ret_posts[1000] = {0,};
    int ret_posts_idx = 0;
    int like_cnt = 0;
    // in 1000 sec
    do {
        int diff = timestamp - history[idx]->timestamp;
        if(diff > 1000)
            break;
        if(available_users[history[idx]->uid]) {
            ret_posts[ret_posts_idx++] = history[idx];
            if(history[idx]->like > 0)
                like_cnt++;
        }
        idx--;
    } while(idx >= 0);
     
    if(like_cnt >= 10) {
        int like_cnt_idx = 0;
        for(register int i = 0; i < ret_posts_idx; i++) {
            if(ret_posts[i]->like != 0) {
                ret_posts[like_cnt_idx++] = ret_posts[i];
            }
        }
        ret_posts_idx = like_cnt_idx;
    }
     
    int max_i = (10 < ret_posts_idx) ? 10 : ret_posts_idx;
    // 큰 순으로 정렬
    //quickSort(0, ret_posts_idx-1, ret_posts);
    for(register int i = 0; i < ret_posts_idx; i++) {
        for(register int j = i + 1; j < ret_posts_idx; j++) {
            if(*ret_posts[i] < *ret_posts[j]) {
                Post* temp = ret_posts[i];
                ret_posts[i] = ret_posts[j];
                ret_posts[j] = temp;
            }
        }
    }
     
    if(max_i != 10) {
        for(register int i = ret_posts_idx; idx >= 0 && max_i < 10;) {
            if(available_users[history[idx]->uid]) {
                ret_posts[i++] = history[idx];
                max_i++;
            }
            idx--;
        }
    }
     
    for(register int i = 0; i < max_i; i++) {
        pIDList[i] = ret_posts[i]->pid;
    }
}