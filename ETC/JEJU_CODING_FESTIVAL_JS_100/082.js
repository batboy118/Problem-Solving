function math(e){
	let list = [];
	for(let s of e){
		if(s=='('){
			list.push(s);
		}
		else if(s == ')'){
			if(list.length == 0 || list.pop == ')')
				return false;
		}
	}
	if(list.length != 0)
		return false;
	return true;
}

while (1){
    let order = prompt('데이터 입력(1), 프로그램 종료(2)');
    if (order == 1){
        const ex = prompt('데이터를 입력하세요');
        console.log(math(ex));
    } else {
        break;
    }
}


//두번째 풀이
function sol(d){
    let step = 0;
    for (let i in d){
        if (d[i] ==="("){
            step += 1;
        } else if (d[i] === ")"){
            step -=1;
        }
    }
    if (step !== 0){
        return false;
    }
    if (step === 0){
        return true;
    }
}

while (1){
    const n = prompt('데이터 입력(1), 프로그램 종료(2)');
    if (n === '1'){
        const str = prompt('데이터를 입력하세요').split('');
        console.log(sol(str));
    } else{
        break;
    }
}
