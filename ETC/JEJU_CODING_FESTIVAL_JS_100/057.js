let count = 0;

for (let i = 0; i <= 1000; i++){
	temp = i
	while(temp)
	{
		if(temp%10 == 1)
			count++;
		temp = Math.floor(temp/10);
	}
}

console.log(count)

//2번 답안
const obj = {};

for (let i = 0; i <= 1000; i++) {
    let tmp = i;
    while (tmp > 0) {
        let num = tmp % 10;
        if (obj[num]) {
            obj[num]++;
        } else {
            obj[num] = 1;
        }
        tmp = parseInt(tmp/10, 10);
    }
}

console.log(obj[1]);

//3번 답안
let s = ''
for(let i = 0; i<=1000; i++){
  s += i
}
//console.log(s);
console.log(s.match(/1/g).length);


//4번 답안
let ss = ''
for(let i = 0; i<=1000; i++){
  ss += i;
}
let counts = 0
for(let j in ss){
  if(ss[j] == 1){
    counts++;
  }
}
console.log(counts);

//5번답안
let sss = ''
for(let i = 0; i<=1000; i++){
  sss += i;
}
let cnt = 0
for(let j of sss){
  if (j == 1){
    cnt++;
  }
}
console.log(cnt);
