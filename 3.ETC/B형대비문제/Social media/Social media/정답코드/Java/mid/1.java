//377MS	JAVA	7,737B
class UserSolution {
 
    PostList[] postByUid;
    Follower[] followMap;
 
    Post[] postByPid;
 
//    Hashtable pidHashTable;
 
    public void init(int N) {
        followMap = new Follower[N+1];
        postByUid = new PostList[N+1];
 
        postByPid = new Post[100001];
//        pidHashTable = new Hashtable(1000007);
    }
 
    public void follow(int uID1, int uID2, int timestamp) {
        if (followMap[uID1] == null) {
            followMap[uID1] = new Follower();
            // followMap[uID1].add(uID2, timestamp);
        }
        followMap[uID1].add(uID2, timestamp);
    }
 
    public void makePost(int uID, int pID, int timestamp) {
        Post newPost = new Post();
        newPost.uId = uID;
        newPost.pId = pID;
        newPost.timestamp = timestamp;
 
        // System.out.println("makePost! uId=" + uID + " pID=" + pID + " ts=" + timestamp);
        if (postByUid[uID] == null) {
            postByUid[uID] = new PostList();
        }
        postByUid[uID].add(newPost);
 
//        postByUid[uID].print();
 
//        int key = pidHashTable.find(Integer.toString(pID));
//        if (key == -1) {
//            key = postCount++;
//            pidHashTable.add(Integer.toString(pID), key);
//        }
        postByPid[pID] = newPost;
    }
 
    public void like(int pID, int timestamp) {
//        int key = pidHashTable.find(Integer.toString(pID));
//        Post post = postByPid[key];
        Post post = postByPid[pID];
        post.like++;
         
        int uid = post.uId;
        postByUid[uid].forceSort(timestamp);
 
        // System.out.println("like pid=" + pID + " like=" + postByPid[key].like + " ts=" + timestamp);
    }
 
    public void getFeed(int uID, int timestamp, int pIDList[]) {
 
        PostList result = new PostList();
        if (postByUid[uID] != null) {
            for (int i = 0; i < 10; i++) {
                Post p = postByUid[uID].posts[i];
                if (p != null) {
                    result.add(p, timestamp);
                }
            }
        }
 
        Follower follower = followMap[uID];
        for (int i = 0; i < follower.followCount; i++) {
            int fid = follower.followers[i].fId;
            if (postByUid[fid] != null) {
                for (int j = 0; j < 10; j++) {
 
                    Post p = postByUid[fid].posts[j];
                    if (p != null) {
                        result.add(p, timestamp);
                    }
                }
            }
        }
 
        // System.out.println("=========getFeed uId=" + uID + " ts=" + timestamp);
        result.print(pIDList);
    }
}
 
class FollowInfo {
    int fId;
    int timestamp;
}
 
class Follower {
    FollowInfo followers[];
    int followCount;
 
    public Follower() {
        followCount = 0;
        followers = new FollowInfo[1000];
    }
 
    public void add(int id, int timestamp) {
        FollowInfo f = new FollowInfo();
        f.fId = id;
        f.timestamp = timestamp;
        followers[followCount++] = f;
    }
}
 
class Post {
    int uId;
    int pId;
    int timestamp;
    int like;
}
 
class PostList {
    Post[] posts;
 
    public PostList() {
        posts = new Post[11];
    }
 
    public void add(Post post) {
        posts[10] = post;
        sort(post.timestamp);
    }
 
    public void add(Post post, int ts) {
        posts[10] = post;
        sort(ts);
    }
     
    public void forceSort(int ts) {
        sort(ts);
    }
 
    public void print() {
        // System.out.println("Print!");
        for (int i = 0; i < 10; i++) {
            if (posts[i] != null) {
                // System.out.println("post[" + i + "] uid=" + posts[i].uId + " pid=" + posts[i].pId + " ts=" + posts[i].timestamp + " like=" + posts[i].like);
            }
        }
    }
 
    public void print(int[] pId) {
        for (int i = 0; i < 10; i++) {
            if (posts[i] == null) {
                break;
            }
            pId[i] = posts[i].pId;
        }
    }
 
    private void sort(int tp) {
        for (int i = 10; i > 0; i--) {
            if (posts[i] != null && posts[i - 1] != null) {
                int c2 = tp - posts[i].timestamp;
                int c1 = tp - posts[i - 1].timestamp;
                if (c2 <= 1000 && c1 <= 1000) {
                    int l2 = posts[i].like;
                    int l1 = posts[i - 1].like;
                    // System.out.println("l2=" + l2 + " l1=" + l1);
                    if (l2 > l1) {
                        Post temp = posts[i];
                        posts[i] = posts[i - 1];
                        posts[i - 1] = temp;
                        // swap
                    } else if (l2 == l1) {
                        if (posts[i].timestamp > posts[i - 1].timestamp) {
                            // swap
                            Post temp = posts[i];
                            posts[i] = posts[i - 1];
                            posts[i - 1] = temp;
                        }
                    }
                } else if (c2 <= 1000 && c1 > 1000) {
                    // swap
                    Post temp = posts[i];
                    posts[i] = posts[i - 1];
                    posts[i - 1] = temp;
                } else if (c2 > 1000 && c1 > 1000) {
                    if (posts[i].timestamp > posts[i - 1].timestamp) {
                        // swap
                        Post temp = posts[i];
                        posts[i] = posts[i - 1];
                        posts[i - 1] = temp;
                    }
                }
            } else if (posts[i] != null && posts[i - 1] == null) {
                posts[i - 1] = posts[i];
                posts[i] = null;
            }
        }
    }
}
 
class Hashtable {
    class Hash {
        String key;
        int data;
    }
 
    int capacity;
    Hash tb[];
 
    public Hashtable(int capacity) {
        this.capacity = capacity;
        tb = new Hash[capacity];
        for (int i = 0; i < capacity; i++) {
            tb[i] = new Hash();
        }
    }
 
    private int hash(String str) {
        int hash = 5381;
 
        for (int i = 0; i < str.length(); i++) {
            int c = (int)str.charAt(i);
            hash = ((hash << 5) + hash) + c;
        }
        if (hash < 0)
            hash *= -1;
        return hash % capacity;
    }
 
    public int find(String key) {
        int h = hash(key);
        int cnt = capacity;
        while (tb[h].key != null && (--cnt) != 0) {
            char[] c1 = tb[h].key.toCharArray();
            char[] c2 = key.toCharArray();
 
            boolean result = true;
            if (c1.length == c2.length) {
                for (int i = 0; i < c1.length; i++) {
                    if (c1[i] != c2[i]) {
                        result = false;
                        break;
                    }
                }
                if (result) {
                    return tb[h].data;
                }
            }
 
            h = (h + 1) % capacity;
        }
        return -1;
    }
 
    boolean add(String key, int data) {
        int h = hash(key);
        while (tb[h].key != null) {
            char[] c1 = tb[h].key.toCharArray();
            char[] c2 = key.toCharArray();
            boolean result = false;
            if (c1.length == c2.length) {
                for (int i = 0; i < c1.length; i++) {
                    if (c1[i] != c2[i]) {
                        result = true;
                    }
                }
            }
            if (!result) {
                return false;
            }
 
//            if (tb[h].key.equals(key)) {
//                return false;
//            }
            h = (h + 1) % capacity;
        }
        tb[h].key = key;
        tb[h].data = data;
        return true;
    }
}