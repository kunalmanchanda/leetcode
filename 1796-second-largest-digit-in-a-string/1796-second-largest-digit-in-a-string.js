/**
 * @param {string} s
 * @return {number}
 */
var secondHighest = function(s) {
    let arr = s.split("").filter(ele => !isNaN(ele)).map(ele => +ele);

    let l = -1, sl = -1;

    for(let i = 0; i < arr.length; i++) {
        if(arr[i] > l) {
            sl = l;
            l = arr[i];
        } else if (arr[i] > sl && arr[i] != l) {
            sl = arr[i];
        }
    }

    return sl;
};