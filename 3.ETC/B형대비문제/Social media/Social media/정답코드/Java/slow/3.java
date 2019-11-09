//125,056KB	1,527MS	JAVA	5,876B
class UserSolution {
 
    static User[] users = new User[1001];
    static Post[] allPosts = new Post[100001];
    static final boolean PRINT_DEBUG = false; 
 
    public void init(int N) {
        users = new User[1001];
        allPosts = new Post[100001];
    }
 
    public void follow(int uID1, int uID2, int timestamp) {
         
        if (PRINT_DEBUG) {
            System.out.println("follow");
            System.out.println("uID1: " + uID1 + " uID2: " + uID2 + " timestamp: " + timestamp);
        }
         
         
         
        if (users[uID1] == null) {
            users[uID1] = new User();
        }
        if (users[uID2] == null) {
            users[uID2] = new User();
        }
        users[uID1].follow(uID2);
    }
 
    public void makePost(int uID, int pID, int timestamp) {
         
        if (PRINT_DEBUG) {
            System.out.println("makePost");
            System.out.println("uID: " + uID + " pID: " + pID + " timestamp: " + timestamp);
        }
         
         
        Post post = new Post(uID, pID, timestamp);
        allPosts[pID] = post;
        users[uID].addPost(post);
    }
 
    public void like(int pID, int timestamp) {
         
        if (PRINT_DEBUG) {
            System.out.println("like");
            System.out.println("pID: " + pID + " timestamp: " + timestamp);
        }
         
        allPosts[pID].likesCount++;
    }
 
    public void getFeed(int uID, int timestamp, int pIDList[]) {
         
         
        users[uID].getFeed(timestamp, pIDList);
        if (PRINT_DEBUG) {
            System.out.println("getFeed");
 
        }
    }
 
    static class Post {
 
        int postId;
        int userId;
        int timestamp;
        int likesCount;
        Post next;
 
        Post(int userId, int postId, int timestamp) {
            this.userId = userId;
            this.postId = postId;
            this.timestamp = timestamp;
        }
    }
 
    static class User {
 
        User[] followed = new User[1001];
        PostList posts = new PostList();
        int followedCounter = 0;
 
        void follow(int followedId) {
            followed[followedCounter++] = users[followedId];
        }
 
        void addPost(Post post) {
            posts.add(post);
        }
 
        int[] getFeed(int timestamp, int pIDList[]) {
 
            int[] feedIds = new int[10];
 
            int timelimit = timestamp - 1001;
 
            int totalPostCount = posts.size;
 
            for (int i = 0; i < followedCounter; i++) {
                if (followed[i] != null && followed[i].posts != null) {
                totalPostCount += followed[i].posts.size;
                }
            }
                 
            Post[] allPosts = new Post[totalPostCount];
             
            int counter = 0;
                 
                for (int i = 0; i < followedCounter; i++) {
                    Post[] p = followed[i].posts.getAll();
                    for (int j = 0; j < p.length; j++) {
                        allPosts[counter++] = p[j];
                    }
                }
 
             
            Post[] pd = posts.getAll();
            for (int j = 0; j < pd.length; j++) {
                allPosts[counter++] = pd[j];
            }
             
            quickSort(allPosts, 0, allPosts.length - 1);
             
             
            int feedCount = 0;
        //  while (feedCount < 10) {
                for (int i = 0; i < allPosts.length; i++) {
                     
                    if (allPosts[i].timestamp > timelimit) {
                        feedIds[feedCount++] = allPosts[i].postId;
                        if (feedCount == 10) {
                        //  pIDList = feedIds;
                            copyIntArray(feedIds, pIDList);
                            return feedIds;
                        }
                    }
                }
                 
                quickSortByTime(allPosts, 0, allPosts.length - 1);
                 
                for (int i = 0; i < allPosts.length; i++) {
                     
                    if (allPosts[i].timestamp <= timelimit) {
                        feedIds[feedCount++] = allPosts[i].postId;
                        if (feedCount == 10) {
                        //  pIDList = feedIds;
                            copyIntArray(feedIds, pIDList);
                            return feedIds;
                        }
                    }
                }
                 
                 
        //  }
        //  pIDList = feedIds;
                copyIntArray(feedIds, pIDList);
            return feedIds;
        }
 
    }
     
    static void copyIntArray(int[] source, int[] dest) {
        for (int i = 0; i < source.length; i++ ) {
            dest[i] = source[i];
        }
         
    }
 
    static class PostList {
 
        Post head;
        int size;
 
        void add(Post post) {
            if (head == null) {
                head = post;
            } else {
                post.next = head;
                head = post;
            }
            size++;
        }
 
        void like(int postId) {
            if (head == null) {
                System.out.println("This should never occure");
                return;
            } else {
                Post current = head;
                while (current != null) {
                    if (current.postId == postId) {
                        current.likesCount++;
                        return;
                    }
                    current = current.next;
                }
            }
        }
         
        Post[] getAll() {
            Post[] posts = new Post[size];
            int counter = 0;
            Post current = head;
            while (current != null) {
                posts[counter++] = current;
                current = current.next;
            }
            return posts;
        }
         
    }
 
    static int compare(Post p1, Post p2) {
 
        int result = p2.likesCount - p1.likesCount;
        if (result == 0) {
            result = p2.timestamp - p1.timestamp;
        }
        return result;
    }
 
    static int compareByTime(Post p1, Post p2) {
        return p2.timestamp - p1.timestamp;
    }
 
    static void quickSort(Post[] posts, int left, int right) {
 
        if (left >= right) {
            return;
        }
 
        Post pivot = posts[(right - left) / 2 + left];
        int index = partition(posts, left, right, pivot);
        quickSort(posts, left, index - 1);
        quickSort(posts, index, right);
 
    }
 
    static int partition(Post[] posts, int left, int right, Post pivot) {
        while (left <= right) {
 
            while (compare(posts[left], pivot) < 0) {
                left++;
            }
            while (compare(posts[right], pivot) > 0) {
                right--;
            }
            if (left <= right) {
                swap(posts, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
 
    static void swap(Post[] posts, int left, int right) {
        Post temp = posts[left];
        posts[left] = posts[right];
        posts[right] = temp;
    }
 
    static void quickSortByTime(Post[] posts, int left, int right) {
        if (left >= right) {
            return;
        }
 
        Post pivot = posts[(right - left) / 2 + left];
        int index = partitionByTime(posts, left, right, pivot);
        quickSortByTime(posts, left, index - 1);
        quickSortByTime(posts, index, right);
    }
 
    static int partitionByTime(Post[] posts, int left, int right, Post pivot) {
        while (left <= right) {
 
            while (compareByTime(posts[left], pivot) < 0) {
                left++;
            }
            while (compareByTime(posts[right], pivot) > 0) {
                right--;
            }
            if (left <= right) {
                swap(posts, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
 
}