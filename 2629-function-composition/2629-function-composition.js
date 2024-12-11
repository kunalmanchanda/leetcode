/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(fn) {
    return function(x) {
        return fn.reduceRight((acc, cf) => cf(acc), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */