// Programmers
// no. 42890
// 후보키
// https://programmers.co.kr/learn/courses/30/lessons/42890
// by JH (batboy118)

const keyList = [];
const visit = Array(10).fill(0);
const keys = [];
let relations;

function checkSubset() {
  let num = 0;
  for (let i of keys) {
    num = num | (1 << i);
  }
  for (let i of keyList) {
    if (i === (i & num)) return;
  }
  keyList.push(num);
}

function checkKeys() {
  const set = new Set();
  for (let i of relations) {
    let string = '';
    for (let j of keys) {
      string += i[j];
    }
    if (set.has(string)) return;
    set.add(string);
  }
  checkSubset();
}

function dfs(depth, start, max) {
  if (depth === max) {
    checkKeys();
    return;
  }
  for (let i = start; i < relations[0].length; i++) {
    if (visit[i] === 0) {
      visit[i] = 1;
      keys.push(i);
      dfs(depth + 1, i + 1, max);
      keys.pop();
      visit[i] = 0;
    }
  }
}

function solution(relation) {
  relations = relation;
  for (let i = 0; i < relation[0].length; i++) dfs(0, 0, i + 1);
  return keyList.length;
}
