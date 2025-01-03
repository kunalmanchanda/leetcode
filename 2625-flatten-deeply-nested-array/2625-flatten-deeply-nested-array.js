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
                res.push(...(flat(ele, n - 1)));
            } else if (index in arr) {
                res.push(ele);
            }
        })
    } else {
        arr.forEach((ele, idx) => {
            if (idx in arr) {
                res.push(ele);
            }
        })
    }

    return res;
};