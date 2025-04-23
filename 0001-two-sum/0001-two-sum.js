/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const map = {}
    let res = [-1, -1];

    nums.forEach((ele, index) => {
        if (map[target - ele] != undefined) {
            res = [map[target - ele], index];
            return;
        }
        map[ele] = index;
    })

    return res;
};