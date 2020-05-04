function solve(a, b){
	let c = [];
	let len = a.length;

	for(let i = 0; i < len; i++){
		let row = [];
		for(let j = 0; j < len; j++){
			let x = 0;
			for(let k=0; k < a[0].length; k++){
				x += a[i][k] * b[k][j];
			}
			row.push(x);
		}
		c.push(row);
	}
	return c;
}

let a = [[1, 2, 3], [2, 4, 5]];
let b = [[1, 0], [0, 3], [0, 4]];

if(a[0].length !== b.length)
	console.log(-1);
else
	console.log(solve(a,b));
