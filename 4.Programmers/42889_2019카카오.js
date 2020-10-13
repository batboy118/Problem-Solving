// Programmers
// no. 42889
// 실패율
// https://programmers.co.kr/learn/courses/30/lessons/42889
// by JH (batboy118)

function solution(N, stages) {
  let answer = [];
  let clear = [0];
  let now = new Array(N + 2).fill(0);
  for (let i = 0; i < stages.length; i++) {
    now[stages[i]]++;
  }
  clear[N] = now[N + 1];
  for (let i = N - 1; i > 0; i--) {
    clear[i] = clear[i + 1] + now[i + 1];
  }
  let info = [];
  for (let i = 1; i < N + 1; i++) {
    let fail = (now[i] / (now[i] + clear[i]));
    info.push({ i, fail });
  }
  answer = info.sort((a, b) => {
    if (b.fail > a.fail) return 1;
    if (b.fail < a.fail) return -1;
    if (b.i < a.i) return 1;
    return -1;
  }).map(i => i.i);
  return answer;
}
