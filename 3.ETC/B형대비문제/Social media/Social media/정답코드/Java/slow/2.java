//146,452KB	929MS	JAVA	7,951B
//package day0722;
 
/**
 * Social media 에서 사용되는 몇 가지 기능을 구현해보자. 
 
 * 
 
 * 
 * 1. 게시글을 등록한다. 각 게시글들은 등록되는 시점의 timestamp 를 가지고 있다.
 
 * 2. 다른 사용자를 “follow” 한다. “follow”를 하게 되면, 그 사용자의 게시글을 볼 수 있다.
 
 * 3. 특정 게시글에 “like”를 추가한다. 4. 특정 사용자를 기준으로 자신이 게시한 글과 자신이 “follow” 한 사용자의 게시글 중
 * 우선 순위가 높은 글부터 내림차순으로 최대 10 개의 게시글을 보여준다.
 
 * 
 
 * 
 * 각 게시글의 우선순위를 계산하는 방법은 다음과 같다.
 
 * 1. 게시된 지 1,000 초 이내인 게시글이 그렇지 않은 게시글보다 우선순위가 높다. 
 
 * 2. 게시된 지 1,000 초 이내인 게시글들 중에는 “like” 가 많은 게시글의 우선순위가 높다.
 
 * 3. 게시된 지 1,000 초 이내이면서 “like” 의 개수가 같은 게시글들 중에는 “timestamp” 가 높은 게시글의 우선순위가
 * 높다.
 
 * 4. 게시된 지 1,000 초를 초과한 게시글의 경우, “timestamp” 가 높은 게시글의 우선순위가 높다. 
 
 *
 */
class UserSolution {
    private static final int MAX_COUNT_OF_ITEM = 100001;
    private int sizeOfUser;
    private int sizeOfPost;
    private PostNode[] postByPostIds;
    private PostByUser[] postByUsers;
    private User[] users;
 
    /**
     * 각 testcase 시작 시 초기화를 위해 1번 호출된다.
     */
    public void init(int N) {
        sizeOfPost = 0;
        sizeOfUser = N + 1;
        users = new User[sizeOfUser];
        postByUsers = new PostByUser[sizeOfUser];
 
        postByPostIds = new PostNode[MAX_COUNT_OF_ITEM];
    }
 
    /**
     * “uID1” 사용자가 “uID2” 사용자를 “follow” 한다.
 
     * “uID1” 사용자는 “uID2” 사용자의 모든 게시글을 볼 수 있다.
     * 
     * @param uID1      사용자의 id (1 ≤ uID1, uID2 ≤ N)
     * @param uID2
     * @param timestamp 현재 시점의 “timestamp” (1 ≤ timestamp ≤ 100,000)
     */
    public void follow(int uID1, int uID2, int timestamp) {
        if (users[uID1] == null) {
            users[uID1] = new User(sizeOfUser, uID1);
        }
        users[uID1].addFollowingUser(uID2);
    }
 
    /**
     * “uID” 사용자가 “pID” 게시글을 게시한다.
     * 
     * @param uID
     * @param pID       게시글의 ID ( 1 부터 오름차순으로 주어진다. )
     * @param timestamp
     */
    public void makePost(int uID, int pID, int timestamp) {
        postByPostIds[pID] = new PostNode(pID, timestamp);
        if (postByUsers[uID] == null) {
            postByUsers[uID] = new PostByUser();
        }
        postByUsers[uID].add(postByPostIds[pID]);
        sizeOfPost++;
    }
 
    /**
     * “pID” 게시글에 “like” 를 1 번 추가 한다. 
 
     * “pID” 는 makePost() 에서 전달되었던 값으로만 주어 진다.
     * 
     * @param pID
     * @param timestamp
     */
    public void like(int pID, int timestamp) {
        postByPostIds[pID].increaseLike();
    }
 
    /**
     * 현재 “timestamp” 를 기준으로 “uID” 사용자에게 보여지는 최대 10 개의 게시글의 “pID” 들을 찾아 우선순위의 내림차순으로
     * “pIDList[]” 배열에 저장하여 반환 한다.
     * 
     * @param uID
     * @param timestamp
     * @param pIDList   보여지는 게시글의 pID 들을 저장하는 배열
     */
    public void getFeed(int uID, int timestamp, int pIDList[]) {
        Heap heap = new Heap(sizeOfPost, timestamp);
 
        int[] feedUserIds = users[uID].getFollowingUsers();
        for (int feedUserId : feedUserIds) {
            if (feedUserId <= 0) {
                break;
            }
 
            PostNode currentPostNode = postByUsers[feedUserId] == null ? null
                    : postByUsers[feedUserId].getHeadPostNode();
            while (currentPostNode != null) {
                int postId = currentPostNode.getPostId();
                heap.heapPush(postByPostIds[postId]);
                currentPostNode = currentPostNode.next;
            }
        }
 
        if (heap.getSize() <= 0) {
            return;
        }
 
        for (int time = 0; time < 10; time++) {
            PostNode postNode = heap.heapPop();
            if (postNode == null) {
                break;
            }
            pIDList[time] = postNode.getPostId();
        }
    }
 
    static class Heap {
        private PostNode heap[];
        private int maxSize;
        private int currentTimestamp;
        private int size;
 
        public Heap(int maxSize, int currentTimestamp) {
            this.maxSize = maxSize;
            this.currentTimestamp = currentTimestamp;
            this.heap = new PostNode[this.maxSize];
            this.size = 0;
        }
 
        /**
         * 각 게시글의 우선순위를 계산하는 방법은 다음과 같다.
 
         * 1. 게시된 지 1,000 초 이내인 게시글이 그렇지 않은 게시글보다 우선순위가 높다. 
 
         * 2. 게시된 지 1,000 초 이내인 게시글들 중에는 “like” 가 많은 게시글의 우선순위가 높다.
 
         * 3. 게시된 지 1,000 초 이내이면서 “like” 의 개수가 같은 게시글들 중에는 “timestamp” 가 높은 게시글의 우선순위가
         * 높다.
 
         * 4. 게시된 지 1,000 초를 초과한 게시글의 경우, “timestamp” 가 높은 게시글의 우선순위가 높다. 
 
         * 
         * @param post1
         * @param post2
         * @return
         */
        private int compare(PostNode post1, PostNode post2) {
            final int prevCurrentTime = currentTimestamp - 1000;
            if ((prevCurrentTime <= post1.getTimestamp() && post1.getTimestamp() <= currentTimestamp)
                    && (prevCurrentTime <= post2.getTimestamp() && post2.getTimestamp() <= currentTimestamp)) {
                if (post1.getCountOfLike() != post2.getCountOfLike()) {
                    return post1.getCountOfLike() - post2.getCountOfLike();
                }
            }
            return post1.getTimestamp() - post2.getTimestamp();
        }
 
        public int getSize() {
            return size;
        }
 
        public void heapPush(PostNode value) {
            if (size + 1 > maxSize) {
                return;
            }
 
            heap[size] = value;
 
            int current = size;
            while (current > 0 && compare(heap[current], heap[(current - 1) / 2]) > 0) {
                PostNode temp = heap[(current - 1) / 2];
                heap[(current - 1) / 2] = heap[current];
                heap[current] = temp;
                current = (current - 1) / 2;
            }
 
            size = size + 1;
        }
 
        public PostNode heapPop() {
            if (size <= 0) {
                return null;
            }
 
            PostNode value = heap[0];
            size = size - 1;
 
            heap[0] = heap[size];
 
            int current = 0;
            while (current < size && current * 2 + 1 < size) {
                int child;
                if (current * 2 + 2 >= size) {
                    child = current * 2 + 1;
                } else {
                    child = compare(heap[current * 2 + 1], heap[current * 2 + 2]) > 0 ? current * 2 + 1
                            : current * 2 + 2;
                }
 
                if (compare(heap[current], heap[child]) > 0) {
                    break;
                }
 
                PostNode temp = heap[current];
                heap[current] = heap[child];
                heap[child] = temp;
 
                current = child;
            }
            return value;
        }
 
    }
 
    static class User {
        private int userId;
        private int[] followingUsers;
        private int indexOfFollowingUsers;
 
        public User(int sizeOfUser, int userId) {
            this.indexOfFollowingUsers = 0;
            this.followingUsers = new int[sizeOfUser + 1];
            this.userId = userId;
            this.followingUsers[this.indexOfFollowingUsers++] = this.userId;
        }
 
        public void addFollowingUser(int userId) {
            followingUsers[indexOfFollowingUsers++] = userId;
        }
 
        public int getCount() {
            return indexOfFollowingUsers;
        }
 
        public int getUserId() {
            return userId;
        }
 
        public int[] getFollowingUsers() {
            return followingUsers;
        }
    }
 
    static class PostByUser {
        private int count;
        private PostNode head;
        private PostNode current;
 
        public PostByUser() {
            this.count = 0;
            this.head = this.current = null;
        }
 
        public void add(PostNode newPostNode) {
            if (head == null) {
                head = current = newPostNode;
                count++;
                return;
            }
            current.setNextPostNode(newPostNode);
            current = newPostNode;
            count++;
        }
 
        public int getCount() {
            return count;
        }
 
        public PostNode getHeadPostNode() {
            return head;
        }
 
    }
 
    static class PostNode {
        private int postId;
        private int timestamp;
        private int countOfLike;
        private PostNode next;
 
        public PostNode(int postId, int timestamp) {
            this.postId = postId;
            this.timestamp = timestamp;
            this.countOfLike = 0;
            this.next = null;
        }
 
        public void setNextPostNode(PostNode next) {
            this.next = next;
        }
 
        public PostNode getNextPostNode() {
            return next;
        }
 
        public void increaseLike() {
            this.countOfLike++;
        }
 
        public int getPostId() {
            return postId;
        }
 
        public void setTimestamp(int timestamp) {
            this.timestamp = timestamp;
        }
 
        public int getTimestamp() {
            return timestamp;
        }
 
        public int getCountOfLike() {
            return countOfLike;
        }
 
    }
 
}