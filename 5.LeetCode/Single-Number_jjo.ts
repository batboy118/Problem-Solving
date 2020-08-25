function singleNumber(nums: number[]): number {
    return nums.reduce((a,n) => a = a ^ n);
};
