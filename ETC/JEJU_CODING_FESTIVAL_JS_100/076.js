let tc = Number(prompt("테스트 케이스 수"));
let info = prompt("줄 및 커버리지 수").split(' ');
let lines = info[0];
let coverage = info[1];
let map = [];
for(let i = 0; i < lines; i++){
	map.push(prompt().split(' '))
}

let max = 0;
for(let i = coverage; i <= lines; i++){
	for(let j = coverage; j <= lines; j++){
		for(let x = i - coverage; x < i; x++){
			let temp = 0;
			for(let y = j - coverage ; y < j; y++){
				if(map[x][y]){
					temp++;
				}
			}
			if(max < temp)
				max=temp;
		}
	}
}

console.log(max);
