//95,120KB	341MS	JAVA	4,564B
class UserSolution {
     
    private static int n;
    private static User[] user;
    private static Post[] post;
     
    private static Post[] feed;
     
    private static final int MAX = 100001;
     
    public void init(int N) {
//System.out.println("init: N=" + N);
 
        n = N + 1;
         
        user = new User[n];
        for (int i = 0 ; i < n ; i++) {
            user[i] = new User();
        }
 
        post = new Post[MAX];
        feed = new Post[11];
    }
 
    public void follow(int uID1, int uID2, int timestamp) {
//System.out.println("follow: uID1=" + uID1 + ", uID2=" + uID2 + ", timestamp=" + timestamp);
        user[uID1].follow[user[uID1].followcount++] = uID2;
    }
 
    public void makePost(int uID, int pID, int timestamp) {
//System.out.println("makePost: uID=" + uID + ", pID=" + pID + ", timestamp=" + timestamp);
        if (post[pID] == null) {
            post[pID] = new Post();
        }
        post[pID].pID = pID;
        post[pID].uID = uID;
        post[pID].timestamp = timestamp;
         
         
        user[uID].post[user[uID].postcount++] = pID;
    }
 
    public void like(int pID, int timestamp) {
//System.out.println("like: pID=" + pID + ", timestamp=" + timestamp);
        post[pID].like++;
    }
 
    public void getFeed(int uID, int timestamp, int pIDList[]) {
//System.out.println("getFeed: uID=" + uID + ", timestamp=" + timestamp);
         
//System.out.println("user["+uID+"].followcount=" + user[uID].followcount);
        for (int i = 0 ; i < user[uID].followcount ; i++) {
//System.out.println("user["+uID+"].follow["+i+"]=" + user[uID].follow[i]);
//System.out.println("user["+user[uID].follow[i]+"].postcount=" + user[user[uID].follow[i]].postcount);
        }
         
        int count = user[uID].postcount;
         
        for (int i = 0 ; i < user[uID].followcount ; i++) {
            count = count + user[user[uID].follow[i]].postcount;
        }       
//System.out.print("count=" + count + ", ");
 
        if (count > (10 * (user[uID].followcount + 1))) {
            count = (10 * (user[uID].followcount + 1));
        }
//System.out.print("(10 * (user["+uID+"].followcount + 1))=" + (10 * (user[uID].followcount + 1)));
         
        feed = new Post[count];
         
        int j = 0;
        for (int k = user[uID].postcount - 1, l = 0 ; k >= 0 && l < 10 ; k--, l++) {
            if (post[user[uID].post[k]].timestamp >= timestamp - 1000) {
                feed[j] = post[user[uID].post[k]];
                sort1(j++);
            } else {
                break;
            }
//System.out.println("uID=" + feed[j].uID + ", pID=" + feed[j].pID + ", like=" + feed[j].like + ", timestamp=" + feed[j].timestamp);
        }
         
        for (int i = 0 ; i < user[uID].followcount ; i++) {
            for (int k = user[user[uID].follow[i]].postcount - 1, l = 0 ; k >= 0 && l < 10 ; k--, l++) {
                if (post[user[user[uID].follow[i]].post[k]].timestamp >= timestamp - 1000) {
                    feed[j] = post[user[user[uID].follow[i]].post[k]];
                    sort1(j++);
                } else {
                    break;
                }
//System.out.println("uID=" + feed[j].uID + ", pID=" + feed[j].pID + ", like=" + feed[j].like + ", timestamp=" + feed[j].timestamp);
            }
        }
 
        for (int k = user[uID].postcount - 1, l = 0 ; k >= 0 && l < 10 ; k--, l++) {
            if (post[user[uID].post[k]].timestamp < timestamp - 1000) {
                feed[j] = post[user[uID].post[k]];
                sort2(j++);
            }
//System.out.println("uID=" + feed[j].uID + ", pID=" + feed[j].pID + ", like=" + feed[j].like + ", timestamp=" + feed[j].timestamp);
        }
         
        for (int i = 0 ; i < user[uID].followcount ; i++) {
            for (int k = user[user[uID].follow[i]].postcount - 1, l = 0 ; k >= 0 && l < 10 ; k--, l++) {
                if (post[user[user[uID].follow[i]].post[k]].timestamp < timestamp - 1000) {
                    feed[j] = post[user[user[uID].follow[i]].post[k]];
                    sort2(j++);
                }
//System.out.println("uID=" + feed[j].uID + ", pID=" + feed[j].pID + ", like=" + feed[j].like + ", timestamp=" + feed[j].timestamp);
            }
        }
         
        for (int k = 0 ; k < j && k < 10 ; k++) {
//System.out.println("uID=" + feed[k].uID + ", pID=" + feed[k].pID + ", like=" + feed[k].like + ", timestamp=" + feed[k].timestamp);
            pIDList[k] = feed[k].pID ;
        }
         
         
    }
     
    public static void sort1(int i) {
         
        Post temp = feed[i];
        int j = i - 1;
 
        while ((j >= 0) && ((temp.like > feed[j].like) || (temp.like == feed[j].like) && temp.timestamp > feed[j].timestamp)) {
            feed[j + 1] = feed[j];
            j--;
        }
        feed[j+1] = temp;
 
    }
 
    public static void sort2(int i) {
         
        Post temp = feed[i];
        int j = i - 1;
 
        while ((j >= 0) && temp.timestamp > feed[j].timestamp) {
            feed[j + 1] = feed[j];
            j--;
        }
        feed[j+1] = temp;
 
    }
 
    class User {
        int uID;
        int[] follow;
        int followcount;
        int[] post;
        int postcount;
        public User() {
            follow = new int[n];
            post = new int[MAX/500];
        }
    }
 
    class Post {
        int pID;
        int uID;
        int timestamp;
        int like;
    }
     
}