/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function (arr) {
    let res = [];
    let count = 0;

    arr.forEach((ele) => {
        if (count < arr.length) {
            if (ele === 0) {
                res.push(0);
                count++;
            }
            if (count < arr.length) {
                res.push(ele);
            }
            count++;
        }
    })

    res.forEach((ele, idx) => arr[idx] = ele);
};