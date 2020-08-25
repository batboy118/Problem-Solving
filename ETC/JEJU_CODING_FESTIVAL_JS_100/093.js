let pages = 'ABCDABEA';
let frame = 3;
let total = 0;
let memory = [];

for(let i of pages){
	if(memory.includes(i))
	{
		total += 1;
	} else if(memory.length < frame){
		memory.push(i);
		total += 6;
	} else{
		memory.shift(1);
		memory.push(i);
		total += 6;
	}
}

console.log(total);
