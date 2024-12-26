/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    let set = new Set();
    let res = false;

    nums.forEach(ele => {
        if (set.has(ele)) {
            res = true;
        }
        set.add(ele);
    })

    return res;
};