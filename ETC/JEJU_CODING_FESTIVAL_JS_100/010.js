const n = prompt("숫자를 입력하세요");

let stars ='';
for(var i = 0; i < n; i++)
{
	for(var j = 0; j < n * 2; j++)
	{
		if(i >= Math.abs(5 - j))
			stars = stars + '*';
		else
			stars = stars + ' ';
	}
	if(i != n - 1)
		stars = stars + '\n';
}

console.log(stars);
