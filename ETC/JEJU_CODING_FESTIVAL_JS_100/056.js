nationWidth = {
	'korea': 220877,
	'Rusia': 17098242,
	'China': 9596961,
	'France': 543965,
	'Japan': 377915,
	'England' : 242900,
}

let size = nationWidth['korea'];

delete nationWidth['korea']

let entry = Object.entries(nationWidth);
let values = Object.values(nationWidth);

let gap = Math.abs(values[0] - size);
console.log(gap);

let item = [];

for(let i = 1; i < values.length ; i++){
	if (gap > Math.abs(values[i] - size)){
		gap = Math.abs(values[i] - size);
		item = entry[i];
	}
}

console.log(item[0], gap);

// const nationWidth = {
// 	'korea': 220877,
// 	'Rusia': 17098242,
// 	'China': 9596961,
// 	'France': 543965,
// 	'Japan': 377915,
// 	'England' : 242900,
// };

// const w = nationWidth['korea'];

// delete nationWidth['korea'];

// const entry = Object.entries(nationWidth);
// const values = Object.values(nationWidth);

// //gap에 최댓값 저장
// let gap = Math.max.apply(null, values);
// let item = [];

// for (let i in entry){
//   if (gap > Math.abs(entry[i][1] - w)){
//     gap = Math.abs(entry[i][1] - w);
//     item = entry[i];
//   }
// }

// console.log(item[0],item[1]-220877);
