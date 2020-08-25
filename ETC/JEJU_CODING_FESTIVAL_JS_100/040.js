//놀이동산에 가자
let maxWeight = parseInt(prompt("최대 수용가능 무게"));
let numberOfPeople = parseInt(prompt("대기 중인 사람"));
let list = [];
for(let i = 0; i< numberOfPeople ; i++)
	list[i] = parseInt(prompt(i + 1 + '번째 사람의 몸무게를 입력하세요'));
let temp = 0;
let cnt = 0;
for(let i = 0; i< numberOfPeople ; i++)
{
	if(maxWeight >= temp + list[i])
	{
		temp += list[i];
		cnt++;
	}
}
console.log(cnt);

// 정답
// let total = 0;
// let count = 0;
// const limit = prompt('제한 무게를 입력하세요.');
// const n = prompt('인원수를 입력하세요.');

// for (let i=1; i<=n; i++){
//   total += parseInt(prompt('무게를 입력해주세요.'), 10);
//   if (total <= limit){
// 		count = i;
//   }
// }

// console.log(count);
