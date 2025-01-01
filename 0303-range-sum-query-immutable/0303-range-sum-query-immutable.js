/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    let n = nums.length;

    this._arr = new Array(n);
    this._arr[0] = nums[0];

    for(let i = 1; i < nums.length; i++) {
        this._arr[i] = this._arr[i-1] + nums[i];
    }
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function(left, right) {
    if(left === 0) {
        return this._arr[right]; 
    } else {
        return this._arr[right] - this._arr[left - 1];
    }
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */