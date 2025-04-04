/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    return nums.map(ele => Math.pow(ele, 2)).sort((a,b) => a - b);
};