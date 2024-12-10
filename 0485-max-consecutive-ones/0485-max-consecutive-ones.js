/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let maxi = 0, count = 0;

    nums.forEach(ele => {
        if (ele === 1) {
            count++;
        } else {
            maxi = maxi > count ? maxi : count;
            count = 0;
        }
    })

    maxi = maxi > count ? maxi : count;

    return maxi;
};