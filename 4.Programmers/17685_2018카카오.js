// Programmers
// no. 17685
// [3차] 자동완성
// https://programmers.co.kr/learn/courses/30/lessons/17685
// by JH (batboy118)

function solution(words) {
  var answer = 0;
  words = words.sort();
  for (let i = 0; i < words.length; i++) {
    let a = 0, b = 0;
    for (let j = 0; i > 0 && j < words[i].length; j++) {
      if ((words[i][j] !== words[i - 1][j])) {
        a = (j + 1);
        break;
      }
      if (j === words[i].length - 1) a = words[i].length;
    }
    for (let j = 0; i < words.length - 1 && j < words[i].length; j++) {
      if ((words[i][j] !== words[i + 1][j])) {
        b = (j + 1);
        break;
      }
      if (j === words[i].length - 1) b = words[i].length;
    }
    if (a > b) answer += a;
    else answer += b;
  }
  return answer;
}
