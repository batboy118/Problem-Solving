function plusOne(digits: number[]): number[] {
    digits[digits.length - 1]++;
    for(let i = digits.length - 2; i > -1; i--){
		if(digits[i + 1] == 10){
            digits[i + 1] = 0;
			digits[i]++;
			continue;
		}
		break;
	}
	if(digits[0] == 10){
		digits[0] = 0;
		digits.unshift(1);
	}
	return digits
};
