// Programmers
// no. 17687
// [3차] N진수 게임
// https://programmers.co.kr/learn/courses/30/lessons/17687
// by JH (batboy118)

function solution(n, t, m, p) {
  let answer = '';
  let totalString = '';
  for (let i = 0; totalString.length < t * m + p; i++) {
    totalString += i.toString(n);
  }
  totalString = totalString.toUpperCase();
  p--;
  while (answer.length !== t) {
    answer += (totalString[p])
    p += m;
  }
  return answer;
}
