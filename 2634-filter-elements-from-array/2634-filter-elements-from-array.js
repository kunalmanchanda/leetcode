/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const res = [];

    arr.forEach((ele, i) => {
        if(i in arr && Object.hasOwn(arr, i) && fn(ele, i)) {
            res.push(ele);
        }
    })

    return res;
};