// Programmers
// no. 42891
// 무지의 먹방 라이브
// https://programmers.co.kr/learn/courses/30/lessons/42891
// by JH (batboy118)

function solution(food_times, k) {
  var answer = 0;
  var i = 0;
  var t = 0;
  const order = food_times
    .map((time, index) => {
      return { time, index };
    })
    .sort((a, b) => a.time - b.time);
  while (k >= (order.length - i) * (order[i].time - t)) {
    k -= (order.length - i) * (order[i].time - t);
    t = order[i].time;
    while (order[i].time - t <= 0) {
      order[i].time -= t;
      if (order[++i] === undefined) return -1;
    }
  }
  k = k % (order.length - i);
  order.length = i;
  order.sort((a, b) => a.index - b.index);
  for (let j = 0; j < order.length; j++) {
    if (order[j].index <= k) k++;
  }
  return k + 1;
}
