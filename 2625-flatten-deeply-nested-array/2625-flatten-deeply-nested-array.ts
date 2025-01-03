type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    let res = []
    const Flatten = (arr, depth) => {
        for (let i = 0; i < arr.length; i++) {
            if (Array.isArray(arr[i]) && depth < n) {
                Flatten(arr[i], depth + 1)
            }
            else {
                res.push(arr[i])
            }
        }
        return res
    }
    return Flatten(arr, 0);
};