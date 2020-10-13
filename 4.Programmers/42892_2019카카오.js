// Programmers
// no. 42891
// 길 찾기 게임
// https://programmers.co.kr/learn/courses/30/lessons/42892
// by JH (batboy118)

let answer = [[], []];

function pre(cur, preTree) {
  answer[0].push(cur);
  if (preTree[cur].left) pre(preTree[cur].left, preTree);
  if (preTree[cur].right) pre(preTree[cur].right, preTree);
}

function post(cur, preTree) {
  if (preTree[cur].left) post(preTree[cur].left, preTree);
  if (preTree[cur].right) post(preTree[cur].right, preTree);
  answer[1].push(cur);
}

function solution(lst) {
  let nodeinfo = lst.map((a) => [...a]);
  nodeinfo.forEach((lst, index) => lst.push(1 + index));
  nodeinfo.sort((a, b) => b[1] - a[1]);
  const tree = {};
  const root = nodeinfo[0][2];
  tree[root] = {};
  for (let i = 1; i < nodeinfo.length; i++) {
    const node = nodeinfo[i];
    tree[node[2]] = {};
    let cur = root;
    while (1) {
      if (node[0] < lst[cur - 1][0]) {
        if (tree[cur].left === undefined) {
          tree[cur].left = node[2];
          break;
        }
        cur = tree[cur].left;
      } else {
        if (tree[cur].right === undefined) {
          tree[cur].right = node[2];
          break;
        }
        cur = tree[cur].right;
      }
    }
  }
  pre(root, tree);
  post(root, tree);
  return answer;
}
