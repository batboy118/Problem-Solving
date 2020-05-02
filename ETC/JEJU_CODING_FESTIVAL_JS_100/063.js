const user_input = prompt('문자열을 입력하세요').split(' ');
let result = '';

for (let s of user_input){
  result += s.slice(0, 1);
}

console.log(result);
