// Programmers
// no. 42627
// 디스크 컨트롤러
// https://programmers.co.kr/learn/courses/30/lessons/42627
// by JH (batboy118)

//제출 코드 (without main)
function solution(jobs) {
    var answer = 0;
    var pq = [];
    let idx =0;
    let pre_outTime = 0;
    jobs.sort((a,b) => {
        if(a[0] != b[0]) 
            return a[0] - b[0]
        return a[1] - b[1]
    })
    while(pq.length !== 0 || idx < jobs.length){
        if(pq.length !== 0){
            let now = pq[0];
            pq.shift();
            if(pre_outTime >= now[0]){
                answer += (now[1] + pre_outTime - now[0]);
                pre_outTime = pre_outTime + now[1];
           }
            else{
                answer += now[1];
                pre_outTime = now[0] + now[1];
            }
        }
        while((pq.length === 0 &&idx < jobs.length) || (idx < jobs.length && pre_outTime >= jobs[idx][0])){
            let i = 0;
            while(i < pq.length && pq[i][1] < jobs[idx][1]){
                i++;
            }
            pq.splice(i, 0, jobs[idx]);
            idx++;
        }
    }
    return Math.floor(answer / jobs.length);
}