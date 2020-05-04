let graph = {1: [2, 3, 4],
	2: [1, 3, 4, 5, 6],
	3: [1, 2, 7],
	4: [1, 2, 5, 6],
	5: [2, 4, 6, 7],
	6: [2, 4, 5, 7],
	7: [3, 5, 6]}

let user_input = prompt('입력해주세요').split(' ');
let start = user_input[0];
let end = user_input[1];

let queue = [start];
let visited = [start];

function solution(){
let count = -1;
let les = 0;

while (queue.length !== 0){
	count += 1;

	let size = queue.length;

	for (let i=0; i<size; i++){
			let node = queue.splice(0,1);
			if (node == end){
				res = count;
			}

			for (let next_node in graph[node]) {
				if (!visited.includes(graph[node][next_node])){
					visited.push(graph[node][next_node]);
					queue.push(graph[node][next_node]);

				}
			}
		}
	}
	return count;
}
console.log(solution());
