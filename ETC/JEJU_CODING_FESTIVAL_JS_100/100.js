퍼즐판 = [[0,0,0,0],[0,1,0,3],[2,5,0,1],[2,4,4,1],[5,1,1,1]]
조작 = [1,1,1,1,3,3,3]

let ans = 0;
let stack = [];

for(let i of 조작){
	let flag = 1;
	for(let j = 0; j < 퍼즐판.length; j++){
		if(퍼즐판[j][i - 1]){
			flag = 0;
			stack.push(퍼즐판[j][i - 1]);
			퍼즐판[j][i - 1] = 0;
			break;
		}
	}
	if(flag){
		ans--;
	} else{
		for(let j = 0; j < stack.length - 1; j++){
			if(stack[j] == stack[j+1]){
				ans += stack[j] * stack[j];
				stack.splice(j,2);
				j = 0;
			}
		}
	}
}
console.log(퍼즐판)
console.log(stack)
console.log(ans)


//2번풀이
function solution(plate, moves){
	let stack = [0];
	let point = 0;

	while (moves.length !== 0){
	  let m = moves.shift();
	  for (let i=0; i<plate.length; i++){
		if (plate[i][m-1] !== 0) {
		  if (stack[stack.length-1] == plate[i][m-1]) {
			point += plate[i][m-1]*2;
			plate[i][m-1] = 0;
			stack.pop();
		  } else {
			stack.push(plate[i][m-1]);
		  }
		  plate[i][m-1] = 0;
		  break;
		} else {
		  if (i == plate.length-1 && plate[i][m-1] == 0){
			point -= 1;
		  }
		}
	  }
	}

	return point;
  }

  const plate = [[0,0,0,0],[0,1,0,3],[2,5,0,1],[2,4,4,1],[5,1,1,1]];
  const moves = [1,1,1,1,3,3,3];

  console.log(solution(plate, moves));
