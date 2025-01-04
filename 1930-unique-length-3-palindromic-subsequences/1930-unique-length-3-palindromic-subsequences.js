/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    const charset = new Set();

    for(let char of s) {
        if(!charset.has(char)) {
            charset.add(char);
        }
    }

    let res = 0;

    for(let char of charset) {
        let i = 0, j = s.length - 1;

        while(s[i] != char) i++;
        while(s[j] != char) j--;
        i++;

        const charUnique = new Set();

        for(let val = i; val < j; val++) {
            charUnique.add(s[val]);
        }

        res += charUnique.size;
    }

    return res;
};