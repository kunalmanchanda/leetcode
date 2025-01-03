/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let res = [];

    if (n > 0) {
        arr.forEach((ele, index) => {
            if (Array.isArray(ele)) {
                res = [...res, ...(flat(ele, n - 1))];
            } else if (index in arr) {
                res = [...res, ele];
            }
        })
    } else {
        arr.forEach((ele, idx) => {
            if (idx in arr) {
                res = [...res, ele];
            }
        })
    }

    return res;
};