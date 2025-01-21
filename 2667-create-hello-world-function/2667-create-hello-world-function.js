/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const greetings = "Hello World";

    return function(...args) {
        return greetings;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */