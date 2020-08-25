//구구단 출력

let dan = prompt('단을 입력하세요');

let res = '';
for(let i = 1; i < 10; i++)
{
	res += dan * i;
	res += ' ';
}
console.log(res);
