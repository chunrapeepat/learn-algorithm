/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, t) {
    let l = 0;
    let r = nums.length-1;
    // find first
    let first = -1;
    while (l <= r) {
        let mid = Math.floor(l + (r - l) / 2);
        if (nums[mid] === t) {
            first = mid;
            r = mid - 1;
        } else if (nums[mid] < t) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // find last
    l = 0;
    r = nums.length-1;
    let last = -1;
    while (l <= r) {
        let mid = Math.floor(l + (r - l) / 2);
        if (nums[mid] === t) {
            last = mid;
            l = mid + 1;
        } else if (nums[mid] < t) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return [first, last]
};
