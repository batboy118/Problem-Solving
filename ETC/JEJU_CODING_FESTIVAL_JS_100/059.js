let str = prompt("입력")

let len = str.length

let n = 25 + Math.floor(len/2)

let a = str.padStart(n, '=');

console.log(a.padEnd(50,'='));
