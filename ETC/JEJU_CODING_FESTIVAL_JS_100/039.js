//오타 수정하기

let str = prompt("입력하세요").split('');

for(let i = 0; i < str.length; i++)
{
	if(str[i] == 'q')
		str[i] = 'e'
}

let res = str.join('');
console.log(res);


// 정답
// //1. 함수사용
// const word = prompt('입력하세요.');

// function replaceAll(str, searchStr, replaceStr) {
//    return str.split(searchStr).join(replaceStr);
// }

// console.log(replaceAll(word,"q","e"));

// //2. 정규식 사용
// const word = prompt('입력하세요.');

// console.log(word.replace(/q/gi, 'e'));
