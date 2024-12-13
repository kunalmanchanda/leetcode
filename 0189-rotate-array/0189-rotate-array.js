/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    let n = nums.length
    let arr = new Array(n);

    nums.forEach((ele, idx) => {
        arr[(idx + k) % n] = ele;
    });

    arr.forEach((ele, idx) => {
        nums[idx] = ele
    });
};