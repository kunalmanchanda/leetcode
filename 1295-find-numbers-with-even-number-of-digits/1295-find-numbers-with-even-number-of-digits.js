/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
    let evenCount = 0;

    nums.forEach(ele => {
        if ((ele >= 10 && ele <= 99) || (ele >= 1000 && ele <= 9999) || ele >= 100000) {
            evenCount++;
        }
    })

    return evenCount;
};