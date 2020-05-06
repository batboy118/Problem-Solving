function make_map(가로, 세로, 캐릭터위치, 장애물)
{
	let map = [];

	for(let i = 0; i < 세로 + 2; i++){
		let line = [];
		for(let j = 0; j < 가로+ 2; j++){
			if(i == 0 || j== 0 || j == 가로 + 1 || i == 세로 + 1){
				line.push(2);
			} else{
				line.push(0);
			}
		}
		map.push(line);
	}
	let s = 캐릭터위치;
	map[캐릭터위치[0]+1][캐릭터위치[1]+1] = 1;
	for(let s of 장애물){
		map[s[0] + 1][s[1] + 1] = 2;
	}
	for(let i of map) {
		console.log(i);
	  }
}

가로 = 4
세로 = 5
캐릭터위치 = [0,0]
장애물 = [[0,1],[1,1],[2,3],[1,3]]

make_map(가로, 세로, 캐릭터위치, 장애물)


//풀이 2번
function make_map(n,m,char,obj){
	//지도 초기화하기
	//각 지도 가로/세로 두칸 외벽을 포함한 크기만큼 추가하기(각 끝 한칸씩)
	let world_map = [];
	for(let i=0; i<m+2; i++){
	  world_map.push(Array(n+2).fill(0));
	}

	//지도 외벽 그리기
	for(let i in world_map){
	  for(let j in world_map[0]){
		if (i==0 || j==world_map[0].length-1 || j==0 || i==world_map.length-1) {
		  world_map[i][j] = 2;
		}
	  }
	}

	//지도에 캐릭터 추가하기/ 외벽으로 인해 좌표에 +1을 해줍니다.
	world_map[char[0]+1][char[1]+1] = 1;
	//지도에 장애물 추가하기
	for (let i of obj){
	  if (world_map[i[0]+1][i[1]+1] != 1){
		world_map[i[0]+1][i[1]+1] = 2;
	  } else {
		world_map[i[0]+1][i[1]+1] = 1;
	  }
	}
	//장애물을 추가하려는 자리에 캐릭터가 있을 시 캐릭터는 그대로둔다
	//마찬가지 외벽으로 인한 좌표 조정을 해준다.
	for(let i of world_map) {
	  console.log(i);
	}

  }

  make_map(4, 5, [0, 0], [[0,1],[1,1],[2,3],[1,3]]);
