//18,692KB	106MS	C++	3,120B
int heapSize = 0;
int maxUser;
const int MAX_TIME = 100001;
int users[1001];
int followed[1001][26];
int followedSize[1001];
int followedStop[1001];
 
int posted[1001][135];
int postedSize[1001];
int comparePrecalc[MAX_TIME];
int post[MAX_TIME];
int postTime[MAX_TIME];
int compare[MAX_TIME];
int data[300];
 
 
void siftDown(register int i) {
    while (2 * i + 1 < heapSize) {
        register int left = (i<<1) + 1;
        register int right = (i<<1) + 2;
        register int j = left;
        if (right < heapSize && compare[data[right]] > compare[data[left]])
            j = right;
        if (compare[data[i]] >= compare[data[j]])
            break;
        register int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i = j;
    }
}
 
int extractMin() {
    register int min = data[0];
    data[0] = data[heapSize - 1];
    heapSize--;
    siftDown(0);
    return min;
}
 
void buildHeap() {
    for (register int i = heapSize >>1; i >= 0; i--) {
        siftDown(i);
    }
}
 
void init(int N) {
    for (register int i = 0; i <= N; i++) {
        users[i] = 0;
        followedSize[i] = 1;
        postedSize[i] = 0;
        followed[i][0] = i;     
    }
}
 
void follow(const int uID1, const int uID2, const  int timestamp) {
    followed[uID1][followedSize[uID1]++] = uID2;
}
 
void makePost(const int uID,const  int pID,const int timestamp) {
    posted[uID][postedSize[uID]++] = pID;
    postTime[pID] = timestamp;
    post[pID] = 0;
    comparePrecalc[pID] = timestamp;
}
 
void like(const int pID,const  int timestamp) {
    post[pID]++;
    comparePrecalc[pID] +=MAX_TIME;
}
 
void getFeed(const int uID, const  int timestamp, int pIDList[]) {
    heapSize = 0;
    register int currMin = timestamp;
    for (register int i = 0; i < followedSize[uID]; i++) {
        register int ff = followed[uID][i];
        register int to = postedSize[ff] < 11? 0 : postedSize[ff] - 10;
        followedStop[ff] = -1;
        for (register int j = postedSize[ff]-1; j >= to ; j--) {
            register int i1 = posted[ff][j];
            if(postTime[i1] >= timestamp-1000) {
                if(heapSize > 10){
                    register int currTime = comparePrecalc[i1];// (post[i1]<<12) + postTime[i1];
                    if(currTime <= currMin)
                        continue;
 
                    data[heapSize++] = i1;
                    compare[i1] = currTime;
                }else {
                    data[heapSize++] = i1;
                    compare[i1] = comparePrecalc[i1];//(post[i1]<<12) + postTime[i1];
                    if(currMin > comparePrecalc[i1]){
                        currMin = comparePrecalc[i1];
                    }
                }
            } else{
                followedStop[ff] = j;
                break;
            }
        }
    }
 
    if(heapSize < 10){
        for (register int i = 0; i < followedSize[uID]; i++) {
            register int ff = followed[uID][i];
            register int to = followedStop[ff] < 11? 0 : followedStop[ff] - 10;
            for (register int j =  followedStop[ff]; j >= to ; j--) {
                register int i1 = posted[ff][j];
                if(heapSize > 10){
                    if(postTime[i1] <= currMin)
                        break;
                    data[heapSize++] = i1;
                    compare[i1] = postTime[i1];
                }else {
                    data[heapSize++] = i1;
                    compare[i1] = postTime[i1];
                    if(currMin > compare[i1]){
                        currMin = compare[i1];
                    }
                }
            }
        }
    }
    buildHeap();
    register int to = heapSize< 11? 0: heapSize -10;
    register int resPos =0;
    for (register int i = heapSize-1; i>= to; i--) {
        pIDList[resPos++] = extractMin();
    }
}