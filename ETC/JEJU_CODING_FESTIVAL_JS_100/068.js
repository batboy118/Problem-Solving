function calc(list, time){
	let res = [];
	for(let i in list){
		let temp = list[i].split(':').map(n => parseInt(n, 10));
		if(temp[0] > time[0] || (temp[0] == time[0] && temp[1] >= time[1])){
			let time_left = temp[0] * 60 + temp[1] - time[0] * 60 - time[1];
			let hour = parseInt(time_left / 60, 10);
			let minute = time_left % 60;
			res.push(String(hour).padStart(2, 0)+'시간 '+String(minute).padStart(2, 0)+'분');
		} else {
			res.push('지나갔습니다')
		}
	}
	console.log(res)
}


calc(["12:30", "13:20", "14:13"], "12:40".split(':').map(n => parseInt(n, 10)))

console.log("123"*60 + "123123")
