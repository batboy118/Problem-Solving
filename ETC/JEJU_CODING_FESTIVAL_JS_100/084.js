let num = '1723'.split('');
let c = 2;
let max = 0;
let visit = [];

function permu(num, depth, n, c){
	if(depth == c){
		let temp = visit.join('');
		if(temp > max)
			max = temp;
		return;
	}

	for(let i in num){
		if(!visit.includes(num[i])){
			visit.push(num[i]);
			permu(num, depth + 1, n, c);
			visit.pop();
		}
	}
}
permu(num, 0, num.length, c)
console.log(max);


//2번 풀이
function solution(chars) {
  let permute = [];

  const f = (prefix, chars) => {
    for (let i=0; i<chars.length; i++) {
      permute.push(prefix + chars[i]);

      if (permute.indexOf(chars[i] + prefix) === -1) {
        permute.push(chars[i] + prefix);
      }

      f(prefix + chars[i], chars.slice(i + 1));
    }
  }

  f('', chars);

  let result = permute.filter(x => x.length === len);
  result.sort((a, b) => {return b-a});

  return result[0];
}

const num = prompt('숫자를 입력하세요').split('');
const len = parseInt(prompt('몇 개의 수를 선택하시겠습니까?'),10);
console.log(solution(num));
