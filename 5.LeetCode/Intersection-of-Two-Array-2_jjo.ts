function intersect(nums1: number[], nums2: number[]): number[] {
    nums1.sort((a,b) => a - b);
    nums2.sort((a,b) => a - b);
    let new_arr = [];
    let i = 0;
    let j = 0;
    while(i < nums1.length && j < nums2.length){
        if(nums1[i] === nums2[j]){
            new_arr.push(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return new_arr;
};
