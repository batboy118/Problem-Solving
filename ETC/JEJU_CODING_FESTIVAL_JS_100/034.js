//sort 구현하기

function isSorted(val) {
	if(val.length > 1)
	{
		for(let i = 0; i < val.length - 1; i++)
		{
			if(val[i] > val[i + 1])
				return ('NO');
		}
	}
	return ('YES');
}

var h = prompt('키를 입력하세요.').split(' ');

console.log(isSorted(h));


// 정답
// const unsorted = prompt('키를 입력하세요');
// let sorted = "";

// sorted = unsorted
//   .split(" ")
//   .sort(function(a, b) {
//     return a - b;
//   })
//   .join(" ");

// if (unsorted === sorted) {
//   console.log("Yes");
// } else {
//   console.log("No");
// }
