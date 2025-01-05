function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (!obj || typeof classFunction !== 'function') {
        return false;
    }

    let currPrototype = Object.getPrototypeOf(obj);

    while (currPrototype) {
        if (currPrototype === classFunction.prototype) {
            return true;
        }
        currPrototype = Object.getPrototypeOf(currPrototype)
    }

    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */