// Programmers
// no. 17686
// [3차] 파일명 정렬
// https://programmers.co.kr/learn/courses/30/lessons/17686#
// by JH (batboy118)

Array.prototype.stableSort = function(cmp) {
	cmp = !!cmp ? cmp : (a, b) => {
	  if (a < b) return -1;
	  if (a > b) return 1;
	  return 0;
	};
	let stabilizedThis = this.map((el, index) => [el, index]);
	let stableCmp = (a, b) => {
	  let order = cmp(a[0], b[0]);
	  if (order != 0) return order;
	  return a[1] - b[1];
	}
	stabilizedThis.sort(stableCmp);
	for (let i=0; i<this.length; i++) {
	  this[i] = stabilizedThis[i][0];
	}
	return this;
  }

  function solution(files) {
	  var list = [];
	  for(let f of files){
		  let head = ""
		  let num = 0;
		  let tail;
		  for(let i = 0; i < f.length; i++){
			  if(!(f[i] >= "0" && f[i] <= "9")){
				  head += f[i];
			  }
			  else {
				  head = head.toLowerCase();
				  while(f[i] >= "0" && f[i] <= "9"){
					  num = ((10 * Number(num)) + Number(f[i]));
					  i++;
				  }
				  tail = f.substring(i);
				  break;
			  }
		  }
		  list.push({file: f, head, num ,tail});
	  }
	  list.stableSort((a,b) => {
		  if(a.head > b.head) return 1;
		  else if(a.head < b.head) return -1;
		  if(a.num > b.num) return 1;
		  else if(a.num < b.num) return -1;
		  return 0;
	  })
	  return list.map(a => a.file);
  }
