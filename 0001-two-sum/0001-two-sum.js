/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const res = [];

    const map = new Map();

    nums.forEach((ele, idx) => {
        if(map.has(target - ele)) {
            res.push(map.get(target - ele))
            res.push(idx)
            return;
        }

        map.set(ele, idx);
    })

    return res;
};