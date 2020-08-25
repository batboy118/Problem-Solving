let student_score = [];
let class_score = [];
let total_score = [];
let avg_class = [];
let first_student = [];
let avg_total = 0;
let total_sum = 0;

for (let j = 0; j<7; j++){
	let temp_sum = 0;
	let avg_per = [];
	for (let j = 0; j<30; j++){
		let per_sum = 0;
		for (let i=0; i<5; i++){
			student_score.push(Math.floor(Math.random()*100)+1);
			per_sum += student_score[i];
		}
		temp_sum += per_sum;
		avg_per.push(per_sum);
		class_score.push(student_score);
		student_score = [];
	}
	first_student.push(Math.max.apply(null, avg_per)/5)
	total_score.push(class_score);
	class_score = [];
	avg_class.push(temp_sum / 150);
	total_sum += temp_sum;
}
avg_total = total_sum / 1050;


console.log("반 점수")
console.log(total_score);

console.log("반 평균점수")
console.log(avg_class);

console.log("전교 평균")
console.log(avg_total)

console.log("반별 1등")
console.log(first_student)

console.log("")
//2번풀이
let student_score2 = [];
let class_score2 = [];
let total_score2 = [];

for (let k = 0; k < 7; k++) {
  class_score2 = [];
  for (let j = 0; j < 30; j++) {
    student_score2 = [];
    for (let i = 0; i < 5; i++) {
      student_score2.push(Math.floor(Math.random() * 100) + 1);
    }
    class_score2.push(student_score2);
  }
  total_score2.push(class_score2);
}

console.log(total_score2);

let total_average = [];
let c_average = [];
let s_average = 0;
let s_sum = 0;
let c_sum = 0;
let student_one = 0;
let 일등 = 0;

for (let c of total_score) {
  // console.log(c);
  for (let s of c) {
    s_sum = s.reduce((a, b) => a + b);
    s_average = s_sum / 5;
    c_average.push(s_average);
    if (일등 < s_average){
      일등 = s_average;
    }
  }
  console.log("일등 : ");
  console.log(일등);
  일등 = 0;
  console.log("반평균 : ");
  console.log(c_average);
  total_average.push(c_average.reduce((a, b) => a + b)/30);
  c_average = [];
}
console.log("반 평균 : ");
console.log(total_average);
console.log("전체 평균 : ");
console.log(total_average.reduce((a, b) => a + b)/7);
