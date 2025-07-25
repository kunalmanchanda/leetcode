/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function (nums, k) {
    let max;
    let sum = 0;
    let i = 0;

    while (i < k) {
        sum += nums[i];
        i++;
    }

    max = sum;

    let j = 0;

    for (; i < nums.length; i++) {
        sum = sum + nums[i] - nums[j++];
        max = Math.max(max, sum);
    }

    return max / k;
};