//59,604KB	247MS	JAVA	2,585B
class UserSolution {
    private static final int USER_MAX = 1001;
    private static final int POST_MAX = 100001;
    private static final int FEED_MAX = 10;
     
    private static byte tc = 0;
    private static int postNu;
     
    //private static final int[] feedPost = new int[FEED_MAX + 1];
    private static final int[] postPoster = new int[POST_MAX];
    private static final int[] postID = new int[POST_MAX];
    private static final int[] postLike = new int[POST_MAX];
    private static final int[] postTime = new int[POST_MAX];
    private static final int[] idPost = new int[POST_MAX];
    private static final byte[][] fol = new byte[USER_MAX][USER_MAX];
     
    public void init(int N)
    {
        int i, j;
        tc++;
        if (tc <= 1) {
            for (i = USER_MAX-1; i > 0; i--) {
                for (j = USER_MAX-1; j > 0; j--) {
                    fol[i][j] = 0;
                }
            }
        }
        for (i = N; i > 0; i--) {
            fol[i][i] = tc;
        }
        postNu = 0;
    }
 
    public void follow(int uID1, int uID2, int timestamp)
    {
        fol[uID1][uID2] = tc;
    }
 
    public void makePost(int uID, int pID, int timestamp)
    {
        postID[postNu] = pID;
        idPost[pID] = postNu;
        postPoster[postNu] = uID;
        postLike[postNu] = 0;
        postTime[postNu] = timestamp;
        postNu++;
    }
 
    public void like(int pID, int timestamp)
    {
        postLike[idPost[pID]]++;
    }
 
    public void getFeed(int uID, int timestamp, int pIDList[])
    {
        int fNu, p, l, r;
        final int[] feedPost = new int[FEED_MAX + 1];
        final boolean[] feedTill = new boolean[FEED_MAX + 1];
        boolean stop, till1000;
        fNu = 0;
        p = postNu;
        while (p > 0) {
            p--;
            if (fol[uID][postPoster[p]] == tc) {
                till1000 = (timestamp - postTime[p] <= 1000);
                r = fNu;
                l = r-1;
                while (l >= 0) {
                    if (till1000) {
                        if (feedTill[l]) {
                            if (postLike[p] > postLike[feedPost[l]]) {
                                stop = false;
                            } else if (postLike[p] < postLike[feedPost[l]]) {
                                stop = true;
                            } else {
                                if (postTime[p] > postTime[feedPost[l]]) {
                                    stop = false;
                                } else {
                                    stop = true;
                                }
                            }
                        } else {
                            stop = false;
                        }                       
                    } else {
                        if (feedTill[l]) {
                            stop = true;
                        } else {
                            if (postTime[p] > postTime[feedPost[l]]) {
                                stop = false;
                            } else {
                                stop = true;
                            }
                        }
                    }
                    if (stop) break;
                    feedPost[r] = feedPost[l];
                    feedTill[r] = feedTill[l];
                    r--;
                    l--;
                }
                feedPost[r] = p;
                feedTill[r] = till1000;
                if (fNu < 10) {
                    fNu++;
                } else {
                    if (!till1000) break;
                }
            }
        }
        l = fNu;
        while (l > 0) {
            l--;
            pIDList[l] = postID[feedPost[l]];
        }
    }
}