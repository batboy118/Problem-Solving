/**
 Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
    k = k % nums.length;
    let end_nums = nums.splice(0, nums.length - k);
    nums.push(...end_nums)
};
