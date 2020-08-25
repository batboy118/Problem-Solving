let num = prompt();


function sol(num){
	if(num == 0){
		return 0;
	}
	let len = num.length;
	let list = [1];
	let total = 0;

	for(let i = 0; i < len - 1; i++)
	{
		list.push(list[i] * 3);
		total += list[i];
	}

	for(let i = 1; i <= num[0]; i++)
	{
		if(i % 3 == 0)
		{
			total += list[len - 1];
		}
	}
	if(num[0] % 3 == 0)
	{
		num = num.slice(1, len - 1);
		total += sol(num);
	}
	return total;
}

console.log(sol(num))


//풀이 2
function sol(n){
    let answer = 0;
    let count = 1;
    const d = {3 : 1, 6 : 2, 9 : 3};

    while (n.length !== 0){
        answer += d[parseInt(n.pop(), 10)] * count;
        count *= 3;
    }


    return answer;
}

let user_input = new String(prompt('입력해주세요')).split('');

console.log(sol(user_input));
