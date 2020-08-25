let num = prompt("2보다 큰 짝수를 입력하세요")

function isPrime(n){
	if(n < 2)
		return false;
	else if(n < 4)
		return true;
	for(let i = 2; i * i <= n; i++){
		if(n % i == 0)
			return false
	}
	return true;
}

for (let i = 2 ; i < num; i++)
{
	let temp = num - i;
	if(isPrime(i) && isPrime(temp))
		console.log(i, temp);
}


//풀이 2
function prime_list(n){
    //에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    let sieve = []
    for(let i = 2; i < n; i++){
      sieve.push(true);
    }
    // console.log(sieve);

    //n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    let m = parseInt(n ** 0.5, 10);
    // console.log(m);
    for(let i = 2; i < m + 1; i++){
        if (sieve[i] == true){      // i가 소수인 경우
          for(let j = i+i; j < n; j+=i){ // i이후 i의 배수들을 False 판정
                sieve[j] = false;
            }
        }
    }
    // 소수 목록 산출
    let 소수목록 = [];
    for(let i = 2; i < n; i++){
      if (sieve[i] == true){
        소수목록.push(i)
      }
    }
    return 소수목록;
}
// console.log(prime_list(10000));

// let 소수 = [];
// let 소수판별 = true;

// for(let i=2; i<100; i++){
//   for(let j=2; j<i; j++){
//     if(i%j == 0){
//       소수판별 = false;
//     }
//   }
//   if (소수판별){
//     소수.push(i);
//   }
//   소수판별 = true;
// }

// console.log(소수);
let 입력숫자 = parseInt(prompt('숫자를 입력하세요:'), 10);

const 소수 = prime_list(입력숫자+1);
const 숫자 = 입력숫자;
let 순회 = 0;
let 골드바흐파티션 = [];
for(let n of 소수){
  // console.log(n);
  if(소수.includes(숫자-n)){
    골드바흐파티션.push([n, 숫자-n])
  }
  if(순회 > parseInt(소수.length / 2, 10)){
    break;
  }
  순회++;
}
console.log(골드바흐파티션);
let 차 = 골드바흐파티션.map(e => e[1]-e[0])
console.log(차.indexOf(Math.min.apply(null,차)));
let 차의인덱스 = 차.indexOf(Math.min.apply(null,차))
console.log(골드바흐파티션[차의인덱스]);
