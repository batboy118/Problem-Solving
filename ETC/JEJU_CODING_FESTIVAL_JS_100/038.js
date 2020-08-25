//호준이의 아르바이트

let score = prompt("점수를 입력하세요.").split(' ')
let res = {};

score.sort(function (a,b){
	return a-b;
});

for(let i = 0; i < score.length; i++)
{
	if(res[parseInt(score[i])] === undefined)
		res[parseInt(score[i])] = 1;
	else
		res[parseInt(score[i])]++;
}

let keyList = Object.keys(res);
let total =  res[keyList[keyList.length - 1]];
total += res[keyList[keyList.length - 2]]
total += res[keyList[keyList.length - 3]]
console.log(total)

// 정답

// const scores = prompt('점수입력').split(' ').map(function(n){
// 	return parseInt(n, 10);
//   });

//   scores.sort((a, b) => {
// 	return a-b;
//   });

//   let count = 0;
//   let arr = [];

//   while (arr.length < 3) {
// 	let n = scores.pop();
// 	if (!arr.includes(n)){
// 	  arr.push(n);
// 	}
// 	count += 1;
//   }

//   console.log(count);
