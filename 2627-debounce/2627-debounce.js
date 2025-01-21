/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId = null;
    let context = undefined;
    let args = undefined;

    return function() {
        args = arguments;
        context = this;

        if(timerId) {
            clearTimeout(timerId);
        }

        timerId = setTimeout(() => {
            fn.apply(context, args);
            clearTimeout(timerId);
            timerId = null;
        }, t)
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */