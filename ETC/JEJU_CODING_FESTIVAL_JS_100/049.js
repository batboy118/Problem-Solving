//최댓값 구하기

let numbers = prompt("숫자들을 입력하세요").split(' ').map((n) => {
	return parseInt(n, 10);
});

for(let i = 0; i < numbers.length; i++)
{
	if (max < numbers[i])
		max = numbers[i];
}

console.log(max);
