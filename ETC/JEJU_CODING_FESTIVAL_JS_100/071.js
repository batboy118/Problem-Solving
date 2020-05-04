let res = []

function dfs(g, start){
	let stack = [start];

	while (stack.length !== 0){
	  let n = stack.pop();
	  if (!res.includes(n)){
		res.push(n);
		let sub = g[n].filter(x => !res.includes(x));
		for(let i of sub) {
		  stack.push(i);
		}
	  }
	}
}

let graph = {	'E': ['D', 'A'],
			'F': ['D'],
			'A': ['E', 'C', 'B'],
			'B': ['A'],
			'C': ['A'],
			'D': ['E','F']}

dfs(graph, 'E');

console.log(res);
