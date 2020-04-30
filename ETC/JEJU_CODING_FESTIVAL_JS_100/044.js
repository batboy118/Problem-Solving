//각 자리수의 합
let num = prompt("숫자 입력하세요")
let temp = 0;

while(num)
{
	temp += num %10;
	num = Math.floor(num/10);
}

console.log(temp);
