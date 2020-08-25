function moveZeroes(nums: number[]): void {
    let cnt_zero = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] == 0){
            nums.splice(i, 1);
            i--;
            cnt_zero++;
        }
    }
    while(cnt_zero--) nums.push(0);
};
