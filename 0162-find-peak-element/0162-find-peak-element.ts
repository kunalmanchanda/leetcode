function findPeakElement(nums: number[]): number {
    let n = nums.length;

    for(let i = 0; i < n; i++) {
        if((i === 0 || nums[i] > nums[i-1]) && (i === n - 1 || nums[i] > nums[i + 1])) {
            return i;
        }
    }

    return n - 1;
};