/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {
    let s1 = 0, s2 = 0, res = "";

    while (word1[s1] || word2[s2]) {
        if (word1[s1]) {
            res += word1[s1++];
        }

        if (word2[s2]) {
            res += word2[s2++];
        }
    }

    return res;
};