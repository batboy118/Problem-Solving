let raw_data = "1번: 3,1 2번: 4 3번: 2,1,3 4번: 2,1,3,4".split(' ');
let data = []
for (let i in raw_data){
	if(i % 2){
		data.push(raw_data[i]);
	}
}

let ans = [];
for (let i in data){
	let temp = data[i].split(',');
	for (j in temp){
		if(!ans.includes(temp[j])){
			ans.push(temp[j]);
		}
	}
}
console.log(ans)

//2번 풀이
function solution(i) {
	//먼저 번호로 자릅니다.
	let idx = i.split(/[0-9]번: /g);
	console.log(idx);

	//잘라낸 문자열의 첫번째 요소 ""를 없애줍니다.
	idx.shift();
	console.log(idx);

	for(let i=0; i<idx.length; i++){
		//공백을 없애주고 ',' 단위로 잘라줍니다.
		idx[i] = idx[i].replace(/ /g, '').split(',');

		for(let j=0; j<idx[i].length; j++){
			idx[i][j] = parseInt(idx[i][j], 10);
		}
	}
	console.log(idx);

	let answer = [];

	//기록된 번호 순서대로 값이 중복 되지 않게 answer에 넣어줍니다.
	for(let i of idx){
		for (let j of i){
			if(!answer.includes(j)){
				answer.push(j);
			}
	 	 }
	}

	  return answer;
  }

  let i = "1번: 3,1 2번: 4 3번: 2,1,3 4번: 2,1,3,4";
  console.log(solution(i));
