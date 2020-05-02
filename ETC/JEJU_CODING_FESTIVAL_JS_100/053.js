let inp = prompt("입력").split('');

function fn(inp){
	let store = [];
	for(let i = 0; i < inp.length; i++)
	{
		if(inp[i] == '(')
		{
			store.push('(');
		}
		else if(inp[i] == ')')
		{
			if(store.length == 0 || store.pop() != '(')
				return 'NO';
		}
	}
	if(store.length != 0)
		return 'NO';
	return 'YES';
}

console.log(fn(inp));

