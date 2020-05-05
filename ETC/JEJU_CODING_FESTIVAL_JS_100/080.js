let res = [];
let visit = [];

function combi(list, n, r, depth, start){
	if(depth === r){
		let temp = ''
		for(let i = 0; i < n; i++){
			if(visit.includes(list[i])){
				temp+=list[i];
			}
		}
		res.push(temp);
		return;
	}
	for(let i = start; i < n; i++){
		if(!visit.includes(list[i])){
			visit.push(list[i]);
			combi(list, n, r, depth + 1, i + 1)
			visit.pop();
		}
	}
	return;
}


let list = ['ㄱ','ㄴ','ㄷ','ㄹ'];
let r = 3;

combi(list, list.length, r, 0, 0);
console.log(res);
console.log(res.length);


//2번
function combination(chars) {
    let combi = [];

    const f = (prefix, chars) => {
      for (let i=0; i<chars.length; i++) {
        combi.push(prefix + chars[i]);

        f(prefix + chars[i], chars.slice(i + 1));
      }
    }

    f('', chars);

	//조합의 수에 맞는 것만 추출!
	//console.log(combi);
    const result = combi.filter(x => x.length === n);
    console.log(result);

    return result.length;
}

const arr = ['ㄱ','ㄴ','ㄷ','ㄹ'];
const n = 3;

console.log(combination(arr));
