/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    let mp = new Map();
    let res = false;

    nums.forEach(ele => {
        if (mp.has(ele)) {
            res = true;
        }

        mp.set(ele, true);
    })

    return res;
};