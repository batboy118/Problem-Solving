let res = []

function bfs(g, start){
	let	queue = [start];

	while (queue.length !== 0){
		let n =	queue.shift();
		res.push(n);
		let sub = g[n].filter(x => !res.includes(x));
		for(let i of sub) {
			queue.push(i);
		}
	}
}

let graph = {	'E': ['D', 'A'],
			'F': ['D'],
			'A': ['E', 'C', 'B'],
			'B': ['A'],
			'C': ['A'],
			'D': ['E','F']}

bfs(graph, 'E');

console.log(res);
