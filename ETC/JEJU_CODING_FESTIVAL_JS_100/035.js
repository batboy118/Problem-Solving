//팩토리얼 함수 사용하기

function one(n){
    function two(num){
		let res = 1;
		for(let i = 0; i < n; i++)
		{
			res *= num;
		}
		return res;
    }
    return two;
}

const a = one(2);
const b = one(3);
const c = one(4);

console.log(a(10));
console.log(b(10));
console.log(c(10));

// 정답
// function one(n) {
// 	function two(value) {
// 	  const sq = Math.pow(value, n);
// 	  return sq;
// 	}
// 	return two;
//   }

//   const a = one(2);
//   const b = one(3);
//   const c = one(4);

//   console.log(a(10));
//   console.log(b(10));
//   console.log(c(10));
