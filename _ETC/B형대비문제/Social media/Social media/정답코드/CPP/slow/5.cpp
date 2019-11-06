//19,412KB	900MS	C++	4,165B
typedef unsigned int n;
 
static const n max_user = 1000;
static const n max_post = 100000;
static const n head_id = 0;
static const n tail_id = 100001;
static const n invalid = -1;
n old_id;
n latest_id;
n current_time;
bool follow_array[max_user+1][max_user+1];
struct Post {
    bool is_followed_by(n target_id)
    {
        return follow_array[target_id][user_id];
    }
    bool need_to_pop(void) 
    { 
        return current_time - timestamp > 1000; 
    }
    n timestamp;
    n user_id;
    n like;
    n prev;
    n next;
} post[max_post+10], &head = post[0], &tail = post[max_post+1];
 
void push_after(n target_id, n prev_id)
{
    Post& target = post[target_id];
    Post& prev = post[prev_id];
    n next_id = prev.next;
    Post& next = post[next_id];
 
    target.next = next_id;
    target.prev = prev_id;
 
    next.prev = target_id;
    prev.next = target_id;
}
 
void push_before(n target_id, n next_id)
{
    Post& target = post[target_id];
    Post& next = post[next_id];
    n prev_id = next.prev;
    Post& prev = post[prev_id];
 
    target.next = next_id;
    target.prev = prev_id;
 
    next.prev = target_id;
    prev.next = target_id;
}
 
void pop(n target_id)
{
    if(target_id == tail_id || target_id == head_id)
    {
        return;
    }
    Post& target = post[target_id];
    Post& next = post[target.next];
    Post& prev = post[target.prev];
 
    next.prev = target.prev;
    prev.next = target.next;
 
    target.prev = invalid;
    target.next = invalid;
}
void pop_old(n timestamp)
{
    current_time = timestamp;
    for(n i = old_id + 1; i <= latest_id ; i++)
    {
        if(post[i].need_to_pop() == true)
        {
            pop(i);
            old_id = i;
        }
        else
        {
            break;
        }
         
    }
}
void rearrange(n target_id)
{
    Post& target = post[target_id];
    n compare_id = target.prev; 
    pop(target_id);
 
    while(true)
    {
        Post& compare = post[compare_id];
        if(compare_id == head_id 
            || compare.like > target.like
            || (compare.like == target.like && compare.timestamp > target.timestamp))
        {
            push_after(target_id, compare_id);
            return;
        }
        compare_id = compare.prev;
    }
}
void init(int N)
{
    for(n i=0;i<=max_user;i++)
    {
        for(n j=0;j<=max_user;j++)
        {
            follow_array[i][j] = (i==j);
        }
    }
    for(n i=0;i<max_post+10;i++)
    {
        post[i].like = -1;
        post[i].next = -1;
        post[i].prev = -1;
        post[i].timestamp = -1;
        post[i].user_id = -1;
    }
    head.next = tail_id;
    tail.prev = head_id;
 
    old_id = 0;
    latest_id = 0;
    current_time = 0;
 
}
 
void follow(int uID1, int uID2, int timestamp)
{
    pop_old(timestamp);
    follow_array[uID1][uID2] = true;
}
 
void makePost(int uID, int pID, int timestamp)
{
    pop_old(timestamp);
    Post& target = post[pID];
    target.user_id = uID;
    target.timestamp = timestamp;
    target.like = 0;
    latest_id = pID;
    for(int i = latest_id - 1; i > 0;i--)
    {
        Post& compare = post[i];
        if(compare.need_to_pop()) 
            break;
        if (compare.like == 0)
        {
            push_before(pID, i);
            return;
        }
    }
    push_before(pID, tail_id);
}
 
void like(int pID, int timestamp)
{
    pop_old(timestamp);
    Post& target = post[pID];
    target.like++;
    if(target.need_to_pop() == false)
        rearrange(pID);
}
 
void getFeed(int uID, int timestamp, int pIDList[])
{
    for(n i = 0;i<10;i++) pIDList[i] = 0;
    pop_old(timestamp);
    n index = 0;
    n compare_id = head.next;
    while(compare_id != tail_id)
    {
        Post& compare = post[compare_id];
        if(compare.is_followed_by(uID))
        {
            pIDList[index++] = compare_id;
            if(index == 10) return;
        }
        compare_id = compare.next;
    }
 
    for(n compare_id = old_id; compare_id>0;compare_id--)
    {
        Post& compare = post[compare_id];
        if(compare.is_followed_by(uID))
        {
            pIDList[index++] = compare_id;
            if(index == 10) return;
        }
    }
}