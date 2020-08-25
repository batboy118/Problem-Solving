// Programmers
// no. 17680
// [1차] 캐시
// https://programmers.co.kr/learn/courses/30/lessons/17680
// by JH (batboy118)

function solution(cacheSize, cities) {
	var answer = 0;
	let cache = [];
	if (cacheSize == 0){
		answer = cities.length * 5;
	} else {
		for(let i = 0; i < cities.length; i++){
			let temp = cities[i].toLowerCase();
			if(cache.includes(temp)){
				cache.splice(cache.indexOf(temp),1);
				cache.push(temp);
				answer += 1;
			}else if(cacheSize > cache.length){
				cache.push(temp);
				answer += 5;
			} else {
				cache.shift();
				cache.push(temp);
				answer += 5;
			}
		}
	}
	return answer;
}
