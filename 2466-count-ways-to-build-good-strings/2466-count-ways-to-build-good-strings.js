/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */

let lows, highs, zeros, ones, dp, mod = 1e9+7;

var solve = (len) => {
    if(len > highs) {
        return 0;
    }

    if(dp[len] != -1) {
        return dp[len];
    }

    let addOne = 0;
    if(len >= lows) {
        addOne = 1;
    }

    return dp[len] = (addOne + solve(len + zeros) % mod + solve(len + ones) % mod) % mod;
}

var countGoodStrings = function(low, high, zero, one) {
    lows = low, highs = high, zeros = zero, ones = one;
    dp = new Array(highs + 1).fill(-1);
    return solve(0)
};