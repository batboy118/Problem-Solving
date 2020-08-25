var ch = prompt('문자를 입력하세요')

if(ch.charCodeAt(0) >= 'A'.charCodeAt(0) && ch.charCodeAt(0) <= 'Z'.charCodeAt(0))
	console.log('YES');
else
	console.log('NO');

// 정답
// const data = prompt('알파벳을 입력하세요.');

// if (data === data.toUpperCase()){
//   console.log('YES');
// } else {
//   console.log('NO');
// }
