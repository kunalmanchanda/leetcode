/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    let first = -1, last = -1;

    nums.forEach((ele, idx) => {
        if (ele === target) {
            if (first == -1) {
                first = idx;
            }
            last = idx;
        }
    })

    return [first, last];
};