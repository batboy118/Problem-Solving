let map ="0 1 0 0 0\n0 0 0 0 0\n0 0 0 1 0\n0 0 1 0 0\n0 0 0 0 0".split('\n');

for(let s in map){
	map[s] = map[s].split(' ');
}

for(let i = 0; i < map.length; i++){
	for(let j = 0; j < map[i].length; j++){
		if(map[i][j] == 1){
			map[i][j] = 'f';
			if(i > 0){
				map[i - 1][j] = '*';
			}
			if(i < map.length - 1){
				map[i + 1][j] = '*';
			}
			if(j > 0){
				map[i][j - 1] = '*';
			}
			if(j < map[i].length - 1){
				map[i][j + 1] = '*';
			}
		}
	}
}

for (let i of map){
	console.log(i);
  }
  console.log();
//두번째 풀이
let value ="0 1 0 0 0\n0 0 0 0 0\n0 0 0 1 0\n0 0 1 0 0\n0 0 0 0 0"
let sp = value.split('\n');
let count = 0;

for (let i of sp){
  sp[count] = i.replace('1', 'f').split(' ');
  count += 1;
}

count = 0
let search = 0

for (let s of sp){
  for (let i of s){
    if (i === 'f'){
      search = s.indexOf(i);
      if (search > 0){
        s[search-1] = '*';
      }
      if (search < 4){
        s[search+1] = '*';
      }
      if (count > 0){
        sp[count-1][search] = '*';
      }
      if (count < 4){
        sp[count+1][search] = '*';
      }
    }
  }
  count += 1;
}

for (let i of sp){
  console.log(i);
}
