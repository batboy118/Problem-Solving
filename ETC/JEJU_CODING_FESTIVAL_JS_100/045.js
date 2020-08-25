//getTime()함수 사용하기

let d = new Date();
n = d.getTime();
let year = 1970;

while((year % 4 == 0 && n >= 3600*24*366*1000) || (year % 4 != 0) && n >= 3600*24*365*1000)
{
	if(year % 4)
		n = n - 3600*24*366*1000
	else
		n = n - 3600*24*365*1000
	year++;
}

console.log(year);
