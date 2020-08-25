let str = prompt("숫자를 입력하세요").split('')

let len = str.length
let res = ''

for(i in str)
{
	if(len%3 == 0 && len != 0 && i !=0 )
	{
		res += ',' + str[i]
	}
	else
	{
		res += str[i]
	}
	len--
}

console.log(res)

//2번풀이
let n = prompt('숫자를 입력해주세요.');
n = parseInt(n, 10);

console.log(n.toLocaleString());
