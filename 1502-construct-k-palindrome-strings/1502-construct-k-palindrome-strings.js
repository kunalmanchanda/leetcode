/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function (s, k) {
    const n = s.length;

    if (n == k) return true;
    if (n < k) return false;

    const charArr = new Array(26).fill(0);

    s.split('').forEach(ele => {
        charArr[ele.charCodeAt(0) - 'a'.charCodeAt(0)]++
    })

    let oddFreq = 0;

    charArr.forEach(ele => {
        if (ele % 2 != 0) oddFreq++
    });


    if (oddFreq > k) return false;

    return true;
};