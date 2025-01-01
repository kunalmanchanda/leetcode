/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    let ones = 0, zeros = 0, res = 0;

    s.split('').forEach(ele => {
        if(ele === '1') {
            ones++
        }
    });

    for(var i = 0; i < s.length - 1; i++) {
        if(s[i] == '1') {
            ones--;
        } else {
            zeros++;
        }

        res = Math.max(res, ones + zeros);
    }

    return res;
};