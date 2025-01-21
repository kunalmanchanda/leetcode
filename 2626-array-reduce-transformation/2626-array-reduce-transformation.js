/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    let res = init;
    nums.forEach((e) => res = fn(res, e))
    return res;
};