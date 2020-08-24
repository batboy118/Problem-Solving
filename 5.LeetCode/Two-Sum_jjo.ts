function twoSum(nums: number[], target: number): number[] {
    let ans: number[] = [];
    outer: for(let i = 0; i < nums.length; i++){
        for(let j = i + 1; j < nums.length; j++){
            if(nums[i] + nums[j] == target){
                ans = [i, j];
                break outer;
            }
        }
    }
    return ans;
};
