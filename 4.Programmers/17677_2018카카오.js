// Programmers
// no. 17677
// [1차] 뉴스 클러스터링
// https://programmers.co.kr/learn/courses/30/lessons/17677
// by JH (batboy118)

function solution(str1, str2) {
	var answer = 0;
	let s1 = {};
	let s2 = {};
	for(let i = 0; i < str1.length - 1; i++){
		let temp = str1.substring(i,i+2).toLowerCase();
		let flag = 1;
		for( var j=0; j<2; j++){
			if(!((temp.charCodeAt(j) >= 'a'.charCodeAt(0) && temp.charCodeAt(j) <= 'z'.charCodeAt(0)) || (temp.charCodeAt(j) >= 'A'.charCodeAt(0)) && temp.charCodeAt(j) <= 'Z'.charCodeAt(0))){
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			continue;
		if(flag == 0)
			continue;
		if(s1[temp]){
			s1[temp]++;
		} else{
			s1[temp] = 1;
		}
	}
	for(let i = 0; i < str2.length - 1; i++){
		let temp = str2.substring(i,i+2).toLowerCase();
		let flag = 1;
		for( var j=0; j<2; j++){
			if(!((temp.charCodeAt(j) >= 'a'.charCodeAt(0) && temp.charCodeAt(j) <= 'z'.charCodeAt(0)) || (temp.charCodeAt(j) >= 'A'.charCodeAt(0)) && temp.charCodeAt(j) <= 'Z'.charCodeAt(0))){
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			continue;
		if(s2[temp]){
			s2[temp]++;
		} else{
			s2[temp] = 1;
		}
	}

	let min = 0;
	let max = 0;
	let set = new Set();
	let key1 = Object.keys(s1);
	let key2 = Object.keys(s2);

	if(key1.length == 0 && key2.length == 0){
		return 65536;
	}
	for(let i = 0; i < key1.length; i++){
		set.add(key1[i])
	}
	for(let i = 0; i < key2.length; i++){
		set.add(key2[i])
	}
	for ( let item of set ) {
		if(s1[item] && s2[item]){
			min += Math.min(s1[item], s2[item])
			max += Math.max(s1[item], s2[item])
		} else if(s1[item]){
			max +=s1[item], s2[item]
		} else {
			max += s2[item]
		}
	}
	answer = Math.floor(min/max * 65536);
    return answer;
}

console.log(solution("aa1+aa2", "AAAA12"));
