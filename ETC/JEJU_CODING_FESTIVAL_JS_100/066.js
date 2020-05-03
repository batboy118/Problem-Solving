let tower = ["ABCDEF", "BCAD", "ADEFQRX", "BEDFG", "EFGHZ"];
let rule = "ABD"

let res = [];

function chcek(tower){
let temp = 0;

for (i in tower){
	for (j in rule){
		if(tower[i] == rule[j]){
			if (temp > j){
				return '불가능';
			} else {
				temp = j;
			}
		}
	}
}
return '가능';
}

for (i in tower){
	res.push(chcek(tower[i]));
}

console.log(res);


//2번
function solution(전체블록, 규칙){
	let answer = [];
	for (let 부분블록 of 전체블록){
	  answer.push(블록순서체크(부분블록, 규칙));
	}
	return answer;
  }

  function 블록순서체크(부분블록, 규칙){
	let 임시변수 = 규칙.indexOf(규칙[0]);
	for (let 문자 of 부분블록){
	  if (규칙.includes(문자)){
		if (임시변수 > 규칙.indexOf(문자)){
		  return '불가능';
		}
		임시변수 = 규칙.indexOf(문자);
	  }
	}
	return '가능';
  }


  const 전체블록 = ['ABCDEF', 'BCAD', 'ADEFQRX', 'BEDFG', 'AEBFDGCH'];
  const 규칙 = 'ABCD';

  console.log(solution(전체블록, 규칙));
  //["가능", "불가능", "가능", "가능", "불가능"]
