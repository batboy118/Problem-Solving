//원의 넓이를 구하세요

function circle(r)
{
	return Math.pow(r,2) * 3.14;
}

var r = prompt('원의 반지름을 입력하세요');

console.log(circle(r));
