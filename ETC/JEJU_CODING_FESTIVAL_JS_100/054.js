function sol(l){
	l.sort((a,b) => {
	  return a-b;
	});

	for (let i=0; i<=l.length-1; i++){
	  if(l[i]+1 !== l[i+1]){
		return 'NO';
	  } else {
		return 'YES';
	  }
	}
  }

let a = prompt().split(' ').map(a => parseInt(a, 10));
console.log(sol(a));;
