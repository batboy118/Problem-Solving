//DP문제

const 텃밭 = [
	[0, 0, 0, 0, 0],
	[0, 1, 0, 0, 0],
	[0, 1, 0, 0, 0],
	[0, 0, 1, 0, 0],
	[0, 0, 0, 1, 0]];


function solution(텃밭){
	const 넓이 = 텃밭[0].length;
	const 높이 = 텃밭.length;

	let 텃밭합 = [];
	for (let i=0; i<텃밭.length; i++){
		텃밭합.push(Array(텃밭.length).fill(0));
	}

	for(let i=0; i<높이; i++){
		for(let j=0; j<넓이; j++){
			if (텃밭[i][j] == 0){
				텃밭합[i][j] = 1;
			} else {
				텃밭합[i][j] = 0;
			}
		}
	}

	for(let i=1; i<높이; i++){
		for(let j=1; j<넓이; j++){
			if (텃밭합[i][j] == 1){
				let min;
				if(텃밭합[i-1][j] > 텃밭합[i][j-1]){
					min = 텃밭합[i][j-1];
				} else if (텃밭합[i-1][j-1] > 텃밭합[i-1][j]) {
					min = 텃밭합[i-1][j];
				} else {
					min = 텃밭합[i-1][j-1]
				}
				텃밭합[i][j] = min + 1;
			}
		}
	}

	let maxValue = 0;
	let x = 0;
	let y = 0;

	for (let i=0; i<높이; i++){
		for (let j=0; j<넓이; j++){
			if (maxValue < 텃밭합[i][j]){
				maxValue = 텃밭합[i][j]
				x = i
				y = j
			}
		}
	}

	// console.log(maxValue, x, y);
	console.log(maxValue, 'X', maxValue);

	for(let i=x - (maxValue - 1); i<x+1; i++){
		for(let j=y - (maxValue - 1); j<y + 1; j++){
		텃밭[i][j] = '#';
		}
	}

	return 텃밭;
	}

console.log(solution(텃밭));
