//10진수를 2진수로

let num = prompt("숫자를 입력하세요");
let bin = []

while(num)
{
	if(num % 2)
		bin.push('1')
	else
		bin.push('0')
	num = Math.floor(num/2);
}
bin = bin.reverse().join('');

console.log(bin);


// 정답
// let a = prompt('10진수를 입력해주세요.')
// let b = [];
// let result = '';

// while (a){
// 	b.push(a % 2);
// 	a = parseInt(a / 2, 10);
// }
// b.reverse();

// b.forEach((n) => {
//   result += n;
// })

// console.log(result);
