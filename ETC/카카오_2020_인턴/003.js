//효율성 몇개 통과못함.

function solution(gems) {
	var answer = [1, gems.length];
	let list = {};

	for(let i = 0; i <gems.length; i++){
		list[gems[i]] = -1;
	}
	let kyeList = Object.keys(list);

	if(kyeList.length == 1)
		return [1,1];

	let temp_min = -1;

	for(let i = 0; i <gems.length; i++){
		if(gems[i] == gems[i+1]){
			continue;
		}
		list[gems[i]] = i + 1;
		if(temp_min != -1 && gems[temp_min - 1] != gems[i])
			continue;
		let min = 200000;
		for(let s of kyeList){
			if(list[s] < min)
				min = list[s];
		}
		if(min == -1)
			continue;
		if(i + 1 - min < answer[1] - answer[0])
		{
			answer = [min, i + 1];
		}
		temp_min = min;
	}
	return answer;
}


console.log(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]));

