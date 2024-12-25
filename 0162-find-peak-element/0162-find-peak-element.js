/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function (arr) {
    let n = arr.length;

    if (n === 1) {
        return 0;
    }

    if (arr[0] > arr[1]) {
        return 0;
    }

    if (arr[n - 1] > arr[n - 2]) {
        return n - 1;
    }

    for (let i = 0; i < n; i++) {
        if (((i === 0) || arr[i - 1] < arr[i]) && ((i === n - 1) || arr[i + 1] < arr[i])) {
            return i;
        }
    }

    return -1;
};