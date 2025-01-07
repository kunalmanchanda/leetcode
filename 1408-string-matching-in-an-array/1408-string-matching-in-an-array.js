/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function (words) {
    return words.filter(ele => words.some(item => item.includes(ele) && item !== ele))
};