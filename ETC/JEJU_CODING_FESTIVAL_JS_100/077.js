let s1 = prompt("s1");
let s2 = prompt("s2");

let max = 0;
console.log(Math.min(s1.length, s2.length));
for(let i = 0; i < s1.length; i++){
	if(max == Math.min(s1.length, s2.length))
		break;
	for(let j = 0; j < s2.length; j++){
		if(s1[i] == s2[j]){
			let add = 1;
			for(; i + add < s1.length || j + add < s2.length; add++){
				if(s1[i + add] != s2[j + add])
					break;
			}
			if(add > max)
				max = add;
		}
	}
}

console.log(max);

//풀이 2
function sol(strings){
    let result = [];
    for (let i=1; i<strings.length+1; i++){
        for (let j=0; j<i; j++){
            result.push(strings.slice(j, j+strings.length-i+1));
        }
    }
    return result;
}

const input1 = prompt('첫번째 문자열을 입력해주세요.');
const input2 = prompt('두번째 문자열을 입력해주세요.');
const list1 = sol(input1);
const list2 = sol(input2);

//공통 부분 문자열 찾기- 교집합
let intersection = list1.filter(x => list2.includes(x));

console.log(intersection)
//문자열 길이로 내림차순 정렬
intersection.sort((a,b)=>{
    return b.length-a.length;
});

console.log(intersection[0].length);
