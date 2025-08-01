/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const hash = {};
    
    for (let i = 0; i < nums.length; i++) {
        const comp = target - nums[i]
        if (comp in hash) {
            return [hash[comp], i];
        }
        hash[nums[i]] = i;
    }
};


/*
    nums = [2,7,11,15], target = 9
    ith => 1st Iteration - hash(target - nums[i]) -> return [hash(target - nums[i]), i];
    else => hash[nums[i]] = i;

    2 : 9 - 2, hash = {} => hash.set(2, 0)
    7 : 9 - 7 : {hash.get(2), 1} : {}



*/ 