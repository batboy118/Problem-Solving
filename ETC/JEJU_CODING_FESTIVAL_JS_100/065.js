let a = prompt('입력하세요').split(' ');
let b = prompt('입력하세요').split(' ');

let res = [];
let count = 0;

for (let i in a)
{
	let temp = [];
	if(count % 2){
		temp[0] = a[i];
		temp[1] = b[i];
	} else{
		temp[1] = a[i];
		temp[0] = b[i];
	}
	res[i] = temp;
}

console.log(res);


//2번 풀이
const a = prompt('입력하세요').split(' ');
const b = prompt('입력하세요').split(' ');
let c = [];
let count = 0;

a.forEach(function(e, i){
  if (count%2 === 0){
    c.push([e, b[i]]);
  } else {
    c.push([b[i], e]);
  }
  count++;
});

console.log(c);
