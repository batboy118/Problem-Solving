let 도장 = [
	[1,1,1,2],
	[2,0,0,0],
	[1,1,1,1],
	[0,0,0,0]]
let 회전 = 1

회전 = 회전%4;
let temp = [];
let after = [];
for(let i = 0; i < 도장.length ;i++){
	let line1 = []
	let line2 = []
	for(let j = 0; j < 도장[i].length ; j++)	{
		line1.push(도장[i][j])
		line2.push(도장[i][j])
	}
	temp.push(line1)
	after.push(line2)
}

while(회전--){
	for(let i = 0; i < 도장.length ;i++){
		for(let j = 0; j < 도장[i].length ; j++){
			temp[j][i] = 도장[i][j];
		}
	}
	for(let i = 0; i < 도장.length ;i++){
		for(let j = 0; j < 도장[i].length ; j++){
			after[i][도장.length - j - 1] = temp[i][j];
		}
	}
}

console.log(도장);
console.log(after);
let res = [];
for(let i = 0; i < 도장.length ;i++){
	let temp = [];
	for(let j = 0; j < 도장[i].length ; j++){
		temp.push(도장[i][j] + after[i][j]);
	}
	res.push(temp);
}
console.log(res);


//풀이2
// 기본 입력부분입니다
// N, stmp, k를 입력받습니다.

let N = parseInt(prompt('도장의 크기를 입력하세요.'), 10);

let stmp = [];
// stmp = [
//   [1,1,1,2],
//   [2,0,0,0],
//   [1,1,1,1],
//   [0,0,0,0]];
for (let i=0; i<N; i++){
  let tmp = prompt('도장을 입력하세요').split(' ').map(x => parseInt(x, 10));
  stmp.push(tmp);
}
const k = parseInt(prompt('회전수를 입력하세요'), 10);


function solution(stmp,n) {
  N = stmp.length;
  // 0으로 만들어진 배열 생성
  let p = [];
  for(let i=0; i<N; i++){
    p.push(Array(N).fill(0));
  }

  // 회전시키기 전 최초 1번찍어주기
  p = sum_matrix(p,stmp);

  //회전시키며 도장찍기
  for(let i=0; i<n; i++) {
    stmp = rotate(stmp);
    p = sum_matrix(p,stmp);
  }
  return p;
}


//배열(도장) 회전시키기
function rotate(stmp){
  N = stmp.length;
  let rot = [];
  for(let i=0; i<N; i++){
    rot.push(Array(N)).fill(0);
  }

  for (let i=0; i<N; i++){
    for (let j=0; j<N; j++){
      rot[j][N-1-i] = stmp[i][j];
    }
  }
  return rot;
}


//행렬 더하기 즉 도장이 찍히는 정도를 더한다.
function sum_matrix(p,stmp){
  for(let i=0; i<p.length; i++){
    for(let j=0; j<p[0].length; j++){
      p[i][j] = p[i][j]+stmp[i][j];
    }
  }
  return p;
}

console.log(solution(stmp,k));
