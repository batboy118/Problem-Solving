let num = prompt("숫자를 입력하세요");

for(let i = 2; i < Math.ceil(Math.sqrt(num)); i++)
{
	if(num % i === 0)
	{
		console.log("NO")
		break;
	}
	if(Math.ceil(Math.sqrt(num)) - 1 == i)
	{
		console.log("YES")
	}
}
if(num < 2)
{
	console.log("NO")
}
if(num === 3)
{
	console.log("YES")
}

// 정답
// const num = prompt('숫자를 입력하세요.');

// function check_prime(num) {
//   for (let i=2; i<num; i++) {
//     const result = num % i;
//     if (result === 0) {
//       console.log('NO');
//       return false;
//     }
//   }
//   if (num === 1) {
//     console.log('NO');
//     return;
//   }
//   console.log('YES');
// }

// check_prime(num);
