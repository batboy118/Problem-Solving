function solution(n){
	let 사람 = 0;
	let 총악수 = 0;
	let temp = 0;
	while(true){
	  총악수 = parseInt((사람*(사람-1))/2, 10);
	  if(n < 총악수){
		break;
	  }
	  temp = 총악수;
	  사람 += 1;
	}
	return [parseInt(n-temp, 10), 사람];
}

const 악수의수 = 59;
console.log(solution(악수의수));

//조합
