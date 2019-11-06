//23,548KB	114MS	C++	4,427B	
#define DEBUG 0
#if DEBUG 
#define log(...) printf(__VA_ARGS__);printf("\n")
void check(bool cond)
{
  if (!cond)
  {
    log("Error !!!");
  }
}
#else 
#define log(...) 
#define check(cond)
#endif 
 
 
#define MAX_USER 1000
#define MAX_POST 100000
#define null 0 
 
struct Post {
  void set(int id, int ts, int user)
  {
    pid = id; 
    ts = ts; 
    uid = user; 
  }
  int pid; 
  int ts; 
  int uid; 
  int like;
 
  int score;
  Post* next; 
   
  void comp_score()
  {
    score = like * 1000000 + ts;
  }
};
 
struct User {
  void reset(int uid)
  {
    posts = null;
    post_count = 0;
    follow_count = 0;
    follow_user(uid); // follow myself
  }
  void add_post(Post* p)
  {
    p->next = posts;
    posts = p;
    post_count++;
  }
 
  void follow_user(int id)
  {
    follow[follow_count++] = id;
#if DEBUG
    follow[follow_count] = -1;
#endif 
  }
 
  int follow[MAX_USER+1]; 
  Post *posts;  
  int follow_count;
  int post_count;
};
 
 
User users[MAX_USER+1]; // users
Post posts[MAX_POST+1]; // posts 
Post* remain_ptr[MAX_USER+1];   // pointers to store the location of the first post after 1000 ts 
 
int post_count; 
int user_count; 
int tc = 0;
 
 
void init(int N)
{
  tc++;
  log("==========================");
  log("TC : %d", tc);
  log("==========================");
 
  user_count = N; 
  post_count = 0;
  for (int i = 1; i <= N; i++)
  {
    users[i].reset(i);
  }
}
 
void follow(int uID1, int uID2, int timestamp)
{
  log("\nUser %d follows %d", uID1, uID2);
  users[uID1].follow_user(uID2);
}
 
void makePost(int uID, int pID, int timestamp)
{
  log("\nUser %d posts pid %d at ts %d", uID, pID, timestamp);
  Post* p = &posts[pID];
  p->pid = pID;
  p->uid = uID; 
  p->ts = timestamp;
  p->like = 0;
  p->comp_score();
  users[uID].add_post(p);
}
 
void like(int pID, int timestamp)
{
  posts[pID].like++;
  posts[pID].comp_score();
}
 
void insertion_sort(Post *arr[], int count)
{
  // Put the last item to a proper position
  Post* tmp = arr[count-1];
  int j = count - 2;
  while(j >= 0 && arr[j]->score < tmp->score)
  {
    arr[j+1] = arr[j];
    j = j - 1;
  }
  arr[j + 1] = tmp;
}
 
 
void getFeed(int uID, int timestamp, int pIDList[])
{
  log("\nGet feed user %d at ts %d", uID, timestamp);
 
  User* user = &users[uID]; 
  Post* found[11];    // set size to 11 to do insertion sort conveniently
  int found_count = 0;
   
  for (int i = 0; i < user->follow_count; i++)
  {
    const int &fid = user->follow[i];
    User* follower = &users[fid];
    remain_ptr[fid] = null;     // reset pointer 
 
    Post* post_ptr = follower->posts; 
    if (post_ptr == null) {
      continue;
    }
 
    while (post_ptr && timestamp - post_ptr->ts <= 1000)
    {
      if (found_count < 10) {
        found[found_count++] = post_ptr; 
        insertion_sort(found, found_count);
      }
      else
      {
        if (post_ptr->score > found[found_count-1]->score)
        {          
          found[found_count] = post_ptr;  // put the post at the end of array 
          insertion_sort(found, found_count+1); // sort with size (found_count +1)
        }
      }
 
      post_ptr = post_ptr->next;
    } 
 
    // move pointer to the first post after 1000 ts 
    while (post_ptr && timestamp - post_ptr->ts <=1000)
    {
      post_ptr = post_ptr->next;
    }
    remain_ptr[fid] = post_ptr;
  }
 
  // max post we need to retrieve 
  const int max_iter = 10 - found_count;
  if (max_iter > 0) 
  {
    for (int i = 0; i < user->follow_count; i++)
    {
      const int& fid = user->follow[i];
      Post* post_ptr = remain_ptr[fid];
      if (post_ptr == null) 
      {
        continue;
      }
 
      int iter = 0;
      while (post_ptr && iter <max_iter)
      {
        check(timestamp - post_ptr->ts > 1000);
 
        // reset score to ts 
        post_ptr->like = 0;
        post_ptr->comp_score();
 
        if (found_count < 10) {        
          found[found_count++] = post_ptr;
          insertion_sort(found, found_count);
        }
        else
        {
          if (post_ptr->score > found[found_count - 1]->score)
          {
            found[found_count] = post_ptr;
            insertion_sort(found, found_count+1);
          }
        }
        iter++;
        post_ptr = post_ptr->next;
      }
    }
  }
 
  // reset array 
  for (int i = 0; i < 10; i++)
  {
    pIDList[i] = 0;
  }
 
  // copy result
  for (int i = 0; i < found_count; i++)
  {
    pIDList[i] = found[i]->pid;
  }
}