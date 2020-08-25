let num = '7';
let count = [1];
let tmp = [];

for(let i = 1; i < num; i++){
	tmp = [];
	for(let j in count){
		tmp.push(Number(j) + 1);
		tmp.push(count[j]);
	}
	count = [];
	for(let j = 1; j <= Math.max.apply(null, tmp); j++){
		let n = 0;
		for(let k = 0; k < tmp.length; k++){
			if(j == tmp[k]){
				n++;
			}
		}
		if(n != 0)
			count.push(n);
	}
}
console.log(tmp.join(""));

//2번 풀이
function solution(n){
	let answer = '1';

	if(n === 1){
	  return 1;
	}

	for (let i=1; i<n; i++){
	  answer = rule(answer);
	}

	return answer;
  }

  function rule(answer){
	let answerMax = 9;
	let result = '';

	for (let i=1; i<answerMax; i++){
	  let re = new RegExp(i, 'g');
	  let count = (answer.match(re) || []).length;

	  if(count >=1){
		result = result + String(i) + String(count);
	  }
	}
	return result
  }

  const user_input = 7;
  console.log(solution(user_input));
