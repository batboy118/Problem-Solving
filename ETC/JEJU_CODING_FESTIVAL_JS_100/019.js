//제곱근 구하기
let a = prompt('두 수를 입력하세요.').split(' ');

let res = 1;
for (let i = 0; i < a[1]; i++)
	res *=a[0];
console.log(res);

// 정답
// const n = prompt('수를 입력하세요.').split(' ');
// console.log(Math.pow(parseInt(n[0], 10), parseInt(n[1], 10)));
