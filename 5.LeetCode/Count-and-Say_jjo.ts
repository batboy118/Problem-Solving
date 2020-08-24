function countAndSay(n: number): string {
	let base = '1';
	for(let i = 1; i < n; i++){
		let temp = '';
		let cnt = 1;
		for(let j = 0; j < base.length; j++){
			if(base[j] != base[j + 1]){
				temp += String(cnt);
				temp += base[j];
				cnt = 1;
			} else{
				cnt++;
			}
		}
		console.log(temp);
		base = temp;
	}
	return base;
};
