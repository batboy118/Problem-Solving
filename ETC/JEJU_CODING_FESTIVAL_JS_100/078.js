let n = 13;
let k = 4;

let dish = []
let temp = 0;
for(let i = 1; i <= n; i++){
	dish.push(i);
}
while(dish.length > 2){
	dish.splice(temp,1);
	temp = (temp + k - 1) % dish.length;
}

console.log(dish);


//풀이 2
function sol(n, k) {
	let i = 0;
	//q에 n만큼의 숫자를 넣어준다
	let q = [];
	for(let j=0; j<n; j++){
	  q.push(j+1);
	}

	while (q.length > 2) {
	  if (i > q.length-1) {
		//순환하다 i가 q의 길이보다 클 경우에 len(q)만큼 빼준다.
		//[1,2,3,4,5,6] -> 1다음 4가 빠지고 그 다음은 4+3 = 7(index : 6)이 빠져야 하는데
		//i(현재 빠져야 할 index)가 len(q)보다 크므로 len(q)즉, 4를 빼준다.
		//이걸 마지막 2개가 남을 때 까지 반복함
		i -= q.length;
	  }

	  q.splice(i, 1);
	  i += k;
	  i -= 1;
	}

	return q;
  }

  console.log(sol(n, k));
