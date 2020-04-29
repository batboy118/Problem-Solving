let pyo = prompt("입력").split(' ');
let res = {};
let win ='';
let maxIndex;

for(let i = 0; i < pyo.length; i++)
{
	let val = pyo[i];
	if(res[val] === undefined)
		res[val] = 1;
	else
		res[val]++;
}
keyList = Object.keys(res);
win = keyList[0];
for(let i = 1; i < keyList.length; i++)
{
	if(res[win] < res[keyList[i]])
		win = keyList[i];
}
console.log(`${win}(이)가 총 ${res[win]}표로 반장이 되었습니다.`);

// 정답

// const array = prompt('이름을 입력해주세요.').split(' ');
// let result = {};
// let winner = "";

// for(let index in array){
//   let val = array[index];
//   result[val] = result[val] === undefined ? 1 : result[val] = result[val] + 1;
// }

// winner = Object.keys(result).reduce(function(a, b){
//   return result[a] > result[b] ? a : b
// });

// console.log(`${winner}(이)가 총 ${result[winner]}표로 반장이 되었습니다.`);
