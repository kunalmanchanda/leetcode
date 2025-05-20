/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n === 0) {
        return 1;
    }
    if(n === -1) {
        return 1/x;
    }

    let res = myPow(x, Math.floor(n/2));

    if(n % 2 === 0) {
        return res * res;
    } else {
        if(n < 0) {
            return 1/x * res * res;
        } else {
            return x * res * res;
        }
    }
};