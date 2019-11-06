//129,000KB	618MS	JAVA	5,043B
class UserSolution {
     
    int MAX = 100001;   
 
    class user {
        int fc;
        int[] follow;
        //ArrayList<Integer> postlist;
        postlist postlist = new postlist();
        user (int n) {
            fc = 0 ;
            follow = new int[n];
            postlist = new postlist();
        }
        void addfollow(int uID2) {
            follow[fc++] = uID2;
        }
        void addpost(int pID) {
            postlist.add(pID);
        }
    } 
     
    class postid { 
        int id ;
        postid prev,next;
    }
     
    class postlist {
        postid head,tail;
        void add(int pid) {
            postid id = new postid();
            id.id = pid;            
            if (head == null) {
                head = id;    
                tail = id;
            }else{
                tail.next = id;
                id.prev = tail;
                tail = id;
            }    
        }
    }
    
     
    class post { 
        int uid;
        int pid;
        int timestamp;
        int like = 0;
    }
     
    user[] users = null;
    post[] posts ;
    ll result = null;
    int userN;
    public void init(int N)
    {
        userN =  N ;
        users = new user[N+1];
        //init
        posts = new post[MAX];
    }
 
    public void follow(int uID1, int uID2, int timestamp)
    {   
        if ( users[uID1] == null ) {
            users[uID1] = new user(userN);
        }
        if (users[uID2] == null) { 
            users[uID2] = new user(userN);
        }
         
        users[uID1].addfollow(uID2);
    }
 
    public void makePost(int uID, int pID, int timestamp)
    {
        if (posts[pID] == null){
            posts[pID] = new post();
        }
        posts[pID].uid = uID;
        posts[pID].pid = pID;
        posts[pID].timestamp = timestamp;
        users[uID].addpost(pID);
    }
 
    public void like(int pID, int timestamp)
    {   
        posts[pID].like += 1;
    }    
     
    public void getFeed(int uID, int timestamp, int pIDList[])
    {
        result = new ll();
        addcandi(users[uID],timestamp);
         
        for (int i = 0; i < users[uID].fc ; i++) {
            int fwid = users[uID].follow[i];
            addcandi(users[fwid],timestamp);
        }
         
        result h = result.head.next;
        int c = 0;
        while(h!=null && c < 10) {            
            pIDList[c++] = h.id;
            h = h.next; 
        }
    }
     
    void addcandi(user u ,int timestamp) {
        postid h = u.postlist.head;
        while(h != null){
            if ( posts[h.id].timestamp <= timestamp ) { 
                result.add(posts[h.id],timestamp);            
            }else{
                break;
            }
            h = h.next;
        }
         
    }
     
    class result{
        int id ; 
        result prev, next;
    }
    class ll { 
        result head,tail;
        int c  = 0 ;
         
        ll () {
            result r = new result();
            r.id = -1; 
            head = r; tail = r;
        }
         
        public void print() {
            result h = head.next;
            while(h!=null) {
                System.out.print(h.id + ",");
                h = h.next; 
            }
            System.out.println();
        }
 
        void add(post p , int time) { 
            result r = new result();
            r.id = p.pid; 
             
            result last = head; 
            result start = head.next;
             
            int cnt = 0 ; 
            while(start!=null && cnt < 10) { 
                //p를 바꾸려면 조건 처리 
                if (compare( p , posts[start.id] , time)){ 
                    result pre = start.prev;
                    pre.next = r ;
                    r.prev = pre;
                     
                    r.next = start;
                    start.prev = r;            
                    return;
                }
                last = start;
                start = start.next;
                cnt++;
            }
            
            last.next = r ;
            r.prev = last; 
            tail = last;
             
        }
 
        //p 가 1000초 이내라면,
        boolean compare(post p, post t , int time) {
            // TODO Auto-generated method stub
            int ptime = time - p.timestamp;
            int ttime = time - t.timestamp;
             
            if (ptime <= 1000 && ttime <= 1000) {
                if (p.like > t.like) return true;
                else if (p.like == t.like ) { 
                    if (p.timestamp >t.timestamp) {
                        return true;
                    }
                }
            }
            else if (ptime > 1000 && ttime > 1000){
                if (p.timestamp > t.timestamp) {
                    return true;
                }
            }
            else if(ptime <= 1000 && ttime > 1000) {
                if (p.timestamp >t.timestamp) {
                    return true;
                }
            }
            return false;
        }
         
    }
}