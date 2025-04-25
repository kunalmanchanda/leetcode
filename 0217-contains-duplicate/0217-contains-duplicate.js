/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    let n = nums.length;
    let res = 0;

    nums.forEach(ele => res += ele)

    return n <= 1 ? false : res < Math.ceil(n*(n+1)/2);
};