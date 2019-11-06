//72,604KB	268MS	JAVA	2,332B
class UserSolution {
 
    private static boolean[][] followers;
    private static int[] iposts = new int[200000];
    private static int[] times = new int[200000];
    private static int[] uids = new int[200000];
    private static int[] likes = new int[200000];
    private static int[] selected = new int[200000];
    private static int nPosts;
 
    public void init(int N) {
        followers = new boolean[1001][1001];
        nPosts = 1;
        for (int i = 1; i < followers.length; i++) {
            followers[i][i] = true;
        }
    }
 
    public void follow(int uID1, int uID2, int timestamp) {
        followers[uID1][uID2] = true;
    }
 
    public void makePost(int uID, int pID, int timestamp) {
 
        likes[pID] = 0;
        iposts[nPosts] = pID;
        uids[nPosts] = uID;
        times[nPosts] = timestamp;
        nPosts++;
    }
 
    public void like(int pID, int timestamp) {
        likes[pID]++;
    }
 
    public void getFeed(int uID, int timestamp, int[] pIDList) {
 
        for (int i = 0; i < pIDList.length; i++) {
            pIDList[i] = 0;
        }
        boolean[] follows = followers[uID];
        int endtime = timestamp - 1000;
        int nSelected = 0;
        int i;
        for (i = nPosts - 1; i >= 0 && times[i] >= endtime; i--) {
            if (follows[uids[i]]) {
                selected[nSelected++] = i;
            }
        }
 
        sort(0, nSelected - 1, selected);
        if (nSelected < 10) {
            for (; i >= 0 && nSelected < 10; i--) {
                if (follows[uids[i]]) {
                    selected[nSelected++] = i;
                }
            }
        }
        int end = nSelected > 10 ? 10 : nSelected;
        for (i = 0; i < end; i++) {
            pIDList[i] = iposts[selected[i]];
        }
    }
 
    private static void sort(int left, int right, int[] list) {
 
        if (left >= right)
            return;
        int pivot = list[left + (right - left) / 2];
        int i = left;
        int j = right;
        while (true) {
            while (compare(pivot, list[i]))
                i++;
            while (compare(list[j], pivot))
                j--;
            if (i >= j)
                break;
            swap(i, j, list);
            i++;
            j--;
        }
        sort(left, j, list);
        sort(j + 1, right, list);
 
    }
 
    private static boolean compare(int nPost1, int nPost2) {
 
        if (likes[iposts[nPost1]] < likes[iposts[nPost2]])
            return true;
        if (likes[iposts[nPost1]] > likes[iposts[nPost2]])
            return false;
 
        if (times[nPost1] < times[nPost2])
            return true;
        if (times[nPost1] > times[nPost2])
            return false;
 
        return false;
    }
 
    private static void swap(int a, int b, int[] list) {
        int temp;
        temp = list[a];
        list[a] = list[b];
        list[b] = temp;
    }
}