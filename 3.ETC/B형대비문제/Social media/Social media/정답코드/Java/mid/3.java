//108,320KB	486MS	JAVA	6,536B
class UserSolution {
    int PCNT = 10;
    int MAX_SIZE = 100001;
    int P_MAX_SIZE;
    int runCount;
    class User {
        int uID = 1;
        FList fList = new FList();
        PList pList = new PList();
        User prev;
    }
     
    class Post {
        int pID;
        int like;
        int timestamp;
        Post prev;
        Post() {
             
        }
        Post(int id, int time) {
            pID = id;
            timestamp = time;
        }
    }
    User uList[];
    Post pList[];
    static int baseTime;
     
     
    public void init(int N)
    {
         P_MAX_SIZE = N +1;
         uList = new User[P_MAX_SIZE];
         pList = new Post[MAX_SIZE];
         baseTime = 0;
         runCount = 0;
          
    }
 
    public void follow(int uID1, int uID2, int timestamp)
    {
        //System.out.println("run count = " + runCount);
        runCount++;
        if (uList[uID1] == null) {
            uList[uID1] = new User();
        }
        if (uList[uID2] == null) {
            uList[uID2] = new User();
        }
        uList[uID1].fList.add(uList[uID2]);
    }
 
    public void makePost(int uID, int pID, int timestamp) {
        //System.out.println("run count = " + runCount);
        runCount++;
        if (uList[uID] == null) {
            uList[uID] = new User();
        }
        Post p = new Post(pID, timestamp);
        pList[pID] = p;
        uList[uID].pList.add(p);
 
    }
 
    public void like(int pID, int timestamp)
    {
        //System.out.println("run count = " + runCount);
        runCount++;
        pList[pID].like++;
    }
 
    public void getFeed(int uID, int timestamp, int pIDList[])
    {
        //System.out.println("run count = " + runCount);
         
        runCount++;
        if (runCount == 84) {
            //System.out.println("###");
        }
 
        baseTime = timestamp;
 
         
        int pSize = uList[uID].pList.size();
        int fSize = uList[uID].fList.getFeedSize();
        heapInit(pSize + fSize);
        uList[uID].pList.getFeed();
        uList[uID].fList.getFeed();
        if (runCount == 84) {
            //System.out.println("");
        }
 
        Post post[] = new Post[PCNT];
        for (int i = 0; i < PCNT; i++) {
            post[i] = heapPop();
            if (post[i] != null) {
                pIDList[i] = post[i].pID;
                //System.out.print(pIDList[i] + " ");
            }
        }
        //System.out.println("");
    }
     
    public static boolean checkpriority (Post a, Post b) {  //a가 크면 true
        int timeA = baseTime - a.timestamp;
        int timeB = baseTime - b.timestamp;
        if (timeA <= 1000  && timeB <= 1000 ) {  // 둘다 1000 미만이면
            if (a.like > b.like)
                return true;
            else if (a.like == b.like) {
                return timeA < timeB ? true : false;
            } else {
                return false;
            }
        } else {    //1000초 이상이 있으면 시간순으로
            return timeA < timeB ? true : false; 
        }
    }
 
    Post heap[];
    int heapSize = 0;
 
    void heapInit(int size)
    {
        heapSize = 0;
        heap = new Post[size];
    }
 
    void heapPush(Post value)
    {
        if (heapSize + 1 > MAX_SIZE)
        {
            return;
        }
 
        heap[heapSize] = value;
 
        int current = heapSize;
        while (current > 0 && checkpriority(heap[current], heap[(current - 1) / 2])) 
        {
            Post temp = heap[(current - 1) / 2];
            heap[(current - 1) / 2] = heap[current];
            heap[current] = temp;
            current = (current - 1) / 2;
        }
 
        heapSize = heapSize + 1;
    }
 
    Post heapPop()
    {
        if (heapSize <= 0)
        {
            return null;
        }
 
        Post value = heap[0];
        heapSize = heapSize - 1;
 
        heap[0] = heap[heapSize];
 
        int current = 0;
        while (current < heapSize && current * 2 + 1 < heapSize)
        {
            int child;
            if (current * 2 + 2 >= heapSize)
            {
                child = current * 2 + 1;
            }
            else
            {
                child = checkpriority(heap[current * 2 + 1], heap[current * 2 + 2]) ? current * 2 + 1 : current * 2 + 2;
            }
 
            if (checkpriority(heap[current], heap[child]))
            {
                break;
            }
 
            Post temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;
 
            current = child;
        }
        return value;
    }
 
    private class PostNode {
        Post item;
        PostNode next;
        PostNode prev;
 
        PostNode(PostNode prev, Post element, PostNode next) {
            this.item = element;
            this.next = next;
            this.prev = prev;
        }
    }
     
    class PList{
        int size = 0;
        PostNode last;
        PostNode first;
        int modCount = 0;
         
        void add(Post e) {
            final PostNode l = last;
            final PostNode newNode = new PostNode(l, e, null);
            last = newNode;
            if (l == null)
                first = newNode;
            else
                l.next = newNode;
            size++;
            modCount++;
        }
         
        PostNode node(int index) {
            if (index < (size >> 1)) {
                PostNode x = first;
                for (int i = 0; i < index; i++)
                    x = x.next;
                return x;
            } else {
                PostNode x = last;
                for (int i = size - 1; i > index; i--)
                    x = x.prev;
                return x;
            }
        }
         
        public Post get(int index) {
            return node(index).item;
        }
         
        public int size() {
            return size;
        }
         
        public void getFeed() {
            PostNode x = first;
            for (int i = 0; i < size; i++) {
                heapPush(x.item);
                x = x.next;
            }
        }
    } 
     
     
     
    private class UserNode {
        User item;
        UserNode next;
        UserNode prev;
 
        UserNode(UserNode prev, User element, UserNode next) {
            this.item = element;
            this.next = next;
            this.prev = prev;
        }
    }
     
    class FList{
        int size = 0;
        UserNode last;
        UserNode first;
        int modCount = 0;
         
        void add(User e) {
            final UserNode l = last;
            final UserNode newNode = new UserNode(l, e, null);
            last = newNode;
            if (l == null)
                first = newNode;
            else
                l.next = newNode;
            size++;
            modCount++;
        }
         
        UserNode node(int index) {
            if (index < (size >> 1)) {
                UserNode x = first;
                for (int i = 0; i < index; i++)
                    x = x.next;
                return x;
            } else {
                UserNode x = last;
                for (int i = size - 1; i > index; i--)
                    x = x.prev;
                return x;
            }
        }
         
        public User get(int index) {
            return node(index).item;
        }
         
        public int size() {
            return size;
        }
         
        public int getFeedSize() {
            int feedSize = 0;
            UserNode x = first;
            for (int i = 0; i < size; i++) {
                feedSize += x.item.pList.size();
                x = x.next;
            }
            return feedSize;
        }
         
        public void getFeed() {
             
            UserNode x = first;
            for (int i = 0; i < size; i++) {
                x.item.pList.getFeed();
                x = x.next;
            }
        }
 
    } 
   
}