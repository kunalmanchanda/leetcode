/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const uniqueSet = new Set();
    
    nums.forEach(item => uniqueSet.add(item));

    return nums.length != uniqueSet.size
};