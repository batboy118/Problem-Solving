//2020년

let a = prompt("월을 입력하세요");
let b = prompt("일을 입력하세요");

let daysOfMonth = [31,29,31,30,31,30,31,31,30,31,30,31];
let totalDays = 0;
for(i = 1; i < a; i++)
	totalDays += daysOfMonth[i];
totalDays += b - 1;
let offset = totalDays % 7;
let days = ['WED', 'THU', 'FRI', 'SAT', 'SUN', 'MON', 'TUE'];

console.log(days[offset]);

// 정답
// const month = prompt('월을 입력하세요.');
// const date = prompt('일을 입력하세요.');

// function solution(a,b){
//     const day = ["SUN","MON","TUE","WED","THU","FRI","SAT"];

//     const x = new Date('2020-'+a+'-'+b);
//     return day[x.getDay()];
// }
// console.log(solution(month, date));
