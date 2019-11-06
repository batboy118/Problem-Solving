//79,056KB	295MS	JAVA	3,304B
class UserSolution {
     
    class Post {
        int uid;
        int timestamp;
        int likes;
          
        public Post(int uid, int timestamp) {
            this.uid = uid;
            this.timestamp = timestamp;
            this.likes = 0;
        }
    }
      
    class Node {
        int pid;
        int weight;
        Node next;
      
        Node(int pid, int weight) {
            this.pid = pid;
            this.weight = weight;
        }
    }
      
    class LinkedList {
      
        Node head;
        LinkedList() {
            head = null;
        }
      
        void InsertNode(int pid, int weight) {
            if (head == null) {
                Node new_node = new Node(pid, weight);
                head = new_node;
                return;
            }
              
            Node current = head;
            Node previous = head;
      
            int i = 0;
            while (current != null) {
                if (i==10) return;
                if (weight > current.weight) {
                    break;
                }
      
                previous = current;
                current = current.next;
                i++;
            }
              
            Node new_node = new Node(pid, weight);
            new_node.next = current;
            if (head == current) {
                head = new_node;
            } else {
                previous.next = new_node;
            }
        }
    }
      
    Post[] posts;
    int current_post_index;
    boolean[][] follow;
    int n;
      
    public void init(int N)
    {
        posts = new Post[100001];
        current_post_index = 0;         
        follow = new boolean[N+1][N+1];
        n = N;
    }
  
    public void follow(int uID1, int uID2, int timestamp)
    {
        follow[uID1][uID2] = true;
    }
  
    public void makePost(int uID, int pID, int timestamp)
    {
        current_post_index = pID;
        posts[current_post_index] = new Post(uID, timestamp);
    }
  
    public void like(int pID, int timestamp)
    {
        posts[pID].likes++;
    }
  
    public void getFeed(int uID, int timestamp, int pIDList[])
    {
        if (current_post_index == 0)
            return;
        follow[uID][uID] = true;
        int inserted = 0;
        int searched = 0;
        LinkedList list = new LinkedList();
        int current_index;
        current_index = current_post_index - searched;
        while((current_index > 0) && ((timestamp - 1000) <= posts[current_post_index-searched].timestamp)) {
            if (follow[uID][posts[current_index].uid]) {
                list.InsertNode(current_index, posts[current_index].timestamp + 
                        posts[current_index].likes * 100000);
            }
            searched++;
            current_index = current_post_index - searched;
        }
         
        Node current = list.head;
         
        while (current != null) {
            pIDList[inserted] = current.pid;
            current = current.next;
              
            inserted++;
            if (inserted == 10)
                break;
        }
          
        if (inserted < 10) {
            int i = 0;
            while(true) {
                current_index = current_post_index - searched - i;
                if (current_index < 1) break;
                if (inserted >= 10) break;
                  
                if (follow[uID][posts[current_index].uid]) {
                    pIDList[inserted++] = current_index;
                }
                i++;
            }
        }
    }
}