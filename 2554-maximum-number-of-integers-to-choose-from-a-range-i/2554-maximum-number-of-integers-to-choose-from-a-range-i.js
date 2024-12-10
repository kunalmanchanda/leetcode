/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function(banned, n, maxSum) {
        let set = new Set();

    banned.forEach(ele => set.add(ele));

    let count = 0;
    for(let idx = 1; idx <= n; idx++) {
        if(maxSum - idx >= 0 && !set.has(idx)) {
            maxSum -= idx;
            count++;
        }
    }


    return count;
};