/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function(boxes) {
    let n = boxes.length, arr = Array(n).fill(0), cSum = 0, cVal = 0;

    for(let i = 0; i < n; i++) {
        arr[i] += cSum;
        cVal += +boxes[i];
        cSum = cSum + cVal;
    }

    cSum = 0, cVal = 0;
    for(let i = n - 1; i >= 0; i--) {
        arr[i] += cSum;
        cVal += +boxes[i];
        cSum = cSum + cVal;
    }

    return arr;
};