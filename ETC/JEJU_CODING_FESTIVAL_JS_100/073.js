const graph = {'A': ['B', 'C'],
		'B': ['A', 'D', 'E'],
		'C': ['A', 'F'],
		'D': ['B'],
		'E': ['B', 'F'],
		'F': ['C', 'E']};

const user_input = prompt('입력해주세요').split(' ');
const start = user_input[0];
const end = user_input[1];

let queue = [start];
let visited = [start];

function solution(){
let count = -1;

while (queue.length !== 0){
	count += 1;

	let size = queue.length;

	for (let i=0; i<size; i++){
			let node = queue.splice(0,1);
			if (node == end){
				return count;
			}

			for (let next_node in graph[node]) {
				if (!visited.includes(graph[node][next_node])){
					visited.push(graph[node][next_node]);
					queue.push(graph[node][next_node]);

				}
			}
		}
	}
}
console.log(solution());
