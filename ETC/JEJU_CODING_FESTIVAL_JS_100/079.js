const l = [10, 20, 25, 27, 34, 35, 39]; //기존 입력 값
const n = 2;

function rotate(inL, inN){
	let before = inL.slice();
	inN = inN % inL.length;

	for(let i = 0; i < inN; i++){
		let temp = inL.pop();
		inL.splice(0,0,temp) ;
	}

	let min = Math.max.apply(null,before);
	let minIdx = before.indexOf(min);
	for(let i in inL.length){
		let temp = Math.abs(inL[i] - before[i])
		if(temp < min){
			min = temp;
			minIdx = i;
		}
	}
	console.log(`index : ${minIdx}`);
	console.log(`value : ${before[minIdx]}, ${inL[minIdx]}`);
}
console.log(l)
console.log(n)
rotate(l, n)

//풀이 2


function rotate2(a, t){
    let b = a.slice();
    let c = [];
    for (let i=0; i<t; i++){
        b.unshift(b.pop());
    }

    for (let i=0; i<a.length; i++){
        c.push(Math.abs(a[i]-b[i]));
    }

    //최솟값
    const d = Math.min.apply(null, c);

		//최솟값의 인덱스 구하기
    let index = c.indexOf(d);

    console.log("index :",index);
    console.log("value :",a[index],b[index]);
}
console.log(l)
console.log(n)
rotate2(l, n);
