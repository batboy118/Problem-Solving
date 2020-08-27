// Programmers
// no. 42888
// 오픈채팅방
// https://programmers.co.kr/learn/courses/30/lessons/42888
// by JH (batboy118)

function solution(record) {
  let answer = [];
  let users = {};
  let messages = [];
  for (let r of record) {
    r = r.split(" ");
    if (r[0] == "Enter") {
      messages.push([r[1], "님이 들어왔습니다."]);
      users[r[1]] = r[2];
    } else if (r[0] === "Leave") {
      messages.push([r[1], "님이 나갔습니다."]);
    } else {
      users[r[1]] = r[2];
    }
  }
  answer = messages.map(m => users[m[0]] + m[1]);
  return answer;
}
