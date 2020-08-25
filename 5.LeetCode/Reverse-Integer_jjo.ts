function reverse(x: number): number {
    let sign = '';
    if(x < 0){
        sign = '-';
        x *= -1;
    }
    let rn = Number(sign + String(x).split("").reverse().join(""));
    if(-(Math.pow(2,31)) > rn || (Math.pow(2,31) - 1) < rn) return 0
    return rn;
};
