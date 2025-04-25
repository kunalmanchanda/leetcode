/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const obj = {};
    let res = false;

    nums.forEach((ele) => {
        if(obj[ele]) {
            res = true;
        }
        obj[ele] = 1;
    })

    return res;
};