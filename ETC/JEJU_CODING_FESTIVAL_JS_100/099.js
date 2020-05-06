돌의내구도 = [1, 2, 1, 4, 1, 4, 5, 2]
토끼의점프력 = [2, 1, 3, 1, 7, 1, 1]

let res = []

for(let i of 토끼의점프력){
	let 토끼 = 0;
	let flag = 1;
	for(let j = i - 1; j < 돌의내구도.length; j += i){
		돌의내구도[j]--;
		if(돌의내구도[j] == -1){
			res.push('fail');
			flag = 0;
			break;
		}
	}
	if(flag){
		res.push('pass');
	}
}

console.log(res);

//풀이2번
function doong(r, j){
	let answer = [];
	for(let i=0; i<j.length; i++){
	  answer.push('pass');
	}

	for(let i=0; i<j.length; i++) {
	  let p = 0;
	  while (p < r.length-1){
		p += j[i];
		r[p-1] -= 1;

		if (r[p-1] < 0){
		  answer[i] = "fail";
		}
	  }
	}

	return answer;
  }

돌의내구도 = [1, 2, 1, 4, 1, 4, 5, 2]
토끼의점프력 = [2, 1, 3, 1, 7, 1, 1]

  console.log(doong(돌의내구도, 토끼의점프력));
