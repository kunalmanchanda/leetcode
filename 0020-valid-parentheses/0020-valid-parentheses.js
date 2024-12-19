/**
 * @param {string} s
 * @return {boolean}
 */

class Stack {
    constructor() {
        this._arr = []
    }

    push(ele) {
        this._arr.push(ele);
    }

    pop() {
        return this.isEmpty() ? -1 : this._arr.pop();
    }

    size() {
        return this._arr.length;
    }

    isEmpty() {
        return this.size() === 0;
    }

    top() {
        return this.isEmpty() ? -1 : this._arr[this.size() - 1];
    }
}
var isValid = function (s) {
    let stack = new Stack();

    const obj = {
        '(': ')',
        '{': '}',
        '[': ']'
    }

    for (let i = 0; i < s.length; i++) {
        if (obj[stack.top()] === s[i]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }

    return stack.isEmpty()
};